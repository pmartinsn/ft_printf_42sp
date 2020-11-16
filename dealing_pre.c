/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_pre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:43:01 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/16 19:10:44 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_precision(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	tobeconv = malloc(malloc_index(fmt, &*aux));
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
	free(tobeconv);
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
		p_int_wid_pre(&*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	e_pre_x_xxdiu(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		pri_pre_x_wzero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		pri_pre_xx_wzero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		pri_i_pre_n(&*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		pri_pre_u_wzero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	d_pre_zero_two(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	char	*tbvv;

	tbvv = malloc(malloc_index(fmt, &*aux));
	if ((fmt[*aux] >= '0' && fmt[*aux] <= '9'))
	{
		tbvv = converter(tbvv, fmt, &*aux);
		if (*tbvv == 0)
			*aux = *aux + 1;
	}
	if (fmt[*aux] == 's')
	{
		s_pre(tbvv, &*aux, &*star);
		print_while(fmt, &*aux, &*star);
	}
	if ((fmt[*aux] == 'i') | (fmt[*aux] == 'd'))
	{
		*aux = *aux + 1;
		star->kpr8 = va_arg(star->list, int);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		pri_pre_u_wzero(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	free(tbvv);
}

void	s_pre(char *tbvv, int *aux, t_bdr *star)
{
	int	i;

	i = 0;
	*aux = *aux + 1;
	star->hold = ft_atoi(tbvv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
		star->aux_outnbr = "(null)";
	while ((i < star->hold) && star->aux_outnbr[i] != '\0')
	{
		ft_putchar(star->aux_outnbr[i], &*star);
		i++;
	}
}
