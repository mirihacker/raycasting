/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:59:23 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/18 17:05:14 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	check_args(int ac, char **av)
{
	if (ac != 2)
		print_error("Invalid number of arguments.\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		print_error("Invalid file extension.\n");
}

static void	init_vars(t_game *game)
{
    game->x = 0;
    game->y = 0;
    game->dx = cos(radians(game->angle));
    game->dy = -sin(radians(game->angle));
    game->angle = 0;
    game->map.width = 0;
    game->map.height = 0;
    game->map.grid = NULL;
    game->map_line = NULL;
}

int main(int ac, char **av)
{
    t_game *game;
    
    game = safe_malloc(sizeof(t_game));
    check_args(ac, av);
    init_vars(game);
    read_map(av[1], game);
    start_game(game);
    return (0);
}