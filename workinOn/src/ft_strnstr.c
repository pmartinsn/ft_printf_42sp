/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:05:43 by pmartins          #+#    #+#             */
/*   Updated: 2020/03/03 17:27:24 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strnstr(const char *hays, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!*needle)
		return ((char *)&hays[i]);
	while ((hays[i] != '\0') && (i < len))
	{
		j = 0;
		while (hays[i] == needle[j])
		{
			while (hays[i] && (hays[i] == needle[j])
			&& (j < nb_strlen((char *)needle)) && (i < len))
			{
				i++;
				j++;
				if (needle[j] == '\0')
					return ((char *)&hays[i - j]);
			}
			j = 0;
			i++;
		}
		i++;
	}
	return (0);
}
