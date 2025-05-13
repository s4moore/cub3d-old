/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_planet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:51:08 by samoore           #+#    #+#             */
/*   Updated: 2025/05/13 13:26:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	put_image(t_game *game)
{
	// t_xy_int	pos;
	t_unit32		clear;
	int			size;
	int			i;
	int			j;

	clear = game->planets[0].addr[0];
	if (game->planets[0].pos.z < 0)
		return ;
	size = 2;
	i = 0;
	while (i < game->planets[0].h)
	{
		j = 0;
		while (j < game->planets[0].w)
		{
			if (game->planets[0].addr[i * game->planets[0].w + j] != clear)
				put_pixel(game,
					(int)(SCREEN_W / 2 + game->planets[0].pos.x + j / size),
					100 + i / size,
					game->planets[0].addr[i * game->planets[0].w + j]);
			// printf("w %d, posx %d, offset %d\n", game->planets[0].w,
			// (int)game->planets[0].pos.x, i * game->planets[0].w + j);
			j += size;
		}
		i += size;
	}
}
