/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:12:30 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/21 17:47:23 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	mark_position(t_game *game)
{
	if (game->angle < PI / 4 || game->angle > 7 * PI / 4) // facing North
		game->map.grid[(int)game->y][(int)game->x] = 'N';
	else if (game->angle > PI / 4 && game->angle < 3 * PI / 4) // facing East
		game->map.grid[(int)game->y][(int)game->x] = 'E';
	else if (game->angle > 3 * PI / 4 && game->angle < 5 * PI / 4)
		// facing South
		game->map.grid[(int)game->y][(int)game->x] = 'S';
	else // facing West
		game->map.grid[(int)game->y][(int)game->x] = 'W';
}

void	set_pos(t_game *game)
{
	game->map.grid[(int)game->y][(int)game->x] = '0';
	mark_position(game);
}

void render_player(t_game *game)
{
	int tile;
	int play_tile;
	int offset;

	tile = 30;
	play_tile = 10;
	offset = (tile - play_tile) / 2;
    mlx_image_to_window(game->mlx, game->image->character, (int)(game->x * tile) + offset, (int)(game->y * tile) + offset);
}

void	update_display(t_game *game)
{
	set_image(game);
	render_player(game);
}

void game_update(void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (game->m_forward)
		move_forward(game);
	if (game->m_back)
        move_back(game);
    if (game->l_left)
        look_left(game);
    if (game->l_right)
        look_right(game);
	update_display(game);
}
