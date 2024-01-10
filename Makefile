# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ax <ax@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:56:47 by ax                #+#    #+#              #
#    Updated: 2024/01/07 19:47:59 by ax               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = cc
# CFLAGS = -Wall -Werror -Wextra -g3
CFLAGS = -g3
LIBFT_DIR =	./libft
LIBFT =	$(LIBFT_DIR)/libft.a
AR = ar rcs
SRC = libftprintf.c ./utils/libftprintf_utils.c ./utils/libftprintf_uint.c ./utils/libftprintf_hexadecimal.c
SRCS = $(SRC)
OBJS = $(SRCS:.c=.o)
EXECUTABLE = a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $@ $^

$(EXECUTABLE): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@cd $(LIBFT_DIR) && make

all: $(NAME) $(EXECUTABLE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
