/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:59:05 by aessabir          #+#    #+#             */
/*   Updated: 2021/12/16 14:54:16 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_map
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_s;
	void	*img_h;
	void	*img_n;
	void	*img_e;
	void	*img_o;
	char	*o_path;
	char	*w_path;
	char	*s_path;
	char	*h_path;
	char	*e_path;
	char	*n_path;
	int		img_width;
	int		img_height;
	int		width;
	int		heigh;
	int		p_i;
	int		p_j;
	int		x;
	int		y;
	int		count;
	char	**s;
}	t_map;
void	check_map(t_map *map);
void	ft_error(char *s);
void	map_size(char *av, t_map *map);
void	get_map(char *av, t_map *map);
void	draw_map(t_map *map);
void	check_ext(char *s);
void	free_p(t_map *map);
void	draw(t_map *map);
void	right(t_map *map);
void	left(t_map *map);
void	down(t_map *map);
void	up(t_map *map);
int		tclose(void);
#endif