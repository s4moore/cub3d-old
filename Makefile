NAME = cub3D

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCL_DIR = include
LIBFT_DIR = lib/libft
MLX_DIR_MACOS = lib/mlx_opengl
MLX_DIR_LINUX = lib/mlx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Sources and objects

MAIN = src/main/loop.c
INIT = src/init/init.c src/init/planets.c src/init/stars.c src/init/raycaster.c src/init/textures.c src/init/view.c
DRAW = src/draw/draw_floor.c src/draw/draw_planet.c src/draw/draw_stars.c src/draw/draw_walls.c src/draw/draw.c
MATH = src/math/rotate_planets.c src/math/rotate_stars.c src/math/raycast_walls.c src/math/raycast_floor.c
UTILS = src/utils/exit.c src/utils/various.c src/utils/key_control.c src/utils/key_utils.c
PARSER = src/parser/parse_file.c src/parser/map_validation_2.c src/parser/parse_elements.c src/parser/process_map.c src/parser/map_validation.c
SRCS = $(MAIN_FILE) $(MAIN) $(INIT) $(DRAW) $(MATH) $(UTILS) $(PARSER)
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)


# Compiler
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(INCL_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)


ifeq ($(MAKECMDGOALS),game)
MAIN_FILE = src/main/game.c
else
MAIN_FILE = src/main/main.c
endif


# Platform detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	MLX_DIR = lib/mlx_opengl
	MLX = $(MLX_DIR)/libmlx.a -framework OpenGL -framework AppKit
else
	MLX_DIR = lib/mlx-linux
	MLX = -lXext -lX11 -L/usr/lib -lm -lz -L$(MLX_DIR) -lmlx
endif


# Rules

game: all

all: $(MLX_LIB) $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@mkdir -p $(OBJ_DIR)/parser $(OBJ_DIR)/utils  $(OBJ_DIR)/main  $(OBJ_DIR)/draw  $(OBJ_DIR)/init  $(OBJ_DIR)/math
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(MLX)

$(MLX_DIR)/Makefile:
	@echo "Restoring submodule: $(MLX_DIR)"
	@git submodule deinit -f $(MLX_DIR) || true
	@git submodule update --init --recursive $(MLX_DIR)


$(MLX_LIB): $(MLX_DIR)/Makefile
	$(MAKE) -C $(MLX_DIR)


# Build object files
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) re

clean:
	make -C $(LIBFT_DIR) clean
	# @if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean; fi
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX_DIR_LINUX)/*
	rm -rf $(MLX_DIR_MACOS)/*

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	find $(MLX_DIR_LINUX) -type f ! -name '.git' -delete 2>/dev/null || true
	find $(MLX_DIR_MACOS) -type f ! -name '.git' -delete 2>/dev/null || true


re: fclean all

.PHONY: all clean fclean re