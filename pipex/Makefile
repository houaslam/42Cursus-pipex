# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 18:01:50 by houaslam          #+#    #+#              #
#    Updated: 2022/12/23 18:09:12 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_split.c \
		outils.c \
		pipex.c

B_SRCS =  pipex_bonus.c	
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