# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 08:09:21 by aahizi-e          #+#    #+#              #
#    Updated: 2020/01/30 14:28:31 by aahizi-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aahizi-e.filler

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	main.c\
		map.c\
		fill.c\
		points.c\

LIBFT =	libft/libft.a\

OBJS = $(SRCS:.c=.o)

all: libft $(NAME) 

libft:
	@$(MAKE) -C libft/

$(NAME): $(LIBFT) $(OBJS) filler.h
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $@

clean:
	@$(MAKE) clean -C libft/
	@rm -f $(OBJS)


fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
