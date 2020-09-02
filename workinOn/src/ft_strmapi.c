/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:35:26 by pmartins          #+#    #+#             */
/*   Updated: 2020/03/03 17:25:37 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*post;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen((char*)s);
	if (!(post = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	post[len] = '\0';
	while (s[i] != '\0')
	{
		post[i] = f(i, s[i]);
		i++;
	}
	return (post);
}
