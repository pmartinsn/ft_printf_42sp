/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfw_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:27:23 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/18 14:04:03 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	nfw_nbr(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	tobeconv = malloc(malloc_index(fmt, &*aux));
	tobeconv = verify_nfw(tobeconv, fmt, &*aux, &*star);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_wnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_wnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'c')
	{
		*aux = *aux + 1;
		print_char_wnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		verify_nfw_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

char	*verify_nfw(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	int	index;

	index = 0;
	if ((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
	{
		tobeconv[index] = fmt[*aux];
		index++;
		*aux = *aux + 1;
		while (fmt[*aux] >= '0' && fmt[*aux] <= '9')
		{
			tobeconv[index] = fmt[*aux];
			index++;
			*aux = *aux + 1;
		}
	}
	return (tobeconv);
}

void	verify_nfw_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_wnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_wnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		vry_nfw_three(tobeconv, fmt, &*aux, &*star);
}

void	vry_nfw_three(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_wnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_wnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		pri_per_wnbr(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		vry_nfw_four(tobeconv, fmt, &*aux, &*star);
}

void	vry_nfw_four(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		if (fmt[*aux] == '0')
			e_nfwfour(tobeconv, fmt, &*aux, &*star);
		else if (fmt[*aux] == 'p')
		{
			*aux = *aux + 1;
			p_p_snumb(tobeconv, &*star);
			print_while(fmt, &*aux, &*star);
		}
		else if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
			e_nfwfive(tobeconv, fmt, &*aux, &*star);
		else
		{
			*aux = *aux + 1;
			pri_nbr_pre(tobeconv, &*star);
		}
		print_while(fmt, &*aux, &*star);
	}
}

void	e_nfwfour(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	*aux = *aux + 1;
	if ((fmt[*aux] == 'i') | (fmt[*aux] == 'd'))
	{
		*aux = *aux + 1;
		p_int_pre_zero(tobeconv, &*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		pri_pre_u_wzero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
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
}

void	e_nfwfive(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	char	*tbv;

	tbv = malloc(malloc_index(fmt, &*aux));
	tbv = converter(tbv, fmt, &*aux);
	if (fmt[*aux] == 's')
		pri_pre_wnbr(tobeconv, tbv, &*star);
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		p_nbr_pre_i(tobeconv, tbv, &*star);
	else if (fmt[*aux] == 'u')
		pri_pre_u_wnbr(tobeconv, tbv, &*star);
	else if (fmt[*aux] == 'x')
		pri_pre_x_wnbr(tobeconv, tbv, &*star);
	else if (fmt[*aux] == 'X')
		pri_pre_xx_wnbr(tobeconv, tbv, &*star);
	else if (fmt[*aux] == 'p')
		p_p_cnumb(tobeconv, tbv, &*star);
	*aux = *aux + 1;
	free(tbv);
}
