/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:12:30 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/18 19:46:18 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

void mark_position(t_game *game)
{
    if (game->angle < PI / 4 || game->angle > 7 * PI / 4) // facing North
        game->map.grid[(int)game->y][(int)game->x] = 'N';
    else if (game->angle > PI / 4 && game->angle < 3 * PI / 4) // facing East
        game->map.grid[(int)game->y][(int)game->x] = 'E';
    else if (game->angle > 3 * PI / 4 && game->angle < 5 * PI / 4) // facing South
        game->map.grid[(int)game->y][(int)game->x] = 'S';
    else // facing West
        game->map.grid[(int)game->y][(int)game->x] = 'W';
}

void set_pos(t_game *game)
{
    size_t x;
    size_t y;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S'
                || game->map.grid[y][x] == 'E' || game->map.grid[y][x] == 'W')
            {
                game->map.grid[y][x] = '0';
            }
            x++;
        }
        y++;
    }
    mark_position(game);
}


void update_display(t_game *game)
{
    set_image(game);
}
