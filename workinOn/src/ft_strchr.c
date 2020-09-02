/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:06:44 by pmartins          #+#    #+#             */
/*   Updated: 2020/02/13 15:39:17 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buff;
	int		i;

	i = 0;
	buff = (char*)s;
	while (buff[i] != '\0')
	{
		if (buff[i] == c)
			return ((char*)&buff[i]);
		i++;
	}
	if (c == '\0')
		return ((char*)&buff[i]);
	return (0);
}
