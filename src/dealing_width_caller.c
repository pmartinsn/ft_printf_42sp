/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_width_caller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:46 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 17:15:44 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dealing_width(const char *fmt, int *aux, bdr *star)
{
	if(fmt[*aux] == '.')
		check_and_pass(fmt, &*aux, &*star);
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux +1;
		ft_print_int_width( &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 's')
	{
		*aux = *aux +1;
		print_s_width(&*star);			
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'c')
	{
		*aux = *aux +1;
		print_char_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_width_two(fmt, &*aux, &*star);
}