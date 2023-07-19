NAME = so_long
CC = cc
CCFLAGS = -Wall -Wextra -Werror
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS = so_long.c so_long_utils.c ft_error.c ft_goodmap.c ft_img.c \
		so_long_utils_2.c ft_render.c ft_move.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

lib: $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(MLX_MAC) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re lib
