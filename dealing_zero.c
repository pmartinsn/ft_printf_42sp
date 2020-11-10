/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:17:10 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/10 10:03:59 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_zero(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'u')
	| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))
		no_flags(fmt, &*aux, &*star);
	tobeconv = malloc(malloc_index(fmt, &*aux));
	tobeconv = converter(tobeconv, fmt, &*aux);
	if ((fmt[*aux] == '0'))
	{
		ft_jumpzero(fmt, &*aux);
		if (fmt[*aux] == 's')
		{
			*aux = *aux + 1;
			print_s_noflag(&*star);
			print_while(fmt, &*aux, &*star);
		}
	}
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
		pri_per_zerownbr(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	ft_jumpzero(const char *fmt, int *aux)
{
	while (fmt[*aux] == '0')
	{
		*aux = *aux + 1;
	}
}