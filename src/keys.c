/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:32:29 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/18 19:11:47 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	move_forward(t_game *game)
{
	int new_x;
	int new_y;

	new_x = game->x + (int)game->dx;
	new_y = game->y + (int)game->dy;
	if (new_x >= 0 && new_x < (int)game->map.width
		&& new_y >= 0 && new_y < (int)game->map.height
		&& game->map.grid[new_y][new_x] == '0')
	{
		game->map.grid[(int)game->y][(int)game->x] = '0';
		game->x = new_x;
		game->y = new_y;
		set_pos(game);
	}
	update_display(game);
}

void	move_back(t_game *game)
{
	int new_x;
	int new_y;

	new_x = game->x - (int)game->dx;
	new_y = game->y - (int)game->dy;
	if (new_x >= 0 && new_x < (int)game->map.width
		&& new_y >= 0 && new_y < (int)game->map.height
		&& game->map.grid[new_y][new_x] == '0')
	{
		game->map.grid[(int)game->y][(int)game->x] = '0';
		game->x = new_x;
		game->y = new_y;
		set_pos(game);
	}
	update_display(game);
}

void	look_left(t_game *game)
{
	game->angle -= 0.1;
	if (game->angle < 0)
		game->angle += 2 * PI;
	game->dx = cos(game->angle);
	game->dy = sin(game->angle);
	set_pos(game);
	update_display(game);
}

void	look_right(t_game *game)
{
	game->angle += 0.1;
	if (game->angle > 2 * PI)
		game->angle -= 2 * PI;
	game->dx = cos(game->angle);
	game->dy = sin(game->angle);
	set_pos(game);
	update_display(game);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_forward(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_back(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		look_left(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		look_right(game);
}
