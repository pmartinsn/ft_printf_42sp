/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:52:13 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/20 19:21:57 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

int		pri_min_pre_wnbr(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;

	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
		star->aux_outnbr = "(null)";
	star->hold = ft_strlen(star->aux_outnbr);
	if (star->hold < i)
		j = j - star->hold;
	else
		j = j - i;
	e_minprei(j, i, help, &*star);
	return (0);
}

void	e_minprei(int j, int i, int help, t_bdr *star)
{
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
	if (fmt[*aux] == '-')
	{
		*aux = *aux + 1;
		while (fmt[*aux] == '-')
		{
			*aux = *aux + 1;
		}
		*aux = *aux + 1;
	}
	if ((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		if (fmt[*aux] == '*')
		{
			*aux = *aux + 1;
			if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
			{
				*aux = *aux + 1;
				e_starprestari(&*star);
			}
		}
		else
			dealing_precision(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		if (fmt[*aux] == 's')
		{
			*aux = *aux + 1;
			print_s_width(&*star);
			print_while(fmt, &*aux, &*star);
		}
		else if (fmt[*aux] == '.')
			check_and_pass(fmt, &*aux, &*star);
		else
		{
			*aux = *aux + 1;
			dealing_width_m(fmt, &*aux, &*star);
		}
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
	if (fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		print_per_minwnbr(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	free(tbv);
}

int		find_number_value(char *tobeconv, t_bdr *star)
{
	star->yndex = ft_atoi(tobeconv);
	return (star->yndex);
}
