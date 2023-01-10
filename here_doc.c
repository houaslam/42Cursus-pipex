/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:19:24 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/10 15:58:22 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char **av, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
		f_child(fd, av, envp);
	else
		waitpid(pid, NULL, 0);
	pid2 = fork();
	if (pid2 == 0)
		l_child(fd, av, envp);
	else
	{
		close(fd[1]);
		waitpid(pid2, NULL, 0);
	}
	close(fd[0]);
	exit(0);
}

void	f_child(int fd[2], char **av, char **envp)
{
	char	**cmd;
	char	*path;
	int		fds[2];

	pipe(fds);
	o_child(av, fds);
	close(fd[0]);
	dup2(fds[0], 0);
	dup2(fd[1], 1);
	close(fds[1]);
	cmd = ft_split(av[3], ' ');
	if (access(av[3], X_OK) == 0)
		execve(av[3], cmd, envp);
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	ft_putstr_fd("command not found\n", 2, 127);
}

void	l_child(int fd[2], char **av, char **envp)
{
	int		out_f;
	char	**cmd;
	char	*path;

	out_f = open(av[5], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (out_f < 0)
		ft_putstr_fd("out file cannot be opened", 2, 1);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(out_f, 1);
	close(fd[0]);
	cmd = ft_split(av[4], ' ');
	if (access(av[4], X_OK) == 0)
		execve(av[4], cmd, envp);
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	ft_putstr_fd("command not found\n", 2, 127);
}

void	o_child(char **av, int fds[2])
{
	char	*res;

	while (1)
	{
		write(1, "Pipe heredoc>", 13);
		res = get_next_line(0);
		if (!res || (!ft_strncmp(av[2], res, ft_strlen(av[2])) \
		&& ft_strlen(av[2]) == ft_strlen(res) - 1))
		{
			free (res);
			break ;
		}
		write(fds[1], res, ft_strlen(res));
		free(res);
	}
}
