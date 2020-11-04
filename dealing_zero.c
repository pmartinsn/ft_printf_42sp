/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:17:10 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/04 10:41:04 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_zero(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	tobeconv = malloc(*aux * 3);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'u')
	| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))
		no_flags(fmt, &*aux, &*star);
	tobeconv = converter(tobeconv, fmt, &*aux);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dea_zero_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

void	dea_zero_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		print_per_minwnbr(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}
