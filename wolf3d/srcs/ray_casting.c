/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:46:48 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 15:41:18 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	free_draw(t_ray **ray, t_dda **dda)
{
	free(*ray);
	free(*dda);
}

void		find_wall(t_dda **dda, t_ray *ray, t_env *display)
{
	(*dda)->hit = 0;
	while ((*dda)->hit == 0)
		perform_dda(dda, display->map, display);
	if ((*display).side == 0)
		(*dda)->perp_wall_dist = ((*dda)->map_pos.x - ray->pos.x + (1 -
					(*dda)->step.x) / 2) / ray->dir.x;
	else
		(*dda)->perp_wall_dist = ((*dda)->map_pos.y - ray->pos.y + (1 -
					(*dda)->step.y) / 2) / ray->dir.y;
	(*display).line_height = (int)(H_SCREEN / (*dda)->perp_wall_dist);
	(*display).draw_start = -((*display).line_height) / 2 + H_SCREEN / 2;
	if ((*display).draw_start < 0)
		(*display).draw_start = 0;
	(*display).draw_end = ((*display).line_height / 2) + (H_SCREEN / 2);
	if ((*display).draw_end >= H_SCREEN)
		(*display).draw_end = H_SCREEN - 1;
}

void		update_world(t_env *display)
{
	t_ray		*ray;
	t_image		*p;
	t_dda		*dda;

	p = (t_image*)malloc(sizeof(t_image) * 1);
	call_endian(p);
	display->x = 0;
	while (display->x < W_SCREEN)
	{
		display->im1 = mlx_new_image(display->mlx, IM1_SX, IM1_SY);
		p->data1 = mlx_get_data_addr(display->im1, &p->bpp1,
				&p->sl1, &p->endian1);
		p->cam_x = 2 * display->x / (double)(W_SCREEN) - 1;
		ray = get_ray(*(*display).player, p->cam_x);
		init_dda(&dda, ray);
		find_wall(&dda, ray, display);
		call_map_color(display, p, dda);
		mlx_put_image_to_window(display->mlx, display->win, display->im1,
				display->x, display->draw_start);
		mlx_destroy_image(display->mlx, display->im1);
		display->x++;
		free_draw(&ray, &dda);
	}
	free(p);
}

int			key_event(int key_pressed, t_env *update)
{
	double	old_dir_x;
	double	old_plane_x;
	int		x;

	x = 0;
	if (key_pressed == 53)
	{
		exit(0);
		free(update->player);
		while (x < 24)
			free(update->map[x++]);
		free(update->map);
	}
	if (key_pressed == 123)
		left_key(update, &old_dir_x, &old_plane_x);
	if (key_pressed == 124)
		right_key(update, &old_dir_x, &old_plane_x);
	if (key_pressed == 125)
		down_key(update);
	if (key_pressed == 126)
		up_key(update);
	mlx_clear_window(update->mlx, update->win);
	update_world(update);
	return (0);
}

void		draw_world(t_player **player, int **map)
{
	t_env		display;

	display.player = player;
	display.map = map;
	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx, W_SCREEN, H_SCREEN, "WOLF3D");
	mlx_clear_window(display.mlx, display.win);
	update_world(&display);
	mlx_key_hook(display.win, key_event, &display);
	mlx_loop(display.mlx);
}
