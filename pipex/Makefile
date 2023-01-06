# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:30:36 by houaslam          #+#    #+#              #
#    Updated: 2023/01/06 22:14:28 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS =  split.c \
		outils.c \
		pipex.c \
		libft.c 

SRC =  split.c \
		outils.c \
		multi_pipe.c \
		libft.c \
		here_doc.c \
		get_next_line.c 

all : ${NAME}

OBJ = ${SRCS:.c=.o}
OB = ${SRC:.c=.o}

${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}

bonus : $(OB)
	cc $(CFLAGS) ${OB} -o ${NAME}

clean :
	rm -f ${OBJ}
	rm -f ${OB}

fclean : clean
	rm -f $(NAME)

re: fclean all