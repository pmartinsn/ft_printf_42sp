/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_pre_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:22:39 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/16 19:31:04 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

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

