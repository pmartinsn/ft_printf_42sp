/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flag_b_wnbrs_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:40:59 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/27 10:06:45 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	ft_print_int_wnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	star->ret__ = ft_strlen(character);
	j = j - star->ret__;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putnbr(star->kpr8, &*star);
	free(character);
}

void	ft_pzero_int_wnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	star->ret__ = ft_strlen(character);
	j = j - star->ret__;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	if (star->kpr8 != 0)
		ft_putnbr(star->kpr8, &*star);
	if (star->kpr8 == 0)
		ft_putchar(' ', &*star);
	free(character);
}

int		print_s_wnumb(char *tobeconv, t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
	{
		j = j - 6;
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
		ft_putstr("(null)", &*star);
		return (0);
	}
	e_pswnumb(j, help, &*star);
	return (0);
}

void	e_pswnumb(int j, int help, t_bdr *star)
{
	star->hold = ft_strlen(star->aux_outnbr);
	if (star->hold > j)
		j = 0;
	else
		j = j - star->hold;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
}

void	pri_per_wnbr(char *tbv, t_bdr *star)
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

void	print_per_m(char *tbv, t_bdr *star)
{
	int j;
	int help;

	j = 0;
	help = 0;
	j = ft_atoi(tbv);
	ft_putchar('%', &*star);
	if (j < 1)
		j = 1;
	else
		j = j - 1;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
