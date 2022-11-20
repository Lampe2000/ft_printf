/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:27:06 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/21 23:53:05 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	res(char *str, int s, int i)
{
	long long		prev;
	long long		r;

	r = 0;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		prev = r;
		r = r * 10 + str[i] - 48;
		if (r / 10 != prev && s == 1)
			return (-1);
		else if (r / 10 != prev && s == -1)
			return (0);
		i++;
	}
	return (r * s);
}

int	ft_atoi(const char *st)
{
	int				i;
	int				s;
	char			*str;

	str = (char *)st;
	i = 0;
	s = 1;
	while (str[i] != '\0' && ((str[i] <= 13 && str[i] >= 9) || str[i] == ' '))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	return (res(str, s, i));
}
