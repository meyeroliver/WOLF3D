/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 13:14:45 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 13:43:36 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_dda_1(t_dda **dda, t_ray *ray)
{
	(*dda) = (t_dda*)(malloc(sizeof(t_dda)));
	(*dda)->map_pos.x = (ray)->pos.x;
	(*dda)->map_pos.y = (ray)->pos.y;
	(*dda)->delta_dist.x = sqrt(1 + pow((ray)->dir.y, 2)
			/ pow((ray)->dir.x, 2));
	(*dda)->delta_dist.y = sqrt(1 + pow((ray)->dir.x, 2)
			/ pow((ray)->dir.y, 2));
	(*dda)->hit = 0;
}

void		init_dda(t_dda **dda, t_ray *ray)
{
	init_dda_1(dda, ray);
	if ((ray)->dir.x < 0)
	{
		(*dda)->step.x = -1;
		(*dda)->side_dist.x = ((ray)->pos.x - (*dda)->map_pos.x)
			* (*dda)->delta_dist.x;
	}
	else
	{
		(*dda)->step.x = 1;
		(*dda)->side_dist.x = ((*dda)->map_pos.x + 1 - (ray)->pos.x)
			* (*dda)->delta_dist.x;
	}
	if ((ray)->dir.y < 0)
	{
		(*dda)->step.y = -1;
		(*dda)->side_dist.y = ((ray)->pos.y - (*dda)->map_pos.y)
			* (*dda)->delta_dist.y;
	}
	else
	{
		(*dda)->step.y = 1;
		(*dda)->side_dist.y = ((*dda)->map_pos.y + 1 - (ray)->pos.y)
			* (*dda)->delta_dist.y;
	}
}

int			perform_dda(t_dda **dda, int **map, t_env *display)
{
	if ((*dda)->side_dist.x < (*dda)->side_dist.y)
	{
		(*dda)->side_dist.x += (*dda)->delta_dist.x;
		(*dda)->map_pos.x += (*dda)->step.x;
		(*display).side = 0;
	}
	else
	{
		(*dda)->side_dist.y += (*dda)->delta_dist.y;
		(*dda)->map_pos.y += (*dda)->step.y;
		(*display).side = 1;
	}
	if (map[(*dda)->map_pos.y][(*dda)->map_pos.x] > 0)
	{
		(*dda)->hit = 1;
	}
	return ((*dda)->hit);
}
