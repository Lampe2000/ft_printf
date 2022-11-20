/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:37:27 by ysensoy           #+#    #+#             */
/*   Updated: 2022/11/20 03:19:46 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	    nbrlen(unsigned int c);
int	    hexlen(unsigned int nbr);
int	    ft_putchars(char c);
int	    hexfunc(unsigned int nbr, char c);
int	    printing(va_list liste, int c);
int	    ft_printf(const char *str, ...);
int	    ft_uitoa(unsigned int n);
int	    ft_array(char *str);
int	    ptr_printer(unsigned long n);
int	    ptr_print(unsigned long n);

#endif
