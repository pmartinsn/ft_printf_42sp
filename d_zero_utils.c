/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_zero_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:01:31 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 17:22:16 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	print_per_zero(char *tbv, t_bdr *star)
{
	int j;
	int help;

	j = 0;
	help = 0;
	j = ft_atoi(tbv);
	if (j < 1)
		j = 1;
	else
		j = j - 1;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putchar('%', &*star);
}

void	print_s_zero(char *tbv, t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
	{
		j = j - 6;
		ft_putstr("(null)", &*star);
		while (help < j)
		{
			ft_putchar('0', &*star);
			help++;
		}
	}
	else
		e_pzeros(j, help, &*star);
}

void	e_pzeros(int j, int help, t_bdr *star)
{
	star->hold = ft_strlen(star->aux_outnbr);
	if (star->hold > j)
		j = 0;
	else
		j = j - star->hold;
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
}

void	ft_jumpzero(const char *fmt, int *aux)
{
	while ((fmt[*aux] == '0') || (fmt[*aux] == '-'))
	{
		*aux = *aux + 1;
	}
}
