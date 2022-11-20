/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:25:15 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/22 00:16:15 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*a;
	const char	*b;

	a = dest;
	b = src;
	if (a > b)
	{
		while (n--)
			a[n] = b[n];
	}
	else
		return (ft_memcpy(a, b, n));
	return (a);
}
