# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:30:36 by houaslam          #+#    #+#              #
#    Updated: 2023/01/06 15:47:17 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS =  split.c \
		outils.c \
		multi_pipe.c \
		libft.c 

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