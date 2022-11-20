/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:28:39 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/16 03:11:43 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *str, size_t s)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = ft_strlen(str);
	if (s == 0)
		return (j);
	while (str[i] != '\0' && i < (s - 1))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
