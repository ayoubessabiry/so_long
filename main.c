/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:00:04 by aessabir          #+#    #+#             */
/*   Updated: 2022/02/05 14:20:01 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	printf ("%s", s);
	exit (1);
}

void	map_size(char *av, t_map *map)
{
	int		fd;
	char	*s;

	fd = open(av, O_RDWR);
	if (fd < 0)
		ft_error("file does not exist!");
	s = get_next_line(fd);
	while (s != NULL)
	{
		map->heigh++;
		free(s);
		s = get_next_line(fd);
	}	
}

void	get_map(char *av, t_map *map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av, O_RDWR);
	map->s = malloc(sizeof(char *) * (map->heigh + 1));
	if (!map->s)
		return ;
	while (i <= map->heigh)
	{
		map->s[i] = get_next_line(fd);
		i++;
	}
	if (map->s[0] == NULL)
		ft_error("Emty file !!!");
	map->width = ft_strlen(map->s[0]) - 1;
	i = 0;
	while (i < map->heigh - 1)
	{
		if (ft_strlen(map->s[i]) - 1 != (map->width))
			ft_error("map not valid");
		i++;
	}
	if (ft_strlen(map->s[i]) != map->width)
		ft_error("map not valid");
}

void	check_ext(char *s)
{
	char	*p;
	char	*t;
	int		i;

	i = 0;
	t = ".ber";
	p = ft_strrchr(s, '.');
	if (p)
	{
		while (p[i] || t[i])
		{
			if (p[i] != t[i])
				ft_error("extension not valid!!");
			i++;
		}
	}
	else
		ft_error("extension not valid!!");
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		map.count = 1;
		check_ext(av[1]);
		map_size(av[1], &map);
		get_map(av[1], &map);
		check_map(&map);
		draw_map(&map);
	}
	ft_error("no file");
	return (0);
}
