/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minus_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:48:38 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 16:50:47 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	e_checkminus(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		print_per_minwnbr(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	e_minuspre(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		pri_nbr_pre(tbv, &*star);
	}
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		p_int_pre_zero(tbv, &*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		pri_pre_u_wzero(tbv, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		pri_pre_x_wzero(tbv, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		pri_pre_xx_wzero(tbv, &*star);
	}
}

void	e_minuszero(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		pri_pre_u_wzero(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		pri_pre_x_wzero(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		pri_pre_xx_wzero(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		d_pre_zer(tbv, fmt, &*aux, &*star);
}

void	e_minuszerotwo(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		pri_nbr_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if ((fmt[*aux] == 'i') | (fmt[*aux] == 'd'))
	{
		*aux = *aux + 1;
		p_int_pre_zero(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	e_mnbr(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	char	*tbvv;

	tbvv = malloc(malloc_index(fmt, &*aux));
	tbvv = converter(tbvv, fmt, &*aux);
	if (fmt[*aux] == 's')
		pri_min_pre_wnbr(tbv, tbvv, &*star);
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		p_min_pre_i(tbv, tbvv, &*star);
	else if (fmt[*aux] == 'u')
		mim_pre_u_wnbr(tbv, tbvv, &*star);
	else if (fmt[*aux] == 'x')
		mim_pre_x_wnbr(tbv, tbvv, &*star);
	else if (fmt[*aux] == 'X')
		mim_pre_xx_wnbr(tbv, tbvv, &*star);
	*aux = *aux + 1;
	free(tbvv);
}
