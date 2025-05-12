/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:36:49 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 21:16:56 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

// static inline int	pixel_pos(int x, int y, int size_line, int bpp)
// {
// 	return (y * size_line + x * (bpp / 8));
// }

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H)
		return ;
	dst = game->addr + (y * game->line_len + x * (game->bpp / 8));
	*(unsigned int *) dst = color;
}

unsigned int	get_ticks(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned int)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	update_speed(t_game *game)
{
	double	frame_time;

	game->old_time = game->time;
	game->time = get_ticks();
	frame_time = (game->time - game->old_time) / 1000.0;
	game->move_speed = frame_time * 5.0;
	game->rot_speed = frame_time * 2.5;
}

double	get_player_rotation_angle(t_game *game)
{
	return (atan2(game->dir.y, game->dir.x));
}