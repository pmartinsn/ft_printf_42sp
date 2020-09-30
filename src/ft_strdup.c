/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:23:23 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/13 12:20:51 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = ft_strlen((char*)src);
	if (!(ptr = malloc(sizeof(char) * i + 1)))
		return (0);
	while (j < i)
	{
		ptr[j] = src[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
