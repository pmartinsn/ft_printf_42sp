/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_pre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:43:01 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/27 17:18:58 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_precision(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	if (fmt[*aux] == '0')
	{
		*aux = *aux + 1;	
		if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux + 1;
			print_int_zflag(&*star);
		}
		if (fmt[*aux] == 's')
		{
			*aux = *aux + 1;
			s_pre_width(&*star);
			print_while(fmt, &*aux, &*star);
		}
	}
	tobeconv = ft_calloc(malloc_index(fmt, &*aux), sizeof(char));
	if (fmt[*aux] == '*')
		e_pre_star(fmt, &*aux, &*star);
	else if ((fmt[*aux] == 'x') | (fmt[*aux] == 'X') |
	(fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'u'))
		e_pre_x_xxdiu(tobeconv, fmt, &*aux, &*star);
	else if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		p_p_snumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	tobeconv = converter(tobeconv, fmt, &*aux);
	dealing_preci_two(tobeconv, fmt, &*aux, &*star);
//	free(tobeconv);
	tobeconv = NULL;
}

void	dealing_preci_two(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == '0')
	{
		*aux = *aux + 1;
		d_pre_zero_two(tbv, fmt, &*aux, &*star);
		if (fmt[*aux] == 'p')
		{
			*aux = *aux + 1;
			p_p_snumb(tbv, &*star);
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
	}
	else
		dealing_preci_three(tbv, fmt, &*aux, &*star);
}

void	dealing_preci_three(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_preci_four(tbv, fmt, &*aux, &*star);
}

void	dealing_preci_four(char *tbv, const char *fmt, int *aux, t_bdr *star)
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
	else if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	e_pre_star(const char *fmt, int *aux, t_bdr *star)
{
	*aux = *aux + 1;
	if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		s_pre_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		p_int_wid_pre(&*star); ///change de function for a test
		print_while(fmt, &*aux, &*star);
	}
}
