/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:55:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/12/16 17:49:17 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fds[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac != 5 || access(av[1], F_OK))
	{
		ft_printf("%s", strerror(22));
		exit(1);
	}
	if (pipe(fds) == -1)
		perror("pipe fail");
	pid = fork();
	if (pid == 0)
		fchild(fds, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		schild(fds, av, envp);
	close(fds[0]);
	close(fds[1]);
	waitpid(pid2, NULL, 0);
	waitpid(pid, NULL, 0);
}

char	*path_find(char **envp, char *cmd)
{
	char	*hld;
	char	**res;
	int		i;

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
	if (access(res[i], X_OK) == -1)
	{
		ft_printf("%s", "command not found");
		exit(1);
	}
	return (res[i]);
}

void	fchild(int fd[2], char **av, char **envp)
{
	int		in_f;
	char	**cmd;
	char	*path;

	in_f = open(av[1], O_RDONLY);
	if (in_f == -1)
		perror("error infile");
	cmd = ft_split(av[2], ' ');
	path = path_find(envp, cmd[0]);
	dup2(in_f, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(in_f);
	execve(path, cmd, envp);
}

void	schild(int fd[2], char **av, char **envp)
{
	int		out_f;
	char	**cmd;
	char	*path;

	out_f = open(av[4], O_CREAT | O_RDWR, 0777);
	if (out_f == -1)
		perror("error infile");
	cmd = ft_split(av[3], ' ');
	path = path_find(envp, cmd[0]);
	dup2(fd[0], 0);
	dup2(out_f, 1);
	close(fd[1]);
	close(fd[0]);
	close(out_f);
	execve(path, cmd, envp);
}
