# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 04:33:34 by adurusoy          #+#    #+#              #
#    Updated: 2024/03/04 18:44:43 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_rt

FLAGS = -Wall -Werror -Wextra -g

INCFLAGS = -I minishell.h -I ./libft/libft.h

CC = gcc

SRC = main.c

OBJS = $(SRC:.c=.o)

MLX = -L./minilibx -lmlx -lXext -lX11 -lm -lbsd

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling..."
	@make -C ./libft
	@cp libft/libft.a .
	@printf "\e[33mLIBFT: \t\t\t\t\e[35mDONE \e[0m\n"
	@$(CC) $(FLAGS) $(FT_PRNT) $(OBJS) libft.a $(MLX) -o $(NAME) $(INCFLAGS)
	@printf "\e[33mHumble RayTracing Engine: \t\e[35mDONE\e[0m\n"

norm :
	norminette $(SRC) minirt.h ./libft/

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
