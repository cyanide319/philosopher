# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 12:50:02 by tbeaudoi          #+#    #+#              #
#    Updated: 2022/12/08 17:17:41 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -pthread
RM = rm -f

SRCS =  src/philo.c \
		src/utils.c \
		src/parsing.c \
		src/init.c \
		src/routine.c \
		src/routine_utils.c \
			 
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all