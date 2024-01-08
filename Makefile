# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adurusoy <adurusoy@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 04:33:34 by adurusoy          #+#    #+#              #
#    Updated: 2024/01/08 16:17:50 by adurusoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_rt

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC = main.c

OBJS = $(SRC:.c=.o)

MLX = -L./minilibx -lmlx -lXext -lX11 -lm -lbsd

FT_PRNT = ./ft_printf/ftprintf.a


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(FT_PRNT) $(OBJS) $(MLX) -o $(NAME)

norm :
	norminette $(SRC) minirt.h ./ft_printf/*.c ./ft_printf/ft_printf.h

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
