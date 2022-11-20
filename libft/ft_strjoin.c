/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:45:16 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/19 21:17:00 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	size_t	l1;
	size_t	l2;

	if (s1 && s2)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		t = (char *)malloc(sizeof(char) * (l1 + l2) + 1);
		if (!t)
			return (NULL);
		ft_memmove(t, s1, l1);
		ft_memmove(t + l1, s2, l2);
		t[l1 + l2] = '\0';
		return (t);
	}
	t = NULL;
	return (t);
}
