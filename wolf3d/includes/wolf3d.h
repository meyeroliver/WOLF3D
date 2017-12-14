/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 07:46:51 by omeyer            #+#    #+#             */
/*   Updated: 2017/10/15 15:10:24 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define H_SCREEN	400
# define W_SCREEN	600
# define IM1_SX		600
# define IM1_SY		400
# define VELOCITY	0.3
# define ROTATE		0.1

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <time.h>

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vec_d;

typedef struct	s_vector_i
{
	int			x;
	int			y;
}				t_vec_i;

typedef struct	s_player
{
	t_vec_d		pos;
	t_vec_d		dir;
	t_vec_d		p_plane;
}				t_player;

typedef struct	s_ray
{
	t_vec_d		pos;
	t_vec_d		dir;
}				t_ray;

typedef	struct	s_dda
{
	t_vec_i		map_pos;
	t_vec_d		side_dist;
	t_vec_d		delta_dist;
	double		perp_wall_dist;
	t_vec_i		step;
	int			hit;
}				t_dda;

typedef struct	s_image
{
	char		*data1;
	int			endian1;
	int			bpp1;
	int			sl1;
	int			local_endian;
	double		cam_x;
}				t_image;

typedef struct	s_color
{
	t_vec_i		cnt;
	int			opp;
	int			color_val;
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_player	**player;
	int			**map;
	int			x;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			side;
	void		*im1;
}				t_env;

void			wolf3d(char *filename);

char			*valid_map(char *filename);
t_vec_i			get_map_size(int fd);
void			allocate_map(int ***map, t_vec_i size);
void			populate_map(int ***map, t_vec_i size, int fd);

void			init_player(t_player **player);
t_ray			*get_ray(t_player *player, double cam_x);

void			init_dda(t_dda **dda, t_ray *ray);
int				perform_dda(t_dda **dda, int **map, t_env *display);
void			draw_world(t_player **player, int **map);
void			update_world(t_env *display);
void			find_wall(t_dda **dda, t_ray *ray, t_env *display);

int				color_1(void);
int				color_2(void);
int				color_3(void);
int				color_4(void);

int				color_map_1(t_image *pic, t_env display);
int				color_map_2(t_image *pic, t_env display);
int				color_map_3(t_image *pic, t_env display);
int				color_map_4(t_image *pic, t_env display);
int				color_address(unsigned char *ptr, t_color col, t_image *pic);
void			call_map_color(t_env *display, t_image *p, t_dda *dda);

void			left_key(t_env *update, double *old_dir_x, double *old_plane_x);
void			right_key(t_env *update, double *old_dir_x,
				double *old_plane_x);
void			up_key(t_env *update);
void			down_key(t_env *update);

void			call_endian(t_image *p);

#endif
