/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:25:08 by samoore           #+#    #+#             */
/*   Updated: 2025/05/13 11:57:24 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// # include <mlx.h>
// # include <math.h>
// # include <stdlib.h>
// # include <X11/keysym.h> //keysym
// # include <sys/time.h>

#define SCREEN_W 1800
#define SCREEN_H 1080
// #define TEXTURE_SIZE 1024
// #define NUM_STARS 30000
// #define NUM_PLANETS 1
// #define STAR_SPHERE_RADIUS 10.0
#define MAP_W 24
#define MAP_H 24
// #define LEFT -1
// #define RIGHT 1
// #ifndef M_PI
// # define M_PI 3.14159265358979323846
// #endif

typedef unsigned int uint_32;
uint_32	buffer[SCREEN_H][SCREEN_W];


// typedef struct s_xyz {
//     double x;
//     double y;
//     double z;
// } t_xyz;

// typedef struct s_star {
//     double	x;
//     double	y;
//     double	z;
//     double	size;
// 	double	screen_x;
// 	double	screen_y;
//     int		color;
// 	int		twinkle;
// 	int		timer;
// 	int		twinkle_color;
// } t_star;

int	g_world_map[MAP_W][MAP_H] = \
{
{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7},
{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
{4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
{4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
{4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
{4, 0, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 0, 7, 7, 7, 7, 7},
{4, 0, 5, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
{4, 0, 6, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 4},
{4, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 1},
{4, 0, 4, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 4},
{4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
{4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 1},
{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
{6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
{4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3},
{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2},
{4, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}
};



// typedef struct s_xy_dbl
// {
// 	double	x;
// 	double	y;
// }	t_xy_dbl;

// typedef struct s_xy_int
// {
// 	int	x;
// 	int	y;
// }	t_xy_int;

// typedef struct s_draw_props
// {
// 	t_xy_dbl	ray_dir;
// 	t_xy_dbl	delta;
// 	t_xy_dbl	ray_dist;
// 	t_xy_int	step;
// 	t_xy_int	tex;
// 	t_xy_dbl	floor_start;
// 	double		wall_x;
// 	double		wall_dist;
// 	int			side;
// 	int			tex_num;
// 	int			line_height;
// 	int			draw_start;
// 	int			draw_end;
// 	double		tex_step;
// 	double		tex_offset;
// 	double		col;
// }	t_draw_props;


// typedef struct s_planet{
// 	uint_32		*img;
// 	int			w;
// 	int			h;
// 	t_xyz		pos;
// 	t_xy_int	screen;
// 	double orbit_radius;
// 	double orbit_height;
// 	double orbit_angle;
// }	t_planet;

// void	set_star_colour(t_game *game, int i);
// void	create_stars(t_game *game);
// void	put_planet_in_3d(t_game *game);
// void	load_planets(t_game *game);
// t_game	*init(void);
// void	exit_program(t_game *game);
// static inline int	pixel_pos(int x, int y, int size_line, int bpp);
// void	put_pixel(t_game *game, int x, int y, int color);
// unsigned int	get_ticks(void);
// void	set_view_direction(t_game *game, char direction);
// void	load_textures(t_game *game);
// void	ray_caster_init(t_game *game);
// t_xy_int	calculate_gridline_distance(t_game *game, t_draw_props *props);
// void	get_floor_start_position(t_game *game);
// void	calculate_wall_distance(t_game *game, t_draw_props *props);
// void	select_texture_by_wall_direction(t_draw_props *props);
// void	calcualte_slice_properties(t_game *game);
// void	calcualte_texture_properties(t_draw_props *props);
// void	draw_walls(t_game *game, int x);
// void	calculate_initial_props(t_game *game, int x);
// void	draw_floor(t_game *game, t_draw_props *props, int x);
// void	update_speed(t_game *game);
// void	draw_star(t_game *game, t_star s, int color);
// void	put_image(t_game *game);
// void	draw_stars(t_game *game);
// double	get_player_rotation_angle(t_game *game);
// int	draw(t_game *game);
// int	key_press(int keycode, t_game *game);
// int	key_release(int keycode, t_game *game);
// void	check_up_down_arrows(t_game *game);
// void	check_strafe(t_game *game);
// void	rotate_stars(t_game *game, t_star *stars, int direction);
// void	rotate_planets(t_game *game, int direction);
// void	check_left_arrow(t_game *game);
// void	check_right_arrow(t_game *game);
// int	update(t_game *game);
#endif