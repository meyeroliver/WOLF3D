/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 12:06:30 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 15:40:54 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char		*valid_map(char *filename)
{
	if (ft_strcmp(filename, "map0.txt"))
		return (filename);
	else if (ft_strcmp(filename, "map1.txt"))
		return (filename);
	else
		return (NULL);
}

t_vec_i		get_map_size(int fd)
{
	t_vec_i		size;
	int			flag;
	char		*line;

	flag = 0;
	size.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (flag == 0)
		{
			size.x = 0;
			while (*line)
				if (*line++ != ',')
					size.x++;
			flag = 1;
		}
		size.y++;
	}
	free(line);
	return (size);
}

void		allocate_map(int ***map, t_vec_i size)
{
	int		i;

	i = 0;
	(*map) = (int**)(malloc(sizeof(int*) * (size.y + 1)));
	while (i < (int)size.y)
	{
		(*map)[i] = (int*)(malloc(sizeof(int) * (size.x + 1)));
		i++;
	}
}

void		populate_map(int ***map, t_vec_i size, int fd)
{
	t_vec_i	cnt;
	char	**split;
	char	*line;

	cnt.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		cnt.x = 0;
		split = ft_strsplit(line, ',');
		while (cnt.x < size.x)
		{
			(*map)[cnt.y][cnt.x] = ft_atoi(split[cnt.x]);
			cnt.x++;
		}
		cnt.y++;
	}
	free(line);
}
