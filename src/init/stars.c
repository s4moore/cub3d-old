/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:26:44 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	set_star_colour(t_game *game, int i)
{
	int	r;
	int	g;
	int	b;

	g = rand() % 36 + 140;
	b = rand() % 36 + 140;
	r = rand() % 36 + 140;
	game->stars[i].color = (r << 16) | (g << 8) | b;
	game->stars[i].twinkle_color
		= ((int)(r / 1.5) << 16) | ((int)(g / 1.5) << 8) | b;
	game->stars[i].twinkle = ((rand() % 1000) + 5) * 10;
	game->stars[i].timer = 0;
}

void	create_stars(t_game *game)
{
	double	theta;
	int		i;
	double	phi;
	int		w;
	int		h;

	h = 0;
	w = 0;
	game->stars = malloc(sizeof(t_star) * NUM_STARS);
	if (!game->stars)
		return ;
	i = -1;
	while (++i < NUM_STARS)
	{
		theta = ((double)rand() / RAND_MAX) * 2.0 * M_PI;
		phi = acos(2.0 * ((double)rand() / RAND_MAX) - 1.0);
		game->stars[i].x = 100 * sin(phi) * cos(theta);
		game->stars[i].y = 100 * cos(phi);
		game->stars[i].z = 100 * sin(phi) * sin(theta);
		game->stars[i].size = rand() % 3;
		set_star_colour(game, i);
	}
}
