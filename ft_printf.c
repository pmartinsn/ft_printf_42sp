/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:43:30 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 14:06:32 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	find_flag(const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == '-')
	{
		*aux = *aux + 1;
		dealing_minus(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		dealing_precision(fmt, &*aux, &*star);
	}
	if (fmt[*aux] == '0')
	{
		*aux = *aux + 1;
		dealing_zero(fmt, &*aux, &*star);
	}
	if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		dealing_width(fmt, &*aux, &*star);
	}
}

int		sortie(const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] == '-') | (fmt[*aux] == '.') | (fmt[*aux] == '0')
	| (fmt[*aux] == '*'))
	{
		find_flag(fmt, &*aux, &*star);
	}
	if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
		nfw_nbr(fmt, &*aux, &*star);
	else
	{
		no_flags(fmt, &*aux, &*star);
	}
	return (0);
}

int		get_info(const char *fmt, t_bdr *star)
{
	int	aux;

	aux = 0;
	while (fmt[aux])
	{
		if ((fmt[aux] == '%') && fmt[aux + 1] == '%')
		{
			aux = aux + 2;
			ft_putchar('%', &*star);
		}
		if ((fmt[aux] == '%') && (fmt[aux + 1] != '%'))
		{
			aux++;
			star->returned_s = sortie(fmt, &aux, &*star);
		}
		if (fmt[aux] != '\0' && fmt[aux] != '%')
		{
			ft_putchar(fmt[aux], &*star);
			aux++;
		}
	}
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	t_bdr star;

	init_bdr(&star);
	va_start(star.list, fmt);
	get_info(fmt, &star);
	va_end(star.list);
	return (star.count);
}
