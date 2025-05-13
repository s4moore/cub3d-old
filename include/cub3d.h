/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:55:24 by samoore           #+#    #+#             */
/*   Updated: 2025/05/13 11:57:24 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
// # include "main.h"
# include <X11/keysym.h> //keysym
# include <sys/time.h>

# define TEXTURE_SIZE 1024
# define NUM_TEXTURES 5
# define NUM_STARS 30000
# define NUM_PLANETS 1
# define STAR_SPHERE_RADIUS 1000.0
# define MAP_W 24
# define MAP_H 24
# define LEFT -1
# define RIGHT 1
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define SCREEN_W 1800
# define SCREEN_H 1080

typedef unsigned int	uint_32;
extern int				g_world_map[MAP_W][MAP_H];

typedef struct s_xyz {
    double x;
    double y;
    double z;
} t_xyz;

typedef struct s_xy_dbl
{
	double	x;
	double	y;
}	t_xy_dbl;

typedef struct s_xy_int
{
	int	x;
	int	y;
}	t_xy_int;

typedef struct s_draw_props
{
	t_xy_dbl	ray_dir;
	t_xy_dbl	delta;
	t_xy_dbl	ray_dist;
	t_xy_int	step;
	t_xy_int	tex;
	t_xy_dbl	floor_start;
	double		wall_x;
	double		wall_dist;
	int			side;
	int			tex_num;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		tex_step;
	double		tex_offset;
	double		col;
}	t_draw_props;


typedef struct s_planet{
	uint_32		*img;
	uint_32		*addr;
	int			w;
	int			h;
	t_xyz		pos;
	t_xy_int	screen;
	double		orbit_radius;
	double		orbit_height;
	double		orbit_angle;
}	t_planet;

#ifdef __APPLE__
    #define MLX_MACOS
    #include <mlx.h>
#elif defined(__linux__)
    #define MLX_LINUX
    #include <mlx.h>
#endif

# define WIN_WIDTH 800
# define WIN_HEIGHT 600


#ifdef MLX_MACOS
    // macOS keycodes
    #define KEY_W 13
    #define KEY_A 0
    #define KEY_S 1
    #define KEY_D 2
    #define KEY_ESC 53
#else
    // Linux keycodes
    #define KEY_W 119
    #define KEY_A 97
    #define KEY_S 115
    #define KEY_D 100
    #define KEY_ESC 65307
#endif

# define TEX_NORTH 0
# define TEX_SOUTH 1
# define TEX_WEST 2
# define TEX_EAST 3

typedef struct s_map_parser {
    char    **lines;
    int     row_count;
    int     map_start;
	int     capacity;
} t_map_parser;

typedef struct s_visited {
    int     **array;
    int     height;
    int     width;
} t_visited;

typedef struct s_rgb_parser {
    char    **parts;
    char    *r_str;
    char    *g_str;
    char    *b_str;
} t_rgb_parser;

typedef struct s_color {
	int r;
	int g;
	int b;
} t_color;

typedef struct s_texture {
	char *path;
	uint_32 *img;
	uint_32 *addr;
	int width;
	int height;
	int bpp;
	int line_len;
	int endian;
} t_texture;

typedef struct s_map {
	char **grid;
	int width;
	int height;
} t_map;

typedef struct s_player {
	double x;
	double y;
	double dir_x;
	double dir_y;
} t_player;

typedef struct s_star {
    double	x;
    double	y;
    double	z;
    double	size;
	double	screen_x;
	double	screen_y;
    int		color;
	int		twinkle;
	int		timer;
	int		twinkle_color;
} t_star;

typedef struct s_game {
	void *mlx;
	void *win;
	t_texture tex[5];
	t_color floor;
	t_color ceiling;
	t_map map;
	t_player player;

	t_draw_props	*props;
	t_star			*stars;
	t_xyz			dir;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			move_speed;
	double			rot_speed;
	double			yaw;
	double			pitch;
	int				map_x;
	int				map_y;
	double			planet_angle;
	t_planet		planets[3];
	int 			keys[65536];

} t_game;


void	set_star_colour(t_game *game, int i);
void	create_stars(t_game *game);
void	put_planet_in_3d(t_game *game);
void	load_planets(t_game *game);
t_game	*init(void);
void	exit_program(t_game *game);
static inline int	pixel_pos(int x, int y, int size_line, int bpp);
void	put_pixel(t_game *game, int x, int y, int color);
unsigned int	get_ticks(void);
void	set_view_direction(t_game *game, char direction);
void	load_textures(t_game *game);
void	ray_caster_init(t_game *game);
void	calculate_gridline_distance(t_game *game, t_draw_props *props);
void	get_floor_start_position(t_game *game);
void	calculate_wall_distance(t_game *game, t_draw_props *props);
void	select_texture_by_wall_direction(t_draw_props *props);
void	calcualte_slice_properties(t_game *game);
void	calcualte_texture_properties(t_draw_props *props);
void	draw_walls(t_game *game, int x);
void	calculate_initial_props(t_game *game, int x);
void	draw_floor(t_game *game, t_draw_props *props, int x);
void	update_speed(t_game *game);
void	draw_star(t_game *game, t_star s, int color);
void	put_image(t_game *game);
void	draw_stars(t_game *game);
double	get_player_rotation_angle(t_game *game);
int	draw(t_game *game);
int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_game *game);
void	check_up_down_arrows(t_game *game);
void	check_strafe(t_game *game);
void	rotate_stars(t_game *game, t_star *stars, int direction);
void	rotate_planets(t_game *game, int direction);
void	check_left_arrow(t_game *game);
void	check_right_arrow(t_game *game);
int	main_loop(t_game *game);

void parse_file_content(int fd, t_game *game, t_map_parser *map_parser);
void parse_line(char *line, t_game *game, t_map_parser *map_parser);
void check_elements(t_game *game);
int parse_file(const char *path, t_game *game);
void init_map_parser(t_map_parser *map_parser);
void add_map_line(t_map_parser *map_parser, char *line);

void process_map(t_game *game, t_map_parser *map_parser);
int find_max_width(t_map_parser *map_parser);
void fill_map_grid(t_game *game, t_map_parser *map_parser, int max_width);
void allocate_map_grid(t_game *game);

void validate_map(t_game *game);
void validate_character(char c, int *player_count);
void validate_player_count(int player_count);
int is_player_position(t_game *game, int y, int x);
void set_player_position(t_game *game, int y, int x, char direction);
void validate_map_characters(t_game *game);
void find_player_position(t_game *game);

void init_visited(t_visited *visited, t_game *game);
void check_visited_cells(t_game *game, t_visited *visited);
void check_map_edges(t_game *game);
void check_empty_space_borders(t_game *game);
void check_cell_borders(t_game *game, int y, int x);
void free_visited(t_visited *visited);
void flood_fill(t_game *game, t_visited *visited, int x, int y);
void check_map_surrounded_by_walls(t_game *game);

int parse_texture(char *line, t_game *game);
int parse_color_element(char *line, t_game *game);
int check_rgb_parts(t_rgb_parser *rgb_parser);
int parse_rgb_values(t_rgb_parser *rgb_parser, t_color *color);
int validate_digit_string(char *str);
void free_rgb_parts(t_rgb_parser *rgb_parser);
int validate_color_range(t_color *color);
int parse_element(char *line, t_game *game);
int parse_color(const char *line, t_color *color);

void free_textures(t_game *game);
void free_map_grid(t_game *game);
void free_game(t_game *game);
void exit_error(const char *msg);

#endif
