/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:18:15 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/22 23:48:44 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char const *s, char c)
{
	int	p;
	int	cnt;

	p = 0;
	cnt = 0;
	if (s[p] == c)
		cnt--;
	while (s[p] != '\0')
	{
		if (s[p] == c && s[p + 1] != c && s[p + 1] != '\0')
			cnt++;
		p++;
	}
	cnt++;
	return (cnt);
}

static char	*malloc_str(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	str_free(char **tab, int i)
{
	int	j;

	j = i;
	while (i--)
		free(tab[i]);
	while (j--)
		tab[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = malloc_str(s, c);
			if (tab[i] == NULL)
				str_free(tab, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
