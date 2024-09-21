# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalshish <yalshish@student.42amman.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 17:03:29 by yalshish          #+#    #+#              #
#    Updated: 2024/09/04 11:38:42 by yalshish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c \
		ft_strdup.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c \
		ft_strnstr.c ft_atoi.c ft_strjoin.c ft_strlcat.c \
		ft_calloc.c ft_substr.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_strtrim.c ft_split.c
OBJS = $(SRCS:.c=.o)

BONUSS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUSO = $(BONUSS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(NAME) $(OBJS)  $(BONUSO)
	ar rcs $^

clean:
	rm -f $(OBJS) $(BONUSO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re