/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:38:14 by pmartins          #+#    #+#             */
/*   Updated: 2020/03/02 14:23:50 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s1;
	char	*aux;

	s1 = (char*)src;
	aux = (char*)dest;
	if (src < dest)
	{
		while (len--)
			aux[len] = s1[len];
	}
	else
	{
		ft_memcpy(aux, s1, len);
	}
	return (dest);
}
