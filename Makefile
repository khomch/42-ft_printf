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


# Colors

DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Actions

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g
RM				=	rm -rf
AR				=	ar rcs

# Variables

INCLUDE_DIR		=	./include
OBJ_DIR			=	./obj
PRINTF_DIR		=	./ft_printf
LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

# Sources

NAME				=	libftprintf.a
FT_PRINTF_SRC_FILES	=	ft_printf.c					\
						ft_printf_hexadecimal.c		\
						ft_printf_pointer.c			\
						ft_printf_uint.c		\
						ft_printf_utils.c
OBJS				=	$(FT_PRINTF_SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Comands

all:				$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
					@cp $(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)
					@echo "$(GREEN)FT_PRINTF compiled$(DEF_COLOR)"

$(LIBFT):
					@echo "$(YELLOW)LIBFT compilation process"
					@cd $(LIBFT_DIR) && make && echo "$(GREEN)LIBFT compiled$(DEF_COLOR)"

$(OBJ_DIR):
					@echo "$(YELLOW)FT_PRINTF compilation process"
					@mkdir -pv $(OBJ_DIR)

$(OBJ_DIR)/%.o:		$(PRINTF_DIR)/%.c
					$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

clean:
					@$(RM) -rf $(OBJ_DIR)
					@cd $(LIBFT_DIR) && make clean
					@echo "$(RED)FT_PRINTF object files cleaned!$(DEF_COLOR)"

fclean:				clean
					@$(RM) -f $(NAME)
					@$(RM) -f $(LIBFT)
					@echo "$(RED)FT_PRINTF executable files cleaned!$(DEF_COLOR)"
					@echo "$(RED)LIBFT executable files cleaned!$(DEF_COLOR)"

re:					fclean all
	@echo "$(CYAN)cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY:				all clean fclean re

# NAME = libftprintf.a
# CC = cc
# CFLAGS = -Wall -Werror -Wextra -g3
# LIBFT_DIR =	./libft
# LIBFT =	$(LIBFT_DIR)/libft.a
# AR = ar rcs
# SRC = ft_printf.c ./utils/ft_printf_utils.c ./utils/ft_printf_uint.c ./utils/ft_printf_hexadecimal.c ./utils/ft_printf_pointer.c
# SRCS = $(SRC)
# OBJS = $(SRCS:.c=.o)
# EXECUTABLE = a.out

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJS) $(LIBFT)
# 	$(AR) $@ $^

# $(EXECUTABLE): $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $^ -o $@

# $(LIBFT):
# 	@cd $(LIBFT_DIR) && make

# all: $(NAME) $(EXECUTABLE)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME) $(EXECUTABLE)

# re: fclean all

# .PHONY: all clean fclean re
