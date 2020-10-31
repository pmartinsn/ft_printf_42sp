/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_width_call_m.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:40:29 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 18:03:09 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	verify_dwm(const char *fmt, int *aux, bdr *star)
{
	if(fmt[*aux] == '.')
	{
		*aux = *aux +1;
		if(fmt[*aux] == '0')
			*aux = *aux +1;
		if(fmt[*aux] == 's')
		{
			int	i;
			
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
}

void	verify_dwm_two(const char *fmt, int *aux, bdr *star)
{
	if(fmt[*aux] == 'p')
	{
		*aux = *aux +1;
		print_p_width_m( &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		print_u_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		print_x_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		print_X_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	dealing_width_m(const char *fmt, int *aux, bdr *star)
{
	verify_dwm(fmt, &*aux, &*star);
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux +1;
		ft_print_int_width_m( &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 's')
	{
		*aux = *aux +1;
		print_s_width_m(&*star);			
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'c')
	{
		*aux = *aux +1;
		print_char_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else 
		verify_dwm_two(fmt, &*aux, &*star);
}