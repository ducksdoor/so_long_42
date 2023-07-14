# --- VARIABLES ---

NAME = so_long
OBJS = $(SRCS%.c=%.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = so_long.h

SRCS = so_long.c so_long_utils.c ft_error.c ft_goodmap.c ft_img.c \
		so_long_utils_2.c ft_render.c ft_move.c


# --- RULES ---

all: $(NAME)

lib: $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $(MLX_MAC) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
	$(MAKE) re -C $(LIBFT_DIR)

.PHONY: all clean fclean re lib