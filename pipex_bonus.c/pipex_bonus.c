/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:55:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/12/24 17:20:54 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fds[a - 2][2];
	pid_t	pid;
	pid_t	pid2;

	if (ac != 5 || access(av[1], F_OK))
		ft_putstr_fd("invalid arguments", 2);
	if (pipe(fds) == -1)
		ft_putstr_fd("pipe failure", 2);
	pid = fork();
	if (pid == 0)
		first_child(fds[0], av, envp);
	pid2 = fork();
	if (pid2 == 0)
		last_child(fds, av, envp);
	if (pid < 0 || pid2 < 0)
		ft_putstr_fd("fork failure", 2);
	close(fds[0]);
	close(fds[1]);
	waitpid(pid2, NULL, 0);
	waitpid(pid, NULL, 0);
}

void	init(int ac, char **av, char **envp)
{	
	pid_t	pidn;
	int		fds[ac - 2][2];
	int		i;

	i = 2;
	while (i < ac - 2)
	{
		pipe(fds[i]);
		pidn = fork();
		if (pidn == 0)
			other_child(fds[i], av, envp, i);
		waitpid(pidn, NULL, 0);
		i++;
	}
}

void	other_child(int fd[2], char **av, char **envp, int i)
{
	char	**cmd;
	char	*path;

	if (dup2(fd[i - 1][0], 0) < 0)
		ft_putstr_fd("dup2 fail", 2);
	if (dup2(fd[i][1], 1))
		ft_putstr_fd("dup2 fail", 2);
	close(fd[i][1]);
	close(fd[i][0]);
	cmd = ft_split(av[i], ' ');
	if (av[i][0] == '/')
	{
		if (!execve(cmd[0], cmd, envp))
			exit(0);
	}
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	ft_putstr_fd("command not found\n", 2);
}

void	first_child(int fd[2], char **av, char **envp)
{
	int		in_f;
	char	**cmd;
	char	*path;

	in_f = open(av[1], O_RDONLY);
	if (dup2(in_f, 0) < 0)
		ft_putstr_fd("dup2 fail", 2);
	if (dup2(fd[1], 1) < 0)
		ft_putstr_fd("dup2 fail", 2);
	close(fd[0]);
	close(fd[1]);
	close(in_f);
	cmd = ft_split(av[2], ' ');
	if (av[2][0] == '/')
	{
		if (!execve(cmd[0], cmd, envp))
			exit(0);
	}
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	ft_putstr_fd("first command not found\n", 2);
}

void	last_child(int fd[2], char **av, char **envp)
{
	int		out_f;
	char	**cmd;
	char	*path;

	out_f = open(av[4], O_CREAT | O_RDWR, 0777);
	if (dup2(fd[0], 0) < 0)
		ft_putstr_fd("dup2 fail", 2);
	if (dup2(out_f, 1))
		ft_putstr_fd("dup2 fail", 2);
	close(fd[1]);
	close(fd[0]);
	close(out_f);
	cmd = ft_split(av[3], ' ');
	if (av[3][0] == '/')
	{
		if (!execve(cmd[0], cmd, envp))
			exit(0);
	}
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	ft_putstr_fd("second command not found\n", 2);
}