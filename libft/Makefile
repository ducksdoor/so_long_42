# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 15:12:23 by lortega-          #+#    #+#              #
#    Updated: 2023/04/07 12:35:43 by lortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(INCLUDE) 
RM = rm -f
AR = ar rcs
INCLUDE = libft.h

SRCS =	ft_strlen.c ft_bzero.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_get_next_line.c ft_gnl_substr.c ft_gnl_strchr.c\
		ft_positivenumber.c ft_printf.c ft_ptr.c\
		ft_putnbr_hx.c ft_putchar.c ft_len_positivenumber.c\
		ft_putstr.c ft_putnbr.c ft_len_nbr.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCSBONUS:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) $(OBJS)
	@$(AR) $(NAME) $(OBJS_BONUS) $(OBJS)

clean:
	@$(RM) $(OBJS_BONUS) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all bonus 

.PHONY: re all bonus clean fclean
