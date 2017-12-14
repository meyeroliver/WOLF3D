/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 12:47:16 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 14:19:36 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_player(t_player **player)
{
	*player = (t_player*)(malloc(sizeof(t_player)));
	(*player)->pos.x = 12;
	(*player)->pos.y = 12;
	(*player)->dir.x = 1;
	(*player)->dir.y = 0;
	(*player)->p_plane.x = 0;
	(*player)->p_plane.y = 0.66;
}

t_ray	*get_ray(t_player *player, double cam_x)
{
	t_ray	*ray;

	ray = (t_ray*)(malloc(sizeof(t_ray)));
	(ray)->pos.x = (player)->pos.x;
	(ray)->pos.y = (player)->pos.y;
	(ray)->dir.x = (player)->dir.x + (player)->p_plane.x * cam_x;
	(ray)->dir.y = (player)->dir.y + (player)->p_plane.y * cam_x;
	return (ray);
}
