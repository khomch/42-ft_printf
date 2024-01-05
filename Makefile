# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ax <ax@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:56:47 by ax                #+#    #+#              #
#    Updated: 2024/01/04 17:44:00 by ax               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LIBFT = ./libft/libft.a
AR = ar rcs
SRC = libftprintf.c
SRCS = $(SRC)
OBJS = $(SRCS:.c=.o)
EXECUTABLE = a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $@ $^

$(EXECUTABLE): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME) $(EXECUTABLE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
