/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:40:00 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 14:18:19 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	print_while(const char *fmt, int *aux, t_bdr *star)
{
	while (fmt[*aux] != '%' && fmt[*aux] != '\0')
	{
		ft_putchar(fmt[*aux], &*star);
		*aux = *aux + 1;
	}
}
