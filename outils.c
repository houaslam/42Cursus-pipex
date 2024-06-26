/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:10:00 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/12 12:46:05 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 
#include "pipex_bonus.h" 

char	*path_find(char **envp, char *cmd)
{
	char	*hld;
	char	**res;
	int		i;
	char	*str;

	i = 0;
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (!*envp)
		return (NULL);
	hld = *envp + 5;
	res = ft_split(hld, ':');
	join(res, i, cmd);
	i = 0;
	while (access(res[i], X_OK) == -1 && res[i])
			i++;
	if (res[i] == NULL)
		return (NULL);
	str = ft_strdup(res[i]);
	ft_freestr(res);
	return (str);
}

void	ft_putstr_fd(char *s, int fd, int status)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit(status);
}

void	join(char **res, int i, char *cmd)
{
	while (res[i])
	{	
		res[i] = ft_strjoin(res[i], "/");
		res[i] = ft_strjoin(res[i], cmd);
		i++;
	}
}
