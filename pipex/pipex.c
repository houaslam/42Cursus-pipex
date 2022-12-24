/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:55:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/12/23 13:01:56 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fds[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac != 5 || access(av[1], F_OK))
		ft_putstr_fd("invalid arguments", 2);
	if (pipe(fds) == -1)
		ft_putstr_fd("pipe failure", 2);
	pid = fork();
	if (pid == 0)
		first_child(fds, av, envp);
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

void	first_child(int fd[2], char **av, char **envp)
{
	int		in_f;
	char	**cmd;
	char	*path;

	in_f = open(av[1], O_RDONLY);
	if (dup2(in_f, 0) < 0)
		ft_putstr_fd("dup2 fail");
	if (dup2(fd[1], 1) < 0)
		ft_putstr_fd("dup2 fail");
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
		ft_putstr_fd("dup2 fail");
	if (dup2(out_f, 1))
		ft_putstr_fd("dup2 fail");
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

void	ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	*path_find(char **envp, char *cmd)
{
	char	*hld;
	char	**res;
	int		i;
	char	*str;

	i = 0;
	while (strncmp(*envp, "PATH", 4))
		envp++;
	hld = *envp + 5;
	res = ft_split(hld, ':');
	while (res[i])
	{	
		res[i] = ft_strjoin(res[i], "/");
		res[i] = ft_strjoin(res[i], cmd);
		i++;
	}
	i = 0;
	while (access(res[i], X_OK) == -1 && res[i])
			i++;
	if (res[i] == NULL)
		return (NULL);
	str = ft_strdup(res[i]);
	ft_free(res);
	return (str);
}
