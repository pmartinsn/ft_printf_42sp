/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:46:39 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 10:47:33 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	p_nbr_pre_i(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;

	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	star->kpr8 = va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->kpr8);
	star->hold = ft_strlen(star->aux_outnbr);
	j = j - i;
	if (star->kpr8 >= 0)
		e_npreione(j, i, help, &*star);
	else
		e_nprei(j, i, help, &*star);
	free(star->aux_outnbr);
}

void	e_npreione(int j, int i, int help, t_bdr *star)
{
	if (star->hold >= i)
		j = j - (star->hold - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	help = 0;
	i = i - star->hold;
	while (help < i)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putnbr(star->kpr8, &*star);
}

void	e_nprei(int j, int i, int help, t_bdr *star)
{
	if (star->hold >= i)
		j = j - (star->hold - i);
	else
		j = j - 1;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	help = 0;
	ft_putchar('-', &*star);
	i = i - star->hold;
	i = i + 1;
	while (help < i)
	{
		ft_putchar('0', &*star);
		help++;
	}
	star->kpr8 = star->kpr8 * -1;
	ft_putnbr(star->kpr8, &*star);
}
