/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:08:50 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/06 15:58:08 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	sv[2];
	int	id2;
	int	i;

	i = 1;
	if (ac >= 6)
	{
		cmd_exec(sv, ac, av, envp);
		id2 = fork();
		if (id2 == 0)
			cmd_exec2(sv, av, envp, ac);
		wait(NULL);
	}
	else
		ft_putstr_fd("arguments are not valid", 2);
}

void	cmd_exec(int sv[2], int ac, char **av, char **envp)
{
	int	fd[2];
	int	i;

	i = 2;
	sv[0] = open(av[1], O_RDWR, 0777);
	while (i < ac - 2)
	{
		pipe(fd);
		if (fork() == 0)
		{
			if (dup2(sv[0], 0) == -1)
				ft_putstr_fd("dup2 fail 1\n", 2);
			close(fd[0]);
			if (dup2(fd[1], 1) == -1)
				ft_putstr_fd("dup2 fail 2\n", 2);
			close(fd[1]);
			exec(i, av, envp);
		}
		close(fd[1]);
		sv[0] = dup(fd[0]);
		close(fd[0]);
		i++;
	}
}

void	cmd_exec2(int sv[2], char **av, char **envp, int ac)
{
	int		out_f;
	char	**cmd;
	char	*path;

	out_f = open(av[ac -1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (dup2(sv[0], 0) == -1)
		ft_putstr_fd("dup2 fail 3\n", 2);
	close(sv[0]);
	if (dup2(out_f, 1) == -1)
		ft_putstr_fd("dup2 fail 4\n", 2);
	exec(ac - 2, av, envp);
}

void	exec(int i, char **av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av[i], ' ');
	if (av[i][0] == '/' || av[i][0] == '0')
	{
		if (!execve(cmd[0], cmd, envp))
			exit(0);
	}
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	ft_putstr_fd("command not found\n", 2);
}
