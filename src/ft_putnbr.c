/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:16:14 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/13 12:15:11 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void			ft_putchar(char c);
void	ft_putnbr(int nb)
{
	long a;
	a = nb;
	if (a < 0)
	{
		write(1, "-", 1);
		a = a * -1;
	}
	if (a / 10 > 0)
	{
		ft_putnbr(a / 10);
	}
	ft_putchar((a % 10) + 48);
		
}
