/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:53:11 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/19 15:45:25 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void init_image(t_game *game)
{
    game->texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!game->texture)
		print_error("Failed to allocate textures");
	game->texture->blank = mlx_load_png("./images/blank.png");
	game->texture->character = mlx_load_png("./images/character.png");
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->texture->empty = mlx_load_png("./images/empty.png");
	game->image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!game->image)
		print_error("Failed to allocate images");
	game->image->blank = mlx_texture_to_image(game->mlx, game->texture->blank);
	game->image->character = mlx_texture_to_image(game->mlx,
			game->texture->character);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->empty = mlx_texture_to_image(game->mlx, game->texture->empty);
	mlx_delete_texture(game->texture->blank);
	mlx_delete_texture(game->texture->character);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->empty);
}

void build_image(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
		mlx_image_to_window(game->mlx, game->image->wall, x * 30, y * 30);
	else if (game->map.grid[y][x] == '0')
		mlx_image_to_window(game->mlx, game->image->blank, x * 10, y * 10);
	else if (game->map.grid[y][x] == 'N' || game->map.grid[y][x] == 'S'
			|| game->map.grid[y][x] == 'E' || game->map.grid[y][x] == 'W')
		{
			mlx_image_to_window(game->mlx, game->image->character, x * 30, y * 30);
			game->x = x;
			game->y = y;
		}

	else if (game->map.grid[y][x] == ' ')
		mlx_image_to_window(game->mlx, game->image->empty, x * 30, y * 30);
}

void set_image(t_game *game)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			build_image(game, x, y);
			x++;
		}
		y++;
	}
}

int start_game(t_game *game)
{
    game->mlx = mlx_init(game->map.width * 30, game->map.height * 30, "Raycasting", false);
    if (!game->mlx)
        print_error("Failed to initialize mlx.\n");
    init_image(game);
    set_image(game);
    mlx_key_hook(game->mlx, key_handler, game);
    mlx_loop(game->mlx);
    return (0);
}