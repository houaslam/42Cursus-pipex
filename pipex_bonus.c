/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:08:50 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/12 12:51:43 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h" 

int	main(int ac, char **av, char **envp)
{
	int	sv[2];
	int	i;

	i = 1;
	if (ac >= 5)
	{
		if (ac == 6 && ft_strncmp(av[1], "here_doc", 8) == 0 \
			&& ft_strlen(av[1]) == ft_strlen("here_doc"))
		{
			here_doc(av, envp);
			exit(0);
		}
		else
		{
			sv[0] = open(av[1], O_RDWR, 0777);
			if (sv[0] < 0)
				ft_putstr_fd("no such file or directory\n", 2, 1);
			cmd_exec(sv, ac, av, envp);
			close(sv[0]);
			while (wait(NULL) != -1)
				;
		}
	}
	else
		ft_putstr_fd("arguments are not valid", 2, 1);
}

void	cmd_exec(int sv[2], int ac, char **av, char **envp)
{
	int	fd[2];
	int	i;

	sv[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (sv[1] < 0)
		ft_putstr_fd("out file couldn t be opened\n", 2, 1);
	i = 2;
	while (i <= ac - 2)
	{
		pipe(fd);
		if (fork() == 0)
		{
			cmd_exec2(sv, i, fd);
			if (i == ac -2)
				dup2(sv[1], 1);
			close(fd[1]);
			close (sv[1]);
			exec(i, av, envp);
		}
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		i++;
	}
	close(sv[1]);
}

void	cmd_exec2(int sv[2], int i, int fd[2])
{
	if (i == 2)
	{
		if (dup2(sv[0], 0) == -1)
			ft_putstr_fd("dup Error", 2, 1);
	}	
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		ft_putstr_fd("dup Error", 2, 1);
	close(sv[0]);
}

void	exec(int i, char **av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av[i], ' ');
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	if (access(av[i], X_OK) == 0)
	{
		if (execve(av[i], cmd, envp) == -1)
			ft_putstr_fd("command not found\n", 2, 127);
	}
	ft_putstr_fd("command not found\n", 2, 127);
}
