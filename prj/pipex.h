/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:50:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/12/16 15:05:55 by houaslam         ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

char	*path_find(char **envp, char *cmd);
void	fchild(int fd[2], char **av, char **envp);
void	schild(int fd[2], char **av, char **envp);

#endif