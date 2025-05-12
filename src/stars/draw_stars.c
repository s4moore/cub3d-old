/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:49:32 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	draw_star(t_game *game, t_star s, int color)
{
	int	y;
	int	err;

	y = 0;
	err = 0;
	while (s.size >= y)
	{
		put_pixel(game, s.screen_x + s.size, s.screen_y + y, color);
		put_pixel(game, s.screen_x + y, s.screen_y + s.size, color);
		put_pixel(game, s.screen_x - y, s.screen_y + s.size, color);
		put_pixel(game, s.screen_x - s.size, s.screen_y + y, color);
		put_pixel(game, s.screen_x - s.size, s.screen_y - y, color);
		put_pixel(game, s.screen_x - y, s.screen_y - s.size, color);
		put_pixel(game, s.screen_x + y, s.screen_y - s.size, color);
		put_pixel(game, s.screen_x + s.size, s.screen_y - y, color);
		y += 1;
		if (err <= 0)
			err += 2 * y + 1;
		if (err > 0)
		{
			s.size -= 1;
			err -= 2 * s.size + 1;
		}
	}
}

void	draw_stars(t_game *game)
{
	t_star	s;
	int		i;

	i = -1;
	while (++i < NUM_STARS)
	{
		s = game->stars[i];
		game->stars[i].timer++;
		if (s.z <= 1)
			continue ;
		s.screen_x = (s.x / s.y) * (SCREEN_W / 2) + (SCREEN_W / 2);
		s.screen_y = (s.z / s.y) * (SCREEN_H / 2) + (SCREEN_H / 2);
		if (s.screen_x >= 0 && s.screen_x < SCREEN_W
			&& s.screen_y >= 0 && s.screen_y < SCREEN_H / 2)
		{
			if (s.timer > 1)
				draw_star(game, s, (int)s.color);
			else
				draw_star(game, s, 0xffffffff);
			if (s.timer >= s.twinkle)
				game->stars[i].timer = 0;
		}
	}
}
