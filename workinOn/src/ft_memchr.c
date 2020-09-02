/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:38:15 by pmartins          #+#    #+#             */
/*   Updated: 2020/02/12 18:44:24 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	int				i;

	i = 0;
	buff = (unsigned char*)s;
	while (n)
	{
		if (buff[i] == (unsigned char)c)
			return (&buff[i]);
		i++;
		n--;
	}
	return (NULL);
}
