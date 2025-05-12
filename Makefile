NAME = cub3D

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCL_DIR = include
LIBFT_DIR = lib/libft
MLX_DIR_MACOS = lib/mlx_opengl
MLX_DIR_LINUX = lib/mlx-linux

ifeq ($(MAKECMDGOALS),game)
MAIN_FILE = src/game.c
NAME = game
else
MAIN_FILE = src/main.c
NAME = cub3D
endif

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Sources and objects
FLOOR = src/floor/draw_floor.c src/floor/raycast_floor.c
INIT = src/init/init.c src/init/planets.c src/init/stars.c src/init/raycaster.c src/init/textures.c src/init/view.c
INPUT = src/input/key_control.c src/input/key_utils.c
LOOPS = src/loops/draw.c src/loops/update.c
PLANETS = src/planets/draw_planet.c src/planets/rotate_planets.c
STARS = src/stars/draw_stars.c src/stars/rotate_stars.c
WALLS = src/walls/draw_walls.c src/walls/raycast_walls.c
UTILS = src/utils/exit.c src/utils/various.c
PARSER = src/parser/parse_file.c src/parser/map_validation_2.c src/parser/parse_elements.c src/parser/process_map.c src/parser/map_validation.c
SRCS = $(MAIN_FILE) $(FLOOR) $(INIT) $(INPUT) $(LOOPS) $(PLANETS) $(STARS) $(WALLS) $(PARSER) $(UTILS)
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# Compiler
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(INCL_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)

# Platform detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	MLX_DIR = lib/mlx_opengl
	MLX = $(MLX_DIR)/libmlx.a -framework OpenGL -framework AppKit
else
	MLX_DIR = lib/mlx-linux
	MLX = -lXext -lX11 -L/usr/lib -lm -lz -Llib/mlx-linux -lmlx
endif

# Build object files
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@mkdir -p $(OBJ_DIR)/parser $(OBJ_DIR)/utils
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX)

$(LIBFT):
	make -C $(LIBFT_DIR) re

$(MLX):
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re