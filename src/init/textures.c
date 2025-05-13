/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:39:11 by samoore           #+#    #+#             */
/*   Updated: 2025/05/13 11:57:24 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	load_textures(t_game *game)
{
	int		i;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;

	char *paths[5] = {
		"pics/cobble.xpm",
		"pics/rusty1.xpm",
		"pics/rock1.xpm",
		"pics/rose.xpm",
		"pics/slate.xpm"
	};

	i = -1;
	while (++i < 5)
	{
		game->tex[i].img = mlx_xpm_file_to_image(game->mlx, paths[i], &width, &height);
		if (!game->tex[i].img)
		{
			fprintf(stderr, "Failed to load texture: %s\n", paths[i]);
			exit(1);
		}
		game->tex[i].addr = (uint_32 *)mlx_get_data_addr(game->tex[i].img, &bpp, &line_len, &endian);
	}
}
