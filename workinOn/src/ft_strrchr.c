/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:02:01 by pmartins          #+#    #+#             */
/*   Updated: 2020/02/27 09:42:00 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buff;
	int		i;

	i = 0;
	buff = (char*)s;
	while (buff[i] != '\0')
	{
		i++;
	}
	if ((char)c == '\0')
		return (&buff[i]);
	while (i >= 0)
	{
		if (buff[i] == (char)c)
		{
			return (&buff[i]);
		}
		i--;
	}
	return (0);
}
