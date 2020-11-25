/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:11:54 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/25 20:11:14 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

static int		get_return_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n >= 10)
	{
		n /= 10;
		++len;
	}
	return (len + 1);
}

char				*ft_itoa_u(unsigned int n, int base/*, char updown*/)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	len;

	nb = n;
	len = (unsigned int)get_return_len(nb);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = len - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % base + 48);
		nb /= 10;
	}
	str[i] = (char)(nb % base + 48);
	str[len] = '\0';
	return (str);
	/*unsigned int	cont_num;
	unsigned int	aux;
	char			*str;

	aux = nb;
	cont_num = (unsigned int)get_return_len(nb);
	
	while ((aux = aux / base) > 0)
		cont_num++;
	str = (char *)ft_calloc((cont_num + 1), sizeof(char));
	if (!str)
		return (NULL);
	str[cont_num--] = '\0';
	cont_num = len -1;
	while (aux >= 0)
	{
		if ((nb % base) < 10)
			str[cont_num] = (nb % base) + '0';
		else
			str[cont_num] = (nb % base) + updown - 10;
		nb = nb / base;
		cont_num--;
	}
	return (str);*/
}