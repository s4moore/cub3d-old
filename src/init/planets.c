/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:28:05 by samoore           #+#    #+#             */
/*   Updated: 2025/05/13 13:26:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	put_planet_in_3d(t_game *game)
{
	double	theta;
	double	height;
	int		i;

	i = -1;
	while (++i < NUM_PLANETS)
	{
		theta = ((double)rand() / RAND_MAX) * 2.0 * M_PI;
		height = ((double)rand() / RAND_MAX) * SCREEN_H - SCREEN_H / 2.0;
		game->planets[i].orbit_radius = SCREEN_W;
		game->planets[i].orbit_height = height;
		game->planets[i].orbit_angle = theta;
		game->planets[i].pos.x = SCREEN_W * cos(theta);
		game->planets[i].pos.z = SCREEN_W * sin(theta);
		game->planets[i].pos.y = height;
	}
}

void	load_planets(t_game *game)
{
	int	i;
	int	bpp;
	int	line_len;
	int	endian;

	i = -1;
	// while (++i < 1)
	// 	game->planets[i].img = malloc(
	// 			sizeof(unsigned int) * TEXTURE_SIZE * TEXTURE_SIZE);
	game->planets[0].img = mlx_xpm_file_to_image(
			game->mlx, "pics/mars.xpm",
			&game->planets[i].w, &game->planets[i].h);
	i = -1;
	while (++i < 1)
		game->planets[i].addr = (t_unit32*)mlx_get_data_addr(
				game->planets[i].img, &line_len, &bpp, &endian);
	game->planets[0].w = 800;
	game->planets[0].h = 800;
	game->planets[0].pos.x = 1;
	game->planets[0].pos.y = 15;
	game->planets[0].pos.z = 100;
	put_planet_in_3d(game);
}
