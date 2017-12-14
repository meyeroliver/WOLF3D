/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 11:55:38 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 13:55:16 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d(char *filename)
{
	t_vec_i		size;
	int			**map;
	int			fd;
	t_player	*player;

	if (valid_map(filename))
	{
		fd = open(filename, O_RDONLY);
		size = get_map_size(fd);
		close(fd);
		allocate_map(&map, size);
		fd = open(filename, O_RDONLY);
		populate_map(&map, size, fd);
		close(fd);
		init_player(&player);
		draw_world(&player, map);
	}
	else
		ft_putendl("Incorrect map. \nPlease insert a valid map");
}
