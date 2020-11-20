/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:23:23 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/19 16:17:51 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = ft_strlen((char*)src);
	if (!(ptr = ft_calloc(i + 1, sizeof(char))))
		return (0);
	while (j < i)
	{
		ptr[j] = src[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
