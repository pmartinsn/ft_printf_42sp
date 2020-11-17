/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:18 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 16:24:53 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_minus(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	verify_flags_minus(fmt, &*aux, &*star);
	tobeconv = malloc(malloc_index(fmt, &*aux));
	tobeconv = converter(tobeconv, fmt, &*aux);
	e_checkminus(tobeconv, fmt, &*aux, &*star);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_min_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

void	dealing_min_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'c')
	{
		*aux = *aux + 1;
		print_char_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_minus_three(tobeconv, fmt, &*aux, &*star);
}

void	dealing_minus_three(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_minus_four(tbv, fmt, &*aux, &*star);
}

void	dealing_minus_four(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		e_minuspre(tbv, fmt, &*aux, &*star);
		if (fmt[*aux] == '0')
		{
			*aux = *aux + 1;
			e_minuszero(tbv, fmt, &*aux, &*star);
		}
		if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
		{
			e_mnbr(tbv, fmt, &*aux, &*star);
			
		}
		print_while(fmt, &*aux, &*star);
	}
}

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
