/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 07:28:43 by omeyer            #+#    #+#             */
/*   Updated: 2017/12/13 13:14:44 by omeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc - 1 == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr(argv[1]);
			ft_putstr("  does not exist. Please insert a valid filname\n");
			return (-1);
		}
		else
		{
			wolf3d(argv[1]);
		}
	}
	else
	{
		ft_putendl("Please insert only one map");
	}
}
