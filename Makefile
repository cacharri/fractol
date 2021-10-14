# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 17:55:22 by ialvarez          #+#    #+#              #
#    Updated: 2021/10/14 20:25:02 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LINK = -lmlx -lmlx -framework OpenGL -framework AppKit
NAME = fractol

SRCS = 	fractol.c

OBJECTS = $(SRCS:.c=.o)
LIBFT_DIR = libft/
LIB_NAME = $(LIBFT_DIR)libft.a
INCLUDES = -I. -I$(LIB_PATH)
FSANITIZE = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LINK) $^ -L ./libft/ -l ft -o $(NAME)

debug: $(OBJECTS)
	@make -s -C $(LIBFT_DIR) 
	@$(CC) $(CFLAGS) $(LINK) $(FSANITIZE) $^ -L ./libft/ -l ft -o $(NAME)
	
clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJECTS)

normi:
	norminette $(SRCS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY:
			clean
			fclean
			all
			re
			bonus
