# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 04:33:34 by adurusoy          #+#    #+#              #
#    Updated: 2024/04/26 21:35:23 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC = \
		./srcs/utils/utils.c \
		./srcs/utils/utils2.c \
		./srcs/utils/utils3.c \
		\
		./srcs/utils/color_funcs.c \
		./srcs/utils/color_funcs2.c \
		\
		./srcs/print_objects/print_objects.c \
		./srcs/print_objects/print_objects2.c \
		\
		./srcs/input_funcs/take_input3.c \
		./srcs/input_funcs/take_input2.c \
		./srcs/input_funcs/take_input.c \
		\
		./srcs/render/create_image.c \
		./srcs/render/sp_pl_intersection.c \
		./srcs/render/cy_intersection.c \
		./srcs/render/check_intersection.c \
		\
		./srcs/vector_funcs/vector_funcs.c \
		./srcs/vector_funcs/vector_funcs2.c \
		./srcs/vector_funcs/vector_funcs3.c \
		\
		./srcs/main.c \


OBJS = $(SRC:.c=.o)

MLX = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\e[33mCompiling...\e[0m"
	@make -s -C ./mlx > /dev/null 2>&1
	@cp mlx/libmlx.a .
	@printf "\e[33mMLX: \t\t\t\t\e[35mDONE \e[0m\n"	
	@make -s -C ./libft
	@cp libft/libft.a .
	@printf "\e[33mLIBFT: \t\t\t\t\e[35mDONE \e[0m\n"
	@$(CC) $(OBJS) $(CFLAGS) libft.a libmlx.a $(MLX) -o $(NAME)
	@printf "\e[33mHumble RayTracing Engine: \t\e[35mDONE\e[0m\n"

norm :
	@norminette $(SRC) minirt.h ./libft/
	@printf "\e[33mNorminette: \e[35mYOUR CODE SUITS NORM's TASTE!!! \e[0m\n"

clean :
	@make -s -C ./mlx clean
	@make -s -C ./libft fclean
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf libmlx.a
	@rm -rf libft.a
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
