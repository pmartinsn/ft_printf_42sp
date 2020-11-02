/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flags_callers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:37:56 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 14:42:34 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void		no_flags(const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] == 'd') || (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		print_int_noflag(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_noflag(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'c')
	{
		*aux = *aux + 1;
		print_char_noflag(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		no_flags_two(fmt, &*aux, &*star);
}

void		no_flags_two(const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_noflag(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_noflag(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_noflag(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_noflag(&*star);
		print_while(fmt, &*aux, &*star);
	}
}
