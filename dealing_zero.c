/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:17:10 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 17:46:35 by pmartins         ###   ########.fr       */
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
	if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux + 1;
			p_int_wid_zero(&*star);
			print_while(fmt, &*aux, &*star);
		}
	}
	tobeconv = malloc(malloc_index(fmt, &*aux));
	tobeconv = converter(tobeconv, fmt, &*aux);
	e_zhalf(tobeconv, fmt, &*aux, &*star);
	dea_zero_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

void	e_zhalf(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	if ((fmt[*aux] == '0') || (fmt[*aux] == '-'))
	{
		if (fmt[*aux] == '-')
		{
			*aux = *aux + 1;
			dealing_minus(fmt, &*aux, &*star);
			print_while(fmt, &*aux, &*star);
		}
		ft_jumpzero(fmt, &*aux);
		if (fmt[*aux] == 's')
		{
			*aux = *aux + 1;
			print_s_noflag(&*star);
			print_while(fmt, &*aux, &*star);
		}
	}
}

void	dea_zero_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	e_dztwo(tobeconv, fmt, &*aux, &*star);
	if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		if (fmt[*aux] == '0')
			d_pre_zer(tobeconv, fmt, &*aux, &*star);
		if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
			e_zeronb(tobeconv, fmt, &*aux, &*star);
		else
		{
			*aux = *aux + 1;
			pri_nbr_pre(tobeconv, &*star);
		}
		print_while(fmt, &*aux, &*star);
	}
}

void	e_zeronb(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	char	*tbvv;

	tbvv = malloc(malloc_index(fmt, &*aux));
	tbvv = converter(tbvv, fmt, &*aux);
	if (fmt[*aux] == 's')
		pri_pre_wnbr(tobeconv, tbvv, &*star);
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		p_nbr_pre_i(tobeconv, tbvv, &*star);
	else if (fmt[*aux] == 'u')
		pri_pre_u_wnbr(tobeconv, tbvv, &*star);
	else if (fmt[*aux] == 'x')
		pri_pre_x_wnbr(tobeconv, tbvv, &*star);
	else if (fmt[*aux] == 'X')
		pri_pre_xx_wnbr(tobeconv, tbvv, &*star);
	*aux = *aux + 1;
	free(tbvv);
}

void	e_dztwo(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
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
