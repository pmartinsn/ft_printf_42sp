/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minus_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:50:35 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 11:51:06 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	p_min_pre_i(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;

	help = 0;
	j = 0;
	i = 0;
	star->keeper = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	star->kpr8 = va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->kpr8);
	star->hold = ft_strlen(star->aux_outnbr);
	star->keeper = i;
	j = j - i;
	if (star->kpr8 >= 0)
		e_minuspreione(j, i, help, &*star);
	else
		e_minusprei(j, i, help, &*star);
	free(star->aux_outnbr);
}

void	e_minuspreione(int j, int i, int help, t_bdr *star)
{
	star->keeper = star->keeper - star->hold;
	while (help < star->keeper)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putnbr(star->kpr8, &*star);
	help = 0;
	if (star->hold >= i)
		j = j - (star->hold - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

void	e_minusprei(int j, int i, int help, t_bdr *star)
{
	ft_putchar('-', &*star);
	star->keeper = star->keeper - star->hold;
	star->keeper = star->keeper + 1;
	while (help < star->keeper)
	{
		ft_putchar('0', &*star);
		help++;
	}
	star->kpr8 = star->kpr8 * -1;
	ft_putnbr(star->kpr8, &*star);
	help = 0;
	if (star->hold >= i)
		j = j - (star->hold - i);
	else
		j = j - 1;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
