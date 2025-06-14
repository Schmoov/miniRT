CC := cc -g3 #-fsanitize=address
CFLAGS := 

SYSLIB := -lXext -lX11 -lm
LIBFT := libft/libft.a
MLX := mlx/libmlx.a

NAME := miniRT

SRC_DIR := src/
SRC := $(shell find src -name '*.c')

OBJ_DIR := .obj/
OBJ := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MLX) -o $@ $(SYSLIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT):
	make -C libft/

$(MLX):
	make -C mlx/

clean:
	make -C libft/ clean
	make -C mlx/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

print-%  : ; @echo $* = $($*)

PHONY: all clean fclean re
