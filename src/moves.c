/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:32:29 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/18 14:04:40 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


void move_forward(t_game *game)
{
    game->x += game->dx;
    game->y += game->dy;
}

void move_back(t_game *game)
{
    game->x -= game->dx;
    game->y -= game->dy;
}

void look_left(t_game *game)
{
    game->angle -= 0.1;
    if (game->angle < 0)
        game->angle += 2 * PI;
    game->dx = cos(game->angle) * 5;
    game->dy = sin(game->angle) * 5;
}

void look_right(t_game *game)
{
   game->angle += 0.1;
    if (game->angle > 2 * PI)
        game->angle -= 2 * PI;
    game->dx = cos(game->angle) * 5;
    game->dy = sin(game->angle) * 5;
}

void key_handler(mlx_key_data_t keydata, void *param)
{
    t_game *game;

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