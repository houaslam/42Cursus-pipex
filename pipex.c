/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:08:50 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/10 13:26:23 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fds[2];
	int		pid;
	int		pid2;

	if (ac != 5)
		ft_putstr_fd("invalid arguments", 2, 1);
	pipe(fds);
	pid = fork();
	if (pid == 0)
		first_child(fds, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		last_child(fds, av, envp);
	if (pid < 0 || pid2 < 0)
		ft_putstr_fd("fork: Resource temporarily unavailable", 2, 1);
	close(fds[0]);
	close(fds[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	first_child(int fd[2], char **av, char **envp)
{
	int		in_f;
	char	**cmd;
	char	*path;

	in_f = open(av[1], O_RDONLY);
	if (in_f < 0)
		ft_putstr_fd("no such file or directory\n", 2, 1);
	if (dup2(in_f, 0) == -1)
		ft_putstr_fd("dup2 fail", 2, 1);
	if (dup2(fd[1], 1) == -1)
		ft_putstr_fd("dup2 fail", 2, 1);
	close(fd[0]);
	close(fd[1]);
	close(in_f);
	cmd = ft_split(av[2], ' ');
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	if (access(av[2], X_OK) == 0)
	{
		if (execve(av[2], cmd, envp) == -1)
			ft_putstr_fd("command not found\n", 2, 127);
	}
	ft_putstr_fd("command not found\n", 2, 127);
}

void	last_child(int fd[2], char **av, char **envp)
{
	int		out_f;
	char	**cmd;
	char	*path;

	out_f = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out_f < 0)
		ft_putstr_fd("out file couldn' t be opened\n", 2, 1);
	if (dup2(fd[0], 0) == -1)
		ft_putstr_fd("dup2 fail", 2, 1);
	if (dup2(out_f, 1) == -1)
		ft_putstr_fd("dup2 fail", 2, 1);
	close(fd[1]);
	close(fd[0]);
	close(out_f);
	cmd = ft_split(av[3], ' ');
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	if (access(av[3], X_OK) == 0)
	{
		if (execve(av[3], cmd, envp) == -1)
			ft_putstr_fd("command not found\n", 2, 127);
	}
	ft_putstr_fd("command not found\n", 2, 127);
}
