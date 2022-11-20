/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:49 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/20 05:58:18 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_printer(unsigned long n)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ptr_printer(n / 16);
		ptr_printer(n % 16);
	}
	else
		ft_putchars(a[n]);
	free(a);
	return (0);
}

int	ptr_print(unsigned long n)
{
	int	i;

	i = 1;
	ft_putchars('0');
	ft_putchars('x');
	ptr_printer(n);
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 2);
}

int	hexfunc(unsigned int nbr, char c)
{
	char			*str;
	int				len;
	char			*d;
	int				i;

	if (c == 'X')
		d = "0123456789ABCDEF";
	else
		d = "0123456789abcdef";
	len = hexlen(nbr);
	i = len;
	str = calloc(len, 1);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return(len);
	}
	while (nbr > 0)
	{
		str[--i] = d[nbr % 16];
		nbr = nbr / 16;
	}
	str[len] = '\0';
	ft_array(str);
	free(str);
	return (len);
}

int	printing(va_list liste, int c)
{
	char	*a;
	int		i;

	i = 0;
	if (c == 'c')
		i += ft_putchars(va_arg(liste, int));
	else if (c == 'd' || c == 'i')
	{
		a = ft_itoa(va_arg(liste, int));
		i += ft_array(a);
		free(a);
	}
	else if (c == 's')
		i += ft_array(va_arg(liste, char *));
	else if (c == 'p')
		i += ptr_print(va_arg(liste, unsigned long));
	else if (c == 'x' || c == 'X')
		i += hexfunc(va_arg(liste, unsigned int), c);
	else if (c == 'u')
		i += ft_uitoa(va_arg(liste, unsigned int));
	else if (c == '%')
		i += ft_putchars('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	liste;
	int		i;
	int		len;

	va_start(liste, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += printing(liste, str[i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(liste);
	return (len);
}
// int main()
// {
// 	ft_printf("%x", 0);
// 	ft_printf("%X", 0);
// }
