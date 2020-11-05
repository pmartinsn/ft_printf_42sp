/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_pre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:43:01 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/05 09:49:03 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_precision(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'u')
	| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))
		no_flags(fmt, &*aux, &*star);
	tobeconv = malloc(malloc_index(fmt, &*aux));
	tobeconv = converter(tobeconv, fmt, &*aux);
	if ((fmt[*aux] == '0') | (fmt[*aux + 1] == 's'))
		*aux = *aux + 2;
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_pre(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_preci_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

void	dealing_preci_two(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_preci_three(tbv, fmt, &*aux, &*star);
}

void	dealing_preci_three(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}
