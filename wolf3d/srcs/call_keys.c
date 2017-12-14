/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 03:39:07 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 15:29:52 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	left_key(t_env *update, double *old_dir_x, double *old_plane_x)
{
	*old_dir_x = (*update->player)->dir.x;
	(*update->player)->dir.x = (*update->player)->dir.x * cos(ROTATE) -
		(*update->player)->dir.y * sin(-ROTATE);
	(*update->player)->dir.y = *old_dir_x * sin(-ROTATE) +
		(*update->player)->dir.y * cos(-ROTATE);
	*old_plane_x = (*update->player)->p_plane.x;
	(*update->player)->p_plane.x = (*update->player)->p_plane.x *
		cos(-ROTATE) - (*update->player)->p_plane.y * sin(-ROTATE);
	(*update->player)->p_plane.y = *old_plane_x * sin(-ROTATE) +
		(*update->player)->p_plane.y * cos(-ROTATE);
}

void	right_key(t_env *update, double *old_dir_x, double *old_plane_x)
{
	*old_dir_x = (*update->player)->dir.x;
	(*update->player)->dir.x = (*update->player)->dir.x * cos(ROTATE) -
		(*update->player)->dir.y * sin(ROTATE);
	(*update->player)->dir.y = *old_dir_x * sin(ROTATE) +
		(*update->player)->dir.y * cos(ROTATE);
	*old_plane_x = (*update->player)->p_plane.x;
	(*update->player)->p_plane.x = (*update->player)->p_plane.x *
		cos(ROTATE) - (*update->player)->p_plane.y * sin(ROTATE);
	(*update->player)->p_plane.y = *old_plane_x * sin(ROTATE) +
		(*update->player)->p_plane.y * cos(ROTATE);
}

void	up_key(t_env *update)
{
	if ((*update).map[(int)((*update->player)->pos.x +
				(*update->player)->dir.x *
				VELOCITY)][(int)(*update->player)->pos.y] != 1)
		(*update->player)->pos.x += (*update->player)->dir.x * VELOCITY;
	if ((*update).map[(int)(*update->player)->pos.x]
			[(int)((*update->player)->pos.y +
				(*update->player)->dir.y * VELOCITY)] != 1)
		(*update->player)->pos.y += (*update->player)->dir.y * VELOCITY;
}

void	down_key(t_env *update)
{
	if ((*update).map[(int)((*update->player)->pos.x -
				(*update->player)->dir.x * VELOCITY)]
			[(int)(*update->player)->pos.y] == 0)
		(*update->player)->pos.x -= (*update->player)->dir.x * VELOCITY;
	if ((*update).map[(int)((*update->player)->pos.x)]
			[(int)((*update->player)->pos.y -
				(*update->player)->dir.y * VELOCITY)] == 0)
		(*update->player)->pos.y -= (*update->player)->dir.y * VELOCITY;
}
