/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:30:00 by mmpofu            #+#    #+#             */
/*   Updated: 2017/08/16 18:52:10 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != 0)
		{
			i++;
			if (s1[i] != s2[i])
				return (0);
		}
		return (1);
	}
	return (0);
}