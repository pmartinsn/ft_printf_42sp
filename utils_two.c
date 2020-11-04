/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:00:42 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/04 15:54:39 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	verify_flags_minus(const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		dealing_precision(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		dealing_width_m(fmt, &*aux, &*star);
	}
}

void	pri_per_zerownbr(char *tbv, t_bdr *star)
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
		ft_putchar('0', &*star);
		help++;
	}
	ft_putchar('%', &*star);
}

int		find_number_value(char *tobeconv, t_bdr *star)
{
	star->yndex = ft_atoi(tobeconv);
	return (star->yndex);
}

void	pri_pre_wnbr(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;

	help = 0;
	j = 0;
	i = 1;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	j = j - i;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	help = 0;
	while (help < i)
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
}
