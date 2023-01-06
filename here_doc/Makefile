# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:30:36 by houaslam          #+#    #+#              #
#    Updated: 2023/01/05 15:36:58 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRC =  split.c \
		get_next_line.c \
		outils.c \
		here_doc.c \
		libft.c 
		
all : ${NAME}

OBJ = ${SRC:.c=.o}

${LIB} : ${OBJ}
	ar -rc ${NAME} ${OBJ}

${NAME} : ${OBJ}
	cc ${OBJ} ${LIB} -o ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)

re: fclean all