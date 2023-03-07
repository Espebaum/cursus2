# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyopark < gyopark@student.42seoul.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 18:31:48 by gyopark           #+#    #+#              #
#    Updated: 2023/03/07 20:38:09 by gyopark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g # -fsanitize=thread
NAME = philo
SRCS = philo.c utils.c init.c thread.c share.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all
.PHONY: re fclean clean all
