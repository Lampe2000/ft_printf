/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:59:58 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/20 02:53:45 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrlen(unsigned int c)
{
	int	i;

	i = 0;
	while (c > 0)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

int	ft_array(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_array("(null)"));
	while (str[len] != '\0')
		len += ft_putchars(str[len]);
	return (len);
}

int	hexlen(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = (nbr / 16);
		i++;
	}
	return (i);
}

int	ft_putchars(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_uitoa(unsigned int n)
{
	int			len;
	char		*str;

	len = nbrlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (n == 0)
	{
		free(str);
		return (write(1, "0", 1));
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	len = ft_array(str);
	free(str);
	return (len);
}
