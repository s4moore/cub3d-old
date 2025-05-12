/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:04:04 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	rotate_stars(t_game *game, t_star *stars, int direction)
{
	double	cos_rot;
	double	sin_rot;
	double	old_x;
	double	old_y;
	int		i;

	cos_rot = cos(direction * game->rot_speed * 0.5);
	sin_rot = sin(direction * game->rot_speed * 0.5);
	i = -1;
	while (++i < NUM_STARS)
	{
		old_x = stars[i].x;
		old_y = stars[i].y;
		stars[i].x = old_x * cos_rot - old_y * sin_rot;
		stars[i].y = old_x * sin_rot + old_y * cos_rot;
	}
}
