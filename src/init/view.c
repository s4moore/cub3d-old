/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:38:10 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	set_view_direction(t_game *game, char direction)
{
	double	old_dir_x;
	double	old_plane_x;

	if (direction == 'N')
		game->rot_speed = 0;
	if (direction == 'W')
		game->rot_speed = 1.5;
	if (direction == 'S')
		game->rot_speed = 3;
	if (direction == 'E')
		game->rot_speed = -1.5;
	old_dir_x = game->dir.x;
	game->dir.x = game->dir.x * cos(game->rot_speed)
		- game->dir.y * sin(game->rot_speed);
	game->dir.y = old_dir_x * sin(game->rot_speed)
		+ game->dir.y * cos(game->rot_speed);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(game->rot_speed)
		- game->plane_y * sin(game->rot_speed);
	game->plane_y = old_plane_x * sin(game->rot_speed)
		+ game->plane_y * cos(game->rot_speed);
}