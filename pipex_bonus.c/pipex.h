/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:50:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/12/23 20:24:25 by houaslam         ###   ########.fr       */
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
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	*path_find(char **envp, char *cmd);
void	first_child(int fd[2], char **av, char **envp);
void	last_child(int fd[2], char **av, char **envp);
char	**ft_freestr(char **arr, int p);
void	ft_putstr_fd(char *s, int fd);
void	ft_free(char **res);
void	ft_close(int **fd[], int i, int ac);
void	other_child(int fd[2], char **av, char **envp, int i);

#endif