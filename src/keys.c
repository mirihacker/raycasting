/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:32:29 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/21 17:58:52 by smiranda         ###   ########.fr       */
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
		game->x = new_x;
		game->y = new_y;
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
		game->x = new_x;
		game->y = new_y;
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
}

void	look_right(t_game *game)
{
	game->angle += 0.1;
	if (game->angle > 2 * PI)
		game->angle -= 2 * PI;
	game->dx = cos(game->angle);
	game->dy = sin(game->angle);
	set_pos(game);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			game->m_forward = true;
		else if (keydata.key == MLX_KEY_S)
			game->m_back = true;
		else if (keydata.key == MLX_KEY_A)
			game->l_left = true;
		else if (keydata.key == MLX_KEY_D)
			game->l_right = true;
	}
	else if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W)
			game->m_forward = false;
		else if (keydata.key == MLX_KEY_S)
			game->m_back = false;
		else if (keydata.key == MLX_KEY_A)
			game->l_left = false;
		else if (keydata.key == MLX_KEY_D)
			game->l_right = false;
	}
	 printf("W: %d, S: %d, A: %d, D: %d\n", game->m_forward, game->m_back, game->l_left, game->l_right);
}
