# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 16:30:36 by houaslam          #+#    #+#              #
#    Updated: 2023/01/12 12:48:38 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus

CFLAGS = -Wall -Wextra -Werror

SRCS =  split.c \
		outils.c \
		pipex.c \
		libft.c 

SRC =  split.c \
		outils.c \
		pipex_bonus.c \
		libft.c \
		here_doc.c \
		get_next_line.c 

OBJ = ${SRCS:.c=.o}
OB = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	cc $(CFLAGS) ${OBJ} -o ${NAME}

bonus : $(BONUS)

$(BONUS) : $(OB)
	 cc $(CFLAGS) ${OB} -o $(BONUS)


clean :
	rm -f ${OBJ}
	rm -f ${OB}

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all