/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:11:21 by smiranda          #+#    #+#             */
/*   Updated: 2024/10/19 15:53:28 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	get_map(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open file.\n");
    line = get_next_line(fd);
	if (!line)
		print_error("Empty file.\n");
	game->map_line = c_strdup(line);
	free(line);
    while ((line = get_next_line(fd)) != NULL)
	{
		game->map_line = c_strjoin(game->map_line, line);
		free(line);
	}
	close(fd);
}

static void	get_dim(t_game *game)
{
	size_t i;
	int longest_line;
    int current_line_len;

    i = 0;
    longest_line = 0;
    current_line_len = 0;
	while (game->map_line[i] != '\0')
	{
		if (game->map_line[i] == '\n')
		{
			if (current_line_len > longest_line)
				longest_line = current_line_len;
			game->map.height++; 
			current_line_len = 0;
		}
		else
			current_line_len++;
		i++;
	}
	if (current_line_len > longest_line)
		longest_line = current_line_len;
	if (current_line_len > 0)
		game->map.height++;
	game->map.width = longest_line;
}

static void	valid_components(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->map_line))
	{
		if (game->map_line[i] != ' ' && game->map_line[i] != '1'
			&& game->map_line[i] != '0' && game->map_line[i] != 'N'
			&& game->map_line[i] != 'S' && game->map_line[i] != 'E'
			&& game->map_line[i] != 'W' && game->map_line[i] != '\n')
			print_error("Invalid map.\n");
		i++;
	}
}

// void get_map_array(t_game *game)
// {
// 	size_t i;
// 	size_t j;
// 	size_t k;

// 	i = 0;
// 	k = 0;
// 	game->map.grid = (char **)safe_calloc(game->map.height, sizeof(char *));
// 	while (i < game->map.height)
// 	{
// 		game->map.grid[i] = (char *)safe_empty(game->map.width + 1, sizeof(char));
// 		j = 0;
// 		while (j < game->map.width)
// 		{
// 			if (game->map_line[k] == '\n' || game->map_line[k] == '\0')
// 			{	
// 				while (j < game->map.width)
// 				{
// 					game->map.grid[i][j] = ' ';
// 					j++;
// 				}
// 				break;
// 			}
// 			game->map.grid[i][j] = game->map_line[k];
//             k++;
//             j++;
//         }
// 		if (game->map_line[k] == '\n')
// 			k++;
// 		game->map.grid[i][j] = '\0';
//         i++;
//     }
// }

static void store_character(t_game *game, size_t row, size_t col)
{
	game->x = col;
	game->y = row;
	if (game->map.grid[row][col] == 'N')
		game->angle = 90;
	else if (game->map.grid[row][col] == 'S')
		game->angle = 270;
	else if (game->map.grid[row][col] == 'E')
		game->angle = 0;
	else if (game->map.grid[row][col] == 'W')
		game->angle = 180;
	game->map.grid[row][col] = '0';
}

static void parse_map(t_game *game, size_t row, size_t *k)
{
	size_t j;

	j = 0;
	while (j < game->map.width)
	{
		if (game->map_line[*k] == '\n' || game->map_line[*k] == '\0')
		{	
			while (j < game->map.width)
			{
				game->map.grid[row][j] = ' ';
				j++;
			}
			break;
		}
		if (game->map_line[*k] == 'N' || game->map_line[*k] == 'S'
			|| game->map_line[*k] == 'E' || game->map_line[*k] == 'W')
			store_character(game, row, j);	
		else
			game->map.grid[row][j] = game->map_line[*k];
		(*k)++;
		j++;
	}
	game->map.grid[row][j] = '\0';
}

void get_map_array(t_game *game)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	game->map.grid = (char **)safe_calloc(game->map.height, sizeof(char *));
	while (i < game->map.height)
	{
		game->map.grid[i] = (char *)safe_empty(game->map.width + 1, sizeof(char));
		parse_map(game, i, &k);
		if (game->map_line[k] == '\n')
			k++;
		i++;
	}
}

void	read_map(char *file, t_game *game)
{
	get_map(file, game);
    get_dim(game);
    valid_components(game);
	get_map_array(game);
}