/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:54:51 by pmartins          #+#    #+#             */
/*   Updated: 2020/03/02 14:24:52 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *ptr;
	char d;

	ptr = b;
	d = (unsigned char)c;
	if ((!b) && (!c))
		return (0);
	while (len)
	{
		*ptr = d;
		ptr++;
		len--;
	}
	return (b);
}
