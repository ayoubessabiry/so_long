/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:40:49 by aessabir          #+#    #+#             */
/*   Updated: 2022/02/05 14:14:19 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_map(t_map *map, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img, x, y);
	if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->img_s, x, y);
	if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img_h, x, y);
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_n, x, y);
	if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->img_e, x, y);
	if (c == 'X')
		mlx_put_image_to_window(map->mlx, map->win, map->img_o, x, y);
}

int	check_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->heigh)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->s[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	draw(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < map->heigh)
	{
		x = 0;
		j = 0;
		while (j < map->width)
		{
			if (check_c(map) && map->s[i][j] == 'E')
				map->s[i][j] = 'X';
			put_map(map, map->s[i][j], x, y);
			x += 50;
			j++;
		}
		y += 50;
		i++;
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(1);
	}	
	if (keycode == 2)
		right(map);
	if (keycode == 0)
		left(map);
	if (keycode == 1)
		down(map);
	if (keycode == 13)
		up(map);
	return (0);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	map->w_path = "./xpm_files/w.xpm";
	map->s_path = "./xpm_files/s.xpm";
	map->e_path = "./xpm_files/E.xpm";
	map->h_path = "./xpm_files/h.xpm";
	map->n_path = "./xpm_files/n.xpm";
	map->o_path = "./xpm_files/O.xpm";
	map->mlx = mlx_init();
	map->img = mlx_xpm_file_to_image(map->mlx, map->w_path, &x, &y);
	map->img_h = mlx_xpm_file_to_image(map->mlx, map->h_path, &x, &y);
	map->img_s = mlx_xpm_file_to_image(map->mlx, map->s_path, &x, &y);
	map->img_n = mlx_xpm_file_to_image(map->mlx, map->n_path, &x, &y);
	map->img_e = mlx_xpm_file_to_image(map->mlx, map->e_path, &x, &y);
	map->img_o = mlx_xpm_file_to_image(map->mlx, map->o_path, &x, &y);
	map->win = mlx_new_window(map->mlx, x * map->width, y * map->heigh, "m");
	draw(map);
	mlx_key_hook(map->win, key_hook, map);
	mlx_hook(map->win, 17, 0, tclose, map);
	mlx_loop(map->mlx);
}
