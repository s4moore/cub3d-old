/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:59:56 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	draw(t_game *game)
{
	int	x;

	x = -1;
	draw_stars(game);
	put_image(game);
	while (++x < SCREEN_W)
	{
		calculate_initial_props(game, x);
		calculate_gridline_distance(game, game->props);
		calculate_wall_distance(game, game->props);
		calcualte_slice_properties(game);
		calcualte_texture_properties(game->props);
		select_texture_by_wall_direction(game->props);
		draw_walls(game, x);
		get_floor_start_position(game);
		draw_floor(game, game->props, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	update_speed(game);
	return (0);
}
