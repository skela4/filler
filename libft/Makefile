# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 08:09:21 by aahizi-e          #+#    #+#              #
#    Updated: 2020/01/28 08:21:41 by aahizi-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
		ft_strlen.c ft_strnlen.c\
		ft_strdup.c ft_strndup.c\
		ft_strcpy.c ft_strncpy.c\
		ft_strcat.c ft_strncat.c ft_strlcat.c\
		ft_strchr.c ft_strrchr.c\
		ft_strstr.c ft_strnstr.c\
		ft_strcmp.c ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c ft_isblank.c ft_iscntrl.c ft_isgraph.c\
		ft_isnumber.c ft_ispunct.c ft_isspace.c ft_isupper.c ft_islower.c ft_isxdigit.c\
		ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c ft_str_is_printable.c\
		ft_str_is_uppercase.c ft_strcapitalize.c ft_strcasecmp.c ft_strncasecmp.c ft_strlowcase.c ft_strupcase.c\
		ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_memalloc.c ft_memdel.c\
		ft_strnew.c ft_strdel.c ft_strclr.c\
		ft_striter.c ft_striteri.c\
		ft_strmap.c ft_strmapi.c\
		ft_strequ.c ft_strnequ.c\
		ft_nbrlen.c\
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
		ft_printlst.c\
		ft_lstnew.c ft_lstnew_ptr.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
		ft_lstadd_after.c ft_lstadd_end.c ft_lstdelete.c ft_lst_size.c\
		get_next_line.c\
		ft_lstadd_end_new.c\
		ft_read_fd.c\
		ft_jump_line.c\
		ft_delete_line.c\




OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft.h
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $@ $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re