#include "cub3d.h"

int	main(void)
{
	t_game	*game;

	game = init();
	ray_caster_init(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
	exit_program(game);
	return (0);
}
