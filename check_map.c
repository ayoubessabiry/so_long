/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:55:14 by aessabir          #+#    #+#             */
/*   Updated: 2021/12/15 15:23:14 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(char c)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		return (0);
	return (1);
}

int	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->heigh)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->s[0][j] != '1' || map->s[map->heigh - 1][j] != '1' ||
			map->s[i][0] != '1' || map->s[i][map->width - 1] != '1')
				return (0);
			else if (!check(map->s[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	at_least(t_map *map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->heigh)
	{
		j = 0;
		while (j < map->width)
		{
			if (c == map->s[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	only_p(t_map *map)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while (i < map->heigh)
	{
		j = 0;
		while (j < map->width)
		{
			if ('P' == map->s[i][j] && f == 0)
			{
				f = 1;
				map->p_i = i;
				map->p_j = j;
			}	
			else if ('P' == map->s[i][j] && f == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_map *map)
{
	if (!check_wall(map))
		ft_error("map not valid");
	if (!(at_least(map, 'E')) || !(at_least(map, 'C')) || !(at_least(map, 'P')))
		ft_error("map not valid");
	if (!only_p(map))
		ft_error("map not valid");
}
