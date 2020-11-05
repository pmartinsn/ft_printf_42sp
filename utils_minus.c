/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:52:13 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/05 11:28:58 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	pri_min_pre_wnbr(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;

	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	j = j - i;
	while ((help < i) && star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
	help = 0;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

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
	else if (fmt[*aux] == '0')
	{
		*aux = *aux + 1;
		deal_min_zero_perc(fmt, &*aux, &*star);
	}
}

void	deal_min_zero_perc(const char *fmt, int *aux, t_bdr *star)
{
	char *tbv;

	tbv = malloc(malloc_index(fmt, &*aux));
	tbv = converter(tbv, fmt, &*aux);
	if(fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		print_per_minwnbr(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	free(tbv);
	
}
