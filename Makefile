CC := cc
CFLAGS := -Wall -Wextra -Werror

SYSLIB := -lXext -lX11 -lm
LIBFT := libft/libft.a
MLX := mlx/libmlx.a

NAME := miniRT

SRC_DIR := src/
SRC := src/display/display.c src/display/display_utils.c src/main.c src/math_utils/color.c src/math_utils/quadratic.c src/math_utils/vector1.c src/math_utils/vector2.c src/model/add_color1.c src/model/add_color2.c src/model/api1.c src/model/api2.c src/model/api3.c src/model/bump1.c src/model/bump2.c src/model/impact.c src/model/impact_color1.c src/model/impact_color2.c src/model/impact_object1.c src/model/impact_object2.c src/model/light.c src/model/model.c src/model/object_axis.c src/model/screen.c src/parser/ambient_lighting.c src/parser/bumpmap/heightmap.c src/parser/bumpmap/heightmap_utils.c src/parser/camera.c src/parser/damier/damier.c src/parser/error_handler.c src/parser/light.c src/parser/objects/cone.c src/parser/objects/cylinder.c src/parser/objects/plane.c src/parser/objects/sphere.c src/parser/parser.c src/parser/parser_free.c src/parser/parser_utils.c src/parser/parse_utils2.c

OBJ_DIR := .obj/
OBJ := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

bonus: all

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

PHONY: all clean fclean re bonus
