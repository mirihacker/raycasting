/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:12:30 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/19 18:36:53 by smiranda         ###   ########.fr       */
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

void	update_display(t_game *game)
{
	set_image(game);
}

void clear_player_pos(t_game *game)
{
    mlx_image_to_window(game->mlx, game->image->blank, (int)(game->x * 30), (int)(game->y * 30));
}

void update_player_pos(t_game *game)
{
    clear_player_pos(game);
    set_pos(game);
}

void render_player(t_game *game)
{
    mlx_image_to_window(game->mlx, game->image->character, (int)(game->x * 10), (int)(game->y * 10));
}