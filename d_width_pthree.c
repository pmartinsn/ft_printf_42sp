/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_width_pthree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:23:58 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/18 13:25:14 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	min_s_pre_ww(t_bdr *star)
{
	int	help;

	help = 0;
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
		star->aux_outnbr = "(null)";
	star->hold = ft_strlen(star->aux_outnbr);
	if ((star->kpr3 > 0) && (star->kpr2 > 0))
		e_swwone(help, &*star);
	else if ((star->kpr3 > 0) && (star->kpr2 < 0))
		e_swwtwo(help, &*star);
	else if ((star->kpr3 < 0) && (star->kpr2 > 0))
		e_swwthree(help, &*star);
	else if ((star->kpr3 < 0) && (star->kpr2 < 0))
	{
		star->kpr3 = star->kpr3 * -1;
		star->kpr2 = star->kpr2 * -1;
		star->kpr3 = star->kpr3 - star->hold;
		ft_putstr(star->aux_outnbr, &*star);
		while (help < star->kpr3)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
}

void	e_swwone(int help, t_bdr *star)
{
	star->kpr3 = star->kpr3 - star->kpr2;
	while ((help < star->kpr2) && star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
	help = 0;
	while (help < star->kpr3)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

void	e_swwtwo(int help, t_bdr *star)
{
	star->kpr2 = star->kpr2 * -1;
	star->kpr3 = star->kpr3 - star->hold;
	ft_putstr(star->aux_outnbr, &*star);
	while (help < star->kpr3)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

void	e_swwthree(int help, t_bdr *star)
{
	star->kpr3 = star->kpr3 * -1;
	star->kpr3 = star->kpr3 - star->hold;
	ft_putstr(star->aux_outnbr, &*star);
	while (help < star->kpr3)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
