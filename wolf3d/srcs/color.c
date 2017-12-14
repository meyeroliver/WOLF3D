/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:19:34 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 15:13:44 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				color_1(void)
{
	int		color;

	color = 0xf44336;
	return (color);
}

int				color_2(void)
{
	int		color;

	color = 0xFFEE58;
	return (color);
}

int				color_3(void)
{
	int		color;

	color = 0x2196F3;
	return (color);
}

int				color_4(void)
{
	int		color;

	color = 0x9C27B0;
	return (color);
}

void			call_map_color(t_env *display, t_image *p, t_dda *dda)
{
	if (display->map[dda->map_pos.y][dda->map_pos.x] == 1)
		color_map_1(p, *display);
	if (display->map[dda->map_pos.y][dda->map_pos.x] == 2)
		color_map_2(p, *display);
	if (display->map[dda->map_pos.y][dda->map_pos.x] == 3)
		color_map_3(p, *display);
	if (display->map[dda->map_pos.y][dda->map_pos.x] == 4)
		color_map_4(p, *display);
}
