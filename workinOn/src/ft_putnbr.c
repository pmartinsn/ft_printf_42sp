/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathaliekhouri <nathaliekhouri@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:16:14 by pmartins          #+#    #+#             */
/*   Updated: 2020/04/16 15:36:33 by nathaliekho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
	}//else ((a % 10) + 48);
	write(1, &a, 1);
}
