/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfw_nbrtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:12:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/18 14:12:44 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

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
