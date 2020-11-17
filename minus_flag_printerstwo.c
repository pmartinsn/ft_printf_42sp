/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_flag_printerstwo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:45:49 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 18:46:16 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

int		print_s_minuswnumb(char *tobeconv, t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
	{
		j = j - 6;
		ft_putstr("(null)", &*star);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
		e_printshalf(j, help, &*star);
		return (0);
	}
	return (0);
}

void	e_printshalf(int j, int help, t_bdr *star)
{
	star->hold = ft_strlen(star->aux_outnbr);
	ft_putstr(star->aux_outnbr, &*star);
	if (star->hold > j)
		j = 0;
	else
		j = j - star->hold;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
