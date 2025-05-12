/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_planets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:04:48 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	rotate_planets(t_game *game, int direction)
{
	double	a;
	double	r;

	game->planets[0].orbit_angle += game->rot_speed * direction;
	a = game->planets[0].orbit_angle;
	r = game->planets[0].orbit_radius;
	game->planets[0].pos.x = r * cos(a);
	game->planets[0].pos.z = r * sin(a);
	game->planets[0].pos.y = game->planets[0].orbit_height;
}