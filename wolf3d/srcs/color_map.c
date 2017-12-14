/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 02:30:45 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 15:30:42 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				color_address(unsigned char *ptr, t_color col, t_image *pic)
{
	int		dec;

	dec = col.opp;
	while (dec--)
		if (pic->endian1 == pic->local_endian)
		{
			if (pic->endian1)
				*(ptr + col.cnt.x * col.opp + dec) =
					((unsigned char *)(&col.color_val))[4 - col.opp + dec];
			else
				*(ptr + col.cnt.x * col.opp + dec) =
					((unsigned char *)(&col.color_val))[dec];
		}
		else
		{
			if (pic->endian1)
				*(ptr + col.cnt.x * col.opp + dec) =
					((unsigned char *)(&col.color_val))[col.opp - 1 - dec];
			else
				*(ptr + col.cnt.x * col.opp + dec) =
					((unsigned char *)(&col.color_val))[3 - dec];
		}
	return (1);
}

int				color_map_1(t_image *pic, t_env display)
{
	t_color			color;
	unsigned char	*ptr;

	color.opp = pic->bpp1 / 8;
	color.cnt.y = display.draw_end - display.draw_start;
	while (color.cnt.y--)
	{
		ptr = (unsigned char*)(pic->data1 + color.cnt.y * pic->sl1);
		color.cnt.x = 1;
		while (color.cnt.x--)
		{
			color.color_val = color_1();
			color_address(ptr, color, pic);
		}
	}
	return (1);
}

int				color_map_2(t_image *pic, t_env display)
{
	t_color			color;
	unsigned char	*ptr;
	int				sky;

	sky = 0;
	color.opp = pic->bpp1 / 8;
	color.cnt.y = display.draw_end - display.draw_start;
	while (color.cnt.y--)
	{
		ptr = (unsigned char*)(pic->data1 + color.cnt.y * pic->sl1);
		color.cnt.x = 1;
		while (color.cnt.x--)
		{
			color.color_val = color_2();
			if (display.side == 1)
			{
				color.color_val = color.color_val / 2;
			}
			color_address(ptr, color, pic);
		}
	}
	return (1);
}

int				color_map_3(t_image *pic, t_env display)
{
	t_color			color;
	unsigned char	*ptr;

	color.opp = pic->bpp1 / 8;
	color.cnt.y = display.draw_end - display.draw_start;
	while (color.cnt.y--)
	{
		ptr = (unsigned char*)(pic->data1 + color.cnt.y * pic->sl1);
		color.cnt.x = 1;
		while (color.cnt.x--)
		{
			color.color_val = color_3();
			if (display.side == 1)
			{
				color.color_val = color.color_val / 2;
			}
			color_address(ptr, color, pic);
		}
	}
	return (1);
}

int				color_map_4(t_image *pic, t_env display)
{
	t_color			color;
	unsigned char	*ptr;

	color.opp = pic->bpp1 / 8;
	color.cnt.y = display.draw_end - display.draw_start;
	while (color.cnt.y--)
	{
		ptr = (unsigned char*)(pic->data1 + color.cnt.y * pic->sl1);
		color.cnt.x = 1;
		while (color.cnt.x--)
		{
			color.color_val = color_4();
			if (display.side == 1)
			{
				color.color_val = color.color_val / 2;
			}
			color_address(ptr, color, pic);
		}
	}
	return (1);
}
