/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:08:50 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/06 22:20:02 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

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
			here_doc(ac, av, envp);
			exit(0);
		}
		else
		{
			cmd_exec(sv, ac, av, envp);
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
	int	out;

	out = open(av[ac -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	i = 2;
	sv[0] = open(av[1], O_RDWR, 0777);
	while (i <= ac - 2)
	{
		pipe(fd);
		if (fork() == 0)
		{
			cmd_exec2(sv, i, fd);
			if (i == ac -2)
				dup2(out, 1);
			close(fd[1]);
			close (out);
			exec(i, av, envp);
		}
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		i++;
	}
}

void	cmd_exec2(int sv[2], int i, int fd[2])
{
	if (i == 2)
	{
		if (sv[0] < 0)
			ft_putstr_fd("no such file or directory\n", 2, 1);
		dup2(sv[0], 0);
	}
	close(fd[0]);
	dup2(fd[1], 1);
	close(sv[0]);
}

void	exec(int i, char **av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av[i], ' ');
	if (av[i][0] == '/' || av[i][0] == '0')
	{
		if (execve(cmd[0], cmd, envp) == -1)
			ft_putstr_fd("command not found\n", 2, 127);
	}
	path = path_find(envp, cmd[0]);
	execve(path, cmd, envp);
	ft_putstr_fd("command not found\n", 2, 127);
}
