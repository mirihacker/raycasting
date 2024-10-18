#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef PI
#  define PI 3.14159265358979323846

# endif

typedef struct s_texture
{
	mlx_texture_t	*blank;
	mlx_texture_t	*character;
	mlx_texture_t	*wall;
	mlx_texture_t	*empty;
}					t_texture;

typedef struct s_image
{
	mlx_image_t		*blank;
	mlx_image_t		*character;
	mlx_image_t		*wall;
	mlx_image_t		*empty;
}					t_image;

typedef struct s_map
{
	size_t			width;
	size_t			height;
	char			**grid;
}					t_map;

typedef struct s_game
{
	void			*mlx;
	float			x;
	float			y;
	float			dx;
	float			dy;
	float			angle;
	char			*map_line;
	t_texture		*texture;
	t_image			*image;
	t_map			map;
}					t_game;

// utils.c //
char				*c_strdup(char *str);
char				*c_strjoin(char *s1, char *s2);
void				*safe_malloc(size_t size);
void				print_error(char *message);
void				*safe_calloc(size_t size, size_t count);
void				*safe_empty(size_t size, size_t count);

// map.c //
void				read_map(char *file, t_game *game);

// build.c //
int					start_game(t_game *game);

#endif