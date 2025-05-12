/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:47:00 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 21:40:13 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	draw_walls(t_game *game, int x)
{
	t_draw_props	*props;
	unsigned int	color;
	int				y;

	props = game->props;
	y = props->draw_start - 1;
	while (++y < props->draw_end)
	{
		props->tex.y = ((int)props->tex_offset);
		props->tex_offset += props->tex_step;
		// printf("Accessing texture %d at x=%d, y=%d\n",
		// 	props->tex_num, props->tex.x, props->tex.y);
		color = (game->tex[props->tex_num].addr)[TEXTURE_SIZE
			* props->tex.y + props->tex.x];
		color = (color >> 1) & 4355711;
		put_pixel(game, x, y, color);
	}
}
