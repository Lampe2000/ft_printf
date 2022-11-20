/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:06:28 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/22 21:50:35 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	ls;
	size_t	ld;

	if (s == 0 && dst == 0)
		return (0);
	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	i = 0;
	if (!s)
		return (ls);
	while (src[i] && ld + i < s - 1)
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	if (ld > s)
		return (ls + s);
	return (ls + ld);
}
