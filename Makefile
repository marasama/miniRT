# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 04:33:34 by adurusoy          #+#    #+#              #
#    Updated: 2024/03/04 18:15:28 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_rt

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = main.c

OBJS = $(SRC:.c=.o)

MLX = -L./minilibx -lmlx -lXext -lX11 -lm -lbsd

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(FT_PRNT) $(OBJS) $(MLX) -o $(NAME)

norm :
	norminette $(SRC) minirt.h ./libft/

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
