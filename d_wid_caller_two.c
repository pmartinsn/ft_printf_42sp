/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_wid_caller_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:06:16 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/27 14:14:56 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	p_int_wid_zero(t_bdr *star)
{
	int		help;
	int		j;
	char	*character;

	j = 0;
	help = 0;
	j = va_arg(star->list, int);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	star->ret__ = ft_strlen(character);
	if (j > 0)
		e_iwidzstart(j, help, &*star);
	else if (j < 0)
		e_iwidzend(j, help, &*star);
	free(character);
}

void	e_iwidzstart(int j, int help, t_bdr *star)
{
	j = j - star->ret__;
	if (star->kpr8 >= 0)
	{
		while (help < j)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr8, &*star);
	}
	else
	{
		ft_putchar('-', &*star);
		while (help < j)
		{
			ft_putchar('0', &*star);
			help++;
		}
		star->kpr8 = star->kpr8 * -1;
		ft_putnbr(star->kpr8, &*star);
	}
}

void	e_iwidzend(int j, int help, t_bdr *star)
{
	j = j * -1;
	j = j - star->ret__;
	ft_putnbr(star->kpr8, &*star);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

void	p_int_wid_pre(t_bdr *star)
{
	int		help;
	int		j;
//	char	*character;

	j = 0;
	help = 0;
	j = va_arg(star->list, int);
	star->kpr8 = va_arg(star->list, int);
//	star->aux_outnbr = ft_itoa(star->kpr8);
//	star->ret__ = ft_strlen(star->aux_outnbr);
	/*if (j < 0)
		j = j * -1;
	j = j - star->ret__;
	if (star->kpr8 > 0)
	{
		while (help < j)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr8, &*star);
	}
	else*/
	if ( star->kpr8 != 0)
		ft_putnbr(star->kpr8, &*star);//e_pwidpre(j, help, &*star);
//	free(star->aux_outnbr);
}

void	e_pwidpre(int j, int help, t_bdr *star)
{
	ft_putchar('-', &*star);
	j = j + 1;
	/*while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}*/
	help = 1;
	while (star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
}
