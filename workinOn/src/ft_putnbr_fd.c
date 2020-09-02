/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathaliekhouri <nathaliekhouri@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:16:14 by pmartins          #+#    #+#             */
/*   Updated: 2020/04/16 15:02:19 by nathaliekho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void			ft_putchar_fd(char c, int fd);
//void			ft_putbnr_fd(int nb, int fd);

void	ft_putnbr_fd(int nb, int fd)
{
	long a;

	a = nb;
	if (a < 0)
	{
		write(fd, "-", 1);
		a = a * -1;
	}
	if (a / 10 > 0)
	{
		ft_putnbr_fd(a / 10, fd);
	}
	ft_putchar_fd((char)(a % 10 + 48), fd);
}
