/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:25:06 by aessabir          #+#    #+#             */
/*   Updated: 2021/12/16 17:08:47 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_map *map)
{
	if (map->s[map->p_i][map->p_j + 1] != '1' &&
		map->s[map->p_i][map->p_j + 1] != 'E')
	{
		printf("%d\n", map->count++);
		if (map->s[map->p_i][map->p_j + 1] == 'X')
			exit(1);
		mlx_clear_window(map->mlx, map->win);
		map->s[map->p_i][map->p_j] = '0';
		map->s[map->p_i][map->p_j + 1] = 'P';
		map->p_j += 1;
		draw(map);
	}
}

void	left(t_map *map)
{
	if (map->s[map->p_i][map->p_j - 1] != '1' &&
		map->s[map->p_i][map->p_j - 1] != 'E')
	{
		printf("%d\n", map->count++);
		if (map->s[map->p_i][map->p_j - 1] == 'X')
			exit(1);
		mlx_clear_window(map->mlx, map->win);
		map->s[map->p_i][map->p_j] = '0';
		map->s[map->p_i][map->p_j - 1] = 'P';
		map->p_j -= 1;
		draw(map);
	}
}

void	down(t_map *map)
{
	if (map->s[map->p_i + 1][map->p_j] != '1' &&
		map->s[map->p_i + 1][map->p_j] != 'E')
	{
		printf("%d\n", map->count++);
		if (map->s[map->p_i + 1][map->p_j] == 'X')
			exit(1);
		mlx_clear_window(map->mlx, map->win);
		map->s[map->p_i][map->p_j] = '0';
		map->s[map->p_i + 1][map->p_j] = 'P';
		map->p_i += 1;
		draw(map);
	}
}

void	up(t_map *map)
{
	if (map->s[map->p_i - 1][map->p_j] != '1' &&
		map->s[map->p_i - 1][map->p_j] != 'E')
	{
		printf("%d\n", map->count++);
		if (map->s[map->p_i - 1][map->p_j] == 'X')
			exit(1);
		mlx_clear_window(map->mlx, map->win);
		map->s[map->p_i][map->p_j] = '0';
		map->s[map->p_i - 1][map->p_j] = 'P';
		map->p_i -= 1;
		draw(map);
	}
}

int	tclose(void)
{
	exit (1);
	return (0);
}
