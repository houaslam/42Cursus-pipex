/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:43:34 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/12 12:52:59 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

int		ft_dim1(char *s, char c);
char	**ft_func(char **arr, char *s, char c);
char	**ft_split(char *s, char c);
char	**ft_freestr(char **arr);

char	*path_find(char **envp, char *cmd);
void	cmd_exec(int sv[2], int ac, char **av, char **envp);
void	exec(int i, char **av, char **envp);
void	cmd_exec2(int sv[2], int i, int fd[2]);

char	*after(char *buf);
char	*ft_handle(char *buf);
char	*ft_check(char *str, int fd);
char	*get_next_line(int fd);

void	o_child(char **av, int fds[2]);
void	l_child(int fd[2], char **av, char **envp);
void	f_child(int fd[2], char **av, char **envp);
void	here_doc(char **av, char **envp);

size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

void	ft_putstr_fd(char *s, int fd, int status);
void	join(char **res, int i, char *cmd);

#endif