/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:48:10 by samoore           #+#    #+#             */
/*   Updated: 2025/05/13 13:26:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	draw_floor(t_game *game, t_draw_props *props, int x)
{
	t_xy_dbl	current_floor;
	double		current_dist;
	double		weight;
	int			y;

	y = props->draw_end;
	while (++y < SCREEN_H)
	{
		current_dist = SCREEN_H / (2.0 * y - SCREEN_H);
		weight = current_dist / props->wall_dist;
		current_floor.x = weight * props->floor_start.x
			+ (1.0 - weight) * game->player.x;
		current_floor.y = weight * props->floor_start.y
			+ (1.0 - weight) * game->player.y;
		put_pixel(
			game,
			x,
			y,
			game->tex[4].addr[1024 * ((int)(current_floor.y * 1024) % 1024)
			+ ((int)(current_floor.x * 1024) % 1024)]);
	}
}
/*// Ceiling (mirror y)
// t_unit32 ceilColor = 
	ceilTexture[floorgame->tex.y * TEXTURE_SIZE + floorgame->Tex.x];
// put_pixel(game, x, screenHeight - y, ceilColor);*/

