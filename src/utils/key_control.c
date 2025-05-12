/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:02:47 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 21:59:04 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	check_up_down_arrows(t_game *game)
{
	if (game->keys[XK_Up] || game->keys[XK_w])
	{
		if (g_world_map[(int)(game->player.x + game->dir.x
				* game->move_speed)][(int)game->player.y] == 0)
			game->player.x += game->dir.x * game->move_speed;
		if (g_world_map[(int)game->player.x][(int)(game->player.y
			+ game->dir.y * game->move_speed)] == 0)
			game->player.y += game->dir.y * game->move_speed;
	}
	if (game->keys[XK_Down] || game->keys[XK_s])
	{
		if (g_world_map[(int)(game->player.x - game->dir.x
				* game->move_speed)][(int)game->player.y] == 0)
			game->player.x -= game->dir.x * game->move_speed;
		if (g_world_map[(int)game->player.x][(int)(game->player.y
			- game->dir.y * game->move_speed)] == 0)
			game->player.y -= game->dir.y * game->move_speed;
	}
}

void	check_strafe(t_game *game)
{
	double	x;
	double	y;

	if (game->keys[XK_d])
	{
		x = game->dir.y;
		y = -game->dir.x;
		if (g_world_map[(int)(game->player.x + x * game->move_speed)]
				[(int)game->player.y] == 0)
			game->player.x += x * game->move_speed;
		if (g_world_map[(int)game->player.x][(int)(game->player.y + y
			* game->move_speed)] == 0)
			game->player.y += y * game->move_speed;
	}
	if (game->keys[XK_a])
	{
		x = -game->dir.y;
		y = game->dir.x;
		if (g_world_map[(int)(game->player.x + x * game->move_speed)]
				[(int)game->player.y] == 0)
			game->player.x += x * game->move_speed;
		if (g_world_map[(int)game->player.x][(int)(game->player.y + y
			* game->move_speed)] == 0)
			game->player.y += y * game->move_speed;
	}
}

void	check_left_arrow(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->keys[0xff51])
	{
		old_dir_x = game->dir.x;
		game->dir.x = game->dir.x * cos(game->rot_speed)
			- game->dir.y * sin(game->rot_speed);
		game->dir.y = old_dir_x * sin(game->rot_speed)
			+ game->dir.y * cos(game->rot_speed);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(game->rot_speed)
			- game->plane_y * sin(game->rot_speed);
		game->plane_y = old_plane_x * sin(game->rot_speed)
			+ game->plane_y * cos(game->rot_speed);
		rotate_stars(game, game->stars, LEFT);
		game->planet_angle += game->rot_speed;
		rotate_planets(game, LEFT);
	}
}

void	check_right_arrow(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->keys[0xff53])
	{
		old_dir_x = game->dir.x;
		game->dir.x = game->dir.x * cos(-game->rot_speed)
			- game->dir.y * sin(-game->rot_speed);
		game->dir.y = old_dir_x * sin(-game->rot_speed)
			+ game->dir.y * cos(-game->rot_speed);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(-game->rot_speed)
			- game->plane_y * sin(-game->rot_speed);
		game->plane_y = old_plane_x * sin(-game->rot_speed)
			+ game->plane_y * cos(-game->rot_speed);
		rotate_stars(game, game->stars, RIGHT);
		game->planet_angle -= game->rot_speed;
		rotate_planets(game, RIGHT);
	}
}
