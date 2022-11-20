/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:15:32 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/25 03:39:25 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	isin(const char s, const char *set)
{
	while (*set != '\0')
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	sz_alloc(int len, const char *s, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = len - 1;
	while (s[i] && isin(s[i], set) == 1 && len > 1)
	{
		i++;
		len--;
	}
	while (s[j] && isin(s[j], set) == 1 && len > 1)
	{
		j--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	int		alloc;
	char	*str;

	if (!s1)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	alloc = sz_alloc(len, s1, set);
	str = malloc((alloc + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i] && isin(s1[i], set) == 1)
		i++;
	while (j < alloc)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
