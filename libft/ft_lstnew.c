/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:50:02 by hmisbah           #+#    #+#             */
/*   Updated: 2022/10/19 21:14:41 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nw;

	nw = (t_list *)malloc(sizeof(*nw));
	if (!nw)
		return (NULL);
	nw -> content = content;
	nw -> next = NULL;
	return (nw);
}
