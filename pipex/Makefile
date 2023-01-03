# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 18:01:50 by houaslam          #+#    #+#              #
#    Updated: 2023/01/03 11:44:45 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_split.c \
		outils.c \
		pipex.c

BSRC =  ft_split.c \
		outils.c \
		pipex_bonus.c
		
all : ${NAME}

OBJ = ${SRCS:.c=.o}

${LIB} : ${OBJ}
	ar -rc ${NAME} ${OBJ}

${NAME} : ${OBJ}
	cc ${OBJ} ${LIB} -o ${NAME}
	
clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)

re: fclean all