/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:44:06 by pmartins          #+#    #+#             */
/*   Updated: 2020/02/13 11:31:23 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ax1;
	unsigned char		*ax2;
	unsigned int		i;

	ax1 = (unsigned char*)s1;
	ax2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (ax1[i] == '\0' && ax2[i] == '\0')
		return (0);
	while ((ax1[i] == ax2[i]) && n-- > 0)
	{
		i++;
		if (n == 0)
			return (0);
	}
	if (ax1[i] != ax2[i])
		return (ax1[i] - ax2[i]);
	return (0);
}
