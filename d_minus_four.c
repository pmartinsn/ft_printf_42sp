/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minus_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:51:42 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 19:05:45 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	d_pre_zer(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	int		help;
	int		j;
	int		i;
	char	*tbvv;

	help = 0;
	j = 0;
	i = 0;
	tbvv = malloc(malloc_index(fmt, &*aux));
	tbvv = converter(tbvv, fmt, &*aux);
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		e_minusdzone(j, i, help, &*star);
	//	free(star->aux_outnbr);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		e_minusdz(j, i, help, &*star);
	}
	free(tbvv);
//	free(tbv);
}

void	e_minusdzone(int j, int i, int help, t_bdr *star)
{
	star->keeper = va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->keeper);
	star->hold = ft_strlen(star->aux_outnbr);
	if (star->hold < i)
		j = j - star->hold;
	else
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

void	e_minusdz(int j, int i, int help, t_bdr *star)
{
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
		star->aux_outnbr = "(null)";
	star->hold = ft_strlen(star->aux_outnbr);
	if (star->hold < i)
		j = j - star->hold;
	else
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
