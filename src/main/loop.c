/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:06:24 by samoore           #+#    #+#             */
/*   Updated: 2025/05/12 22:34:02 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	main_loop(t_game *game)
{
	check_up_down_arrows(game);
	check_left_arrow(game);
	check_right_arrow(game);
	check_strafe(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	draw(game);
	return (0);
}
