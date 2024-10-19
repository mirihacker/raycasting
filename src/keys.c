/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:32:29 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/19 18:33:02 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	move_forward(t_game *game)
{
	float new_x;
	float new_y;

	new_x = game->x + game->dx * MOVE_FACTOR;
	new_y = game->y + game->dy * MOVE_FACTOR;
	if (new_x >= 0 && new_x < (float)game->map.width
		&& new_y >= 0 && new_y < (float)game->map.height
		&& game->map.grid[(int)new_y][(int)new_x] == '0')
	{
		clear_player_pos(game);
		game->x = new_x;
		game->y = new_y;
		update_player_pos(game);
	}
}

void	move_back(t_game *game)
{
	float new_x;
	float new_y;

	new_x = game->x - game->dx * MOVE_FACTOR;
	new_y = game->y - game->dy * MOVE_FACTOR;
	if (new_x >= 0 && new_x < (float)game->map.width
		&& new_y >= 0 && new_y < (float)game->map.height
		&& game->map.grid[(int)new_y][(int)new_x] == '0')
	{
		clear_player_pos(game);
		game->x = new_x;
		game->y = new_y;
		update_player_pos(game);
	}
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
	render_player(game);
	update_display(game);
}
