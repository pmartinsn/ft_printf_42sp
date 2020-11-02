/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:16:14 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 14:00:11 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb, t_bdr *star)
{
	long	a;

	a = nb;
	if (a < 0)
	{
		ft_putchar('-', &*star);
		a = a * -1;
	}
	if (a / 10 > 0)
	{
		ft_putnbr((a / 10), &*star);
	}
	ft_putchar(((a % 10) + 48), &*star);
}
