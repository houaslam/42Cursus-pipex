/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:19:51 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/06 13:37:07 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<errno.h>
# include<fcntl.h> 
# include<string.h> 
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

// split
int		ft_dim1(char *s, char c);
char	**ft_func(char **arr, char *s, char c);
char	**ft_split(char *s, char c);
char	**ft_freestr(char **arr);

// libft
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

// pipex
void	o_child(char **av, int fds[2]);
void	l_child(int fd[2], char **av, char **envp);
void	f_child(int fd[2], char **av, char **envp);
void	last_child(int fd[2], char **av, char **envp);
char	*path_find(char **envp, char *cmd);
void	first_child(int fd[2], char **av, char **envp);
void	ft_putstr_fd(char *s, int fd);

//pipex bonus

void	cmd_exec(int sv[2], int ac, char **av, char **envp);
void	exec(int i, char **av, char **envp);
void	cmd_exec2(int sv[2], char **av, char **envp, int ac);
#endif