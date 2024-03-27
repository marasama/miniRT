# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 04:33:34 by adurusoy          #+#    #+#              #
#    Updated: 2024/03/25 20:16:44 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_rt

FLAGS = -Wall -Werror -Wextra -g

INCFLAGS = -I minishell.h -I ./libft/libft.h

CC = gcc

UTILS = ./utils/check_funcs.c \
		./utils/utils.c \
		./utils/print_objects.c \
		./utils/take_input.c \
		./utils/take_input2.c \
		./utils/print_objects2.c \
		./utils/check_intersection.c \
		./utils/vector_funcs.c

SRC = main.c $(UTILS) create_image.c

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
