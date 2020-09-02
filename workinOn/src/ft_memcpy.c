/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:34:11 by pmartins          #+#    #+#             */
/*   Updated: 2020/02/12 15:00:13 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*ptr;
	unsigned const char		*aux;
	unsigned int			i;

	if ((src == NULL) && (dest == NULL))
		return (NULL);
	ptr = dest;
	aux = src;
	i = 0;
	while (n)
	{
		ptr[i] = aux[i];
		i++;
		n--;
	}
	return (ptr);
}
