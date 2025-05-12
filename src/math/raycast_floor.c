/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:43:56 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	get_floor_start_position(t_game *game)
/*Determines where to start drawing the floor from*/
{
	t_draw_props	*props;

	props = game->props;
	if (props->side == 0 && props->ray_dir.x > 0)
	{
		props->floor_start.x = game->map_x;
		props->floor_start.y = game->map_y + props->wall_x;
	}
	else if (props->side == 0 && props->ray_dir.x < 0)
	{
		props->floor_start.x = game->map_x + 1.0;
		props->floor_start.y = game->map_y + props->wall_x;
	}
	else if (props->side == 1 && props->ray_dir.y > 0)
	{
		props->floor_start.x = game->map_x + props->wall_x;
		props->floor_start.y = game->map_y;
	}
	else
	{
		props->floor_start.x = game->map_x + props->wall_x;
		props->floor_start.y = game->map_y + 1.0;
	}
}
