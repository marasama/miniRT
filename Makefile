# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 04:33:34 by adurusoy          #+#    #+#              #
#    Updated: 2024/03/30 18:59:15 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

FLAGS = -Wall -Werror -Wextra -g

INCFLAGS = -I minishell.h -I ./libft/libft.h

CC = gcc

SRC = ./srcs/check_funcs/check_funcs.c \
		./srcs/utils/utils.c \
		./srcs/utils/utils2.c \
		./srcs/print_objects/print_objects.c \
		./srcs/print_objects/print_objects2.c \
		./srcs/input_funcs/take_input2.c \
		./srcs/input_funcs/take_input.c \
		./srcs/render/create_image.c \
		./srcs/render/sphere_intersection.c \
		./srcs/render/check_intersection.c \
		./srcs/vector_funcs/vector_funcs.c \
		./srcs/vector_funcs/vector_funcs2.c \
		./srcs/vector_funcs/vector_funcs3.c \
		./srcs/main.c

OBJS = $(SRC:.c=.o)

MLX = -L./minilibx -lmlx -lXext -lX11 -lm -lbsd

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\e[33mCompiling...\e[0m"
	@make -s -C ./libft
	@cp libft/libft.a .
	@printf "\e[33mLIBFT: \t\t\t\t\e[35mDONE \e[0m\n"
	@$(CC) $(FLAGS) $(FT_PRNT) $(OBJS) libft.a $(MLX) -o $(NAME) $(INCFLAGS)
	@printf "\e[33mHumble RayTracing Engine: \t\e[35mDONE\e[0m\n"

norm :
	@norminette $(SRC) minirt.h ./libft/
	@printf "\e[33mNorminette: \e[35mYOUR CODE SUITS NORM's TASTE!!! \e[0m\n"

clean :
	@make -s -C ./libft fclean
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf libft.a
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
