/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:46:50 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 14:20:12 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	check_and_pass(const char *fmt, int *aux, t_bdr *star)
{
	int	i;

	*aux = *aux + 1;
	if (fmt[*aux] == '0')
		*aux = *aux + 1;
	if (fmt[*aux] == 's')
	{
		i = 0;
		*aux = *aux + 1;
		star->hold = va_arg(star->list, int);
		star->aux_outnbr = va_arg(star->list, char*);
		while (i < star->hold)
		{
			ft_putchar(' ', &*star);
			i++;
		}
	}
}

void	verify_flags_minus(const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		dealing_precision(fmt, &*aux, &*star);
	}
	if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		dealing_width_m(fmt, &*aux, &*star);
	}
}

void	dealing_width_two(const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
}

char	*converter(char *tobeconv, const char *fmt, int *aux)
{
	int	index;

	if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
	{
		index = 0;
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
