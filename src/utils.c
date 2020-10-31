/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:46:50 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 17:51:18 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	check_and_pass(const char *fmt, int *aux, bdr *star)
{
	*aux = *aux +1;
	if(fmt[*aux] == '0')
		*aux = *aux +1;
	if(fmt[*aux] == 's')
	{
		int i;
		i = 0;
		*aux = *aux +1;
		star->hold = va_arg(star->list, int);
		star->aux_outnbr = va_arg(star->list, char*);
		while(i < star->hold)
		{
			ft_putchar(' ', &*star);
			i++;
		}
	}
}

void	verify_flags_minus(const char *fmt, int *aux, bdr *star)
{
	if((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	if(fmt[*aux] == '.')
	{
		*aux = *aux +1;
		dealing_precision(fmt, &*aux, &*star);
	}
	if(fmt[*aux] == '*')
	{
		*aux = *aux +1;
		dealing_width_m(fmt, &*aux, &*star);
	}
}

void	dealing_width_two(const char *fmt, int *aux, bdr *star)
{
	if(fmt[*aux] == 'p')
	{
		*aux = *aux +1;
		print_p_width( &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		print_u_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		print_x_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		print_X_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
}

char	*converter(char *tobeconv, const char *fmt, int *aux)
{
	if((fmt[*aux] != '0') && (fmt[*aux]  >= '1' && fmt[*aux]  <= '9') )
	{
		int index;
		
		index = 0;
		tobeconv[index]= fmt[*aux];
		index++;
		*aux = *aux + 1;
		while(fmt[*aux]  >= '0' && fmt[*aux]  <= '9')
		{
			tobeconv[index]= fmt[*aux];
			index++;
			*aux = *aux + 1;
		}
	}
	return(tobeconv);
}

void	dealing_minus_two(char *tobeconv, const char *fmt, int *aux, bdr *star)
{
	if(fmt[*aux] == 'p')
	{
		*aux = *aux +1;
		print_p_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		print_u_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		print_x_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		print_X_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}