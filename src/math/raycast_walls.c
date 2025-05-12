/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:42:00 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	calculate_gridline_distance(t_game *game, t_draw_props *props)
{
	if (props->ray_dir.x < 0)
	{
		props->step.x = -1;
		props->ray_dist.x = (game->player.x - game->map_x) * props->delta.x;
	}
	else
	{
		props->step.x = 1;
		props->ray_dist.x
			= (game->map_x + 1.0 - game->player.x) * props->delta.x;
	}
	if (props->ray_dir.y < 0)
	{
		props->step.y = -1;
		props->ray_dist.y
			= (game->player.y - game->map_y) * props->delta.y;
	}
	else
	{
		props->step.y = 1;
		props->ray_dist.y
			= (game->map_y + 1.0 - game->player.y) * props->delta.y;
	}
}

void	calculate_wall_distance(t_game *game, t_draw_props *props)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (props->ray_dist.x < props->ray_dist.y)
		{
			props->ray_dist.x += props->delta.x;
			game->map_x += props->step.x;
			props->side = 0;
		}
		else
		{
			props->ray_dist.y += props->delta.y;
			game->map_y += props->step.y;
			props->side = 1;
		}
		if (g_world_map[game->map_x][game->map_y] > 0)
			hit = 1;
	}
	if (props->side == 0)
		props->wall_dist = props->ray_dist.x - props->delta.x;
	else
		props->wall_dist = props->ray_dist.y - props->delta.y;
}

void	select_texture_by_wall_direction(t_draw_props *props)
{
	if (props->side == 0)
	{
		if (props->ray_dir.x > 0)
			props->tex_num = 0;
		else
			props->tex_num = 1;
	}
	else
	{
		if (props->ray_dir.y > 0)
			props->tex_num = 2;
		else
			props->tex_num = 3;
	}
}

void	calcualte_slice_properties(t_game *game)
{
	t_draw_props	*props;

	props = game->props;
	props->line_height = (int)(SCREEN_H / props->wall_dist);
	props->draw_start = -props->line_height / 2 + SCREEN_H / 2;
	if (props->draw_start < 0)
		props->draw_start = 0;
	props->draw_end = props->line_height / 2 + SCREEN_H / 2;
	if (props->draw_end >= SCREEN_H)
		props->draw_end = SCREEN_H - 1;
	if (props->side == 0)
		props->wall_x = game->player.y + props->wall_dist * props->ray_dir.y;
	else
		props->wall_x = game->player.x + props->wall_dist * props->ray_dir.x;
	props->wall_x -= floor(props->wall_x);
}

void	calcualte_texture_properties(t_draw_props *props)
{
	props->tex.x = (int)(props->wall_x * (double)TEXTURE_SIZE);
	if (props->side == 0 && props->ray_dir.x > 0)
		props->tex.x = TEXTURE_SIZE - props->tex.x - 1;
	if (props->side == 1 && props->ray_dir.y < 0)
		props->tex.x = TEXTURE_SIZE - props->tex.x - 1;
	props->tex_step = 1.0 * TEXTURE_SIZE / props->line_height;
	props->tex_offset = (props->draw_start - SCREEN_H / 2
			+ props->line_height / 2) * props->tex_step;
}

void	calculate_initial_props(t_game *game, int x)
{
	t_draw_props	*props;

	props = game->props;
	props->col = 2 * x / (double)SCREEN_W - 1;
	props->ray_dir.x = game->dir.x + game->plane_x * props->col;
	props->ray_dir.y = game->dir.y + game->plane_y * props->col;
	game->map_x = (int)(game->player.x);
	game->map_y = (int)(game->player.y);
	if (props->ray_dir.x == 0)
		props->delta.x = 1e30;
	else
		props->delta.x = fabs(1 / props->ray_dir.x);
	if (props->ray_dir.y == 0)
		props->delta.y = 1e30;
	else
		props->delta.y = fabs(1 / props->ray_dir.y);
}
