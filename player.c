/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:18 by athekkan          #+#    #+#             */
/*   Updated: 2023/11/21 18:42:35 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_up(int key, t_so_long *game)
{
	if (key == 65362 || key == 119)
	{
		if (game->map[game->y - 1][game->x] == 'N')
			exit(0);
		if (game->map[game->y - 1][game->x] == 'E' && game->stats.coins == 0)
			exit(0);
		if (game->map[game->y - 1][game->x] != '1' &&
			game->map[game->y - 1][game->x] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->y--;
			if (game->map[game->y][game->x] == 'C')
				game->stats.coins--;
			game->map[game->y][game->x] = 'P';
			game->moves++;
		}
	}
}

static void	ft_move_down(int key, t_so_long *game)
{
	if (key == 65364 || key == 115)
	{
		if (game->map[game->y + 1][game->x] == 'N')
			exit(0);
		if (game->map[game->y + 1][game->x] == 'E' && game->stats.coins == 0)
			exit(0);
		if (game->map[game->y + 1][game->x] != '1'
			&& game->map[game->y + 1][game->x] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->y++;
			if (game->map[game->y][game->x] == 'C')
				game->stats.coins--;
			game->map[game->y][game->x] = 'P';
			game->moves++;
		}
	}
}

static void	ft_move_right(int key, t_so_long *game)
{
	if (key == 100 || key == 65363)
	{
		if (game->map[game->y][game->x + 1] == 'N')
			exit(0);
		if (game->map[game->y][game->x + 1] == 'E' && game->stats.coins == 0)
			exit(0);
		if (game->map[game->y][game->x + 1] != '1'
			&& game->map[game->y][game->x + 1] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->x++;
			if (game->map[game->y][game->x] == 'C')
				game->stats.coins--;
			game->map[game->y][game->x] = 'P';
			game->moves++;
		}
	}
}

static void	ft_move_left(int key, t_so_long *game)
{
	if (key == 65361 || key == 97)
	{
		if (game->map[game->y][game->x - 1] == 'N')
			exit(0);
		if (game->map[game->y][game->x - 1] == 'E' && game->stats.coins == 0)
			exit(0);
		if (game->map[game->y][game->x - 1] != '1'
			&& game->map[game->y][game->x - 1] != 'E')
		{
			game->map[game->y][game->x] = '0';
			game->x--;
			if (game->map[game->y][game->x] == 'C')
				game->stats.coins--;
			game->map[game->y][game->x] = 'P';
			game->moves++;
		}
	}
}

int	ft_move(int key, t_so_long *game)
{
	char	*steps;
	char	*coins;

	if (key == 65307 || key == 'q' || key == 'Q')
		exit(0);
	ft_move_up(key, game);
	ft_move_down(key, game);
	ft_move_right(key, game);
	ft_move_left(key, game);
	ft_draw_map(game);
	steps = ft_itoa(game->moves);
	coins = ft_itoa(game->stats.coins);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "STEPS:");
	mlx_string_put(game->mlx, game->win, 60, 10, 0xFFFFFF, steps);
	ft_printf("steps : %d\n", game->moves);
	mlx_string_put(game->mlx, game->win, 10, 40, 0xFFFFFF, "COINS:");
	mlx_string_put(game->mlx, game->win, 60, 40, 0xFFFFFF, coins);
	ft_printf("coins : %d\n\n", game->stats.coins);
	free(coins);
	free(steps);
	return (1);
}
