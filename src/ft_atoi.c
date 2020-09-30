/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:59:07 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/12 21:27:33 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int i;
	int sinal;
	int numero;

	i = 0;
	sinal = 1;
	numero = 0;
	while ((str[i] == ' ' || str[i] == '\t') || (str[i] == '\n') \
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numero = numero * 10 + (str[i] - '0');
		i++;
	}
	return (sinal * numero);
}
