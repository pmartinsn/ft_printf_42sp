/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:00:42 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/04 10:40:54 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	verify_flags_minus(const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		dealing_precision(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		dealing_width_m(fmt, &*aux, &*star);
	}else if (fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		dealing_per_m(fmt, &*aux, &*star);
	}
}


//verificar o zero com numero
	