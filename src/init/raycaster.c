/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:40:12 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 18:39:42 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	ray_caster_init(t_game *game)
{
	game->player.x = 22.0;
	game->player.y = 22.0;
	game->dir.x = -1;
	game->dir.y = 0;
	game->plane_x = 0;
	game->plane_y = 0.6;
	game->time = 0;
	game->old_time = 0;
	set_view_direction(game, 'N');
	load_textures(game);
}