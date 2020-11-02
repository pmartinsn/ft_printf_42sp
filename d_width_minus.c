/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_width_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:42:35 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 13:58:40 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	ft_print_int_width_m(t_bdr *star)
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
	ft_putnbr(star->kpr8, &*star);
	if (star->ret__ > j)
		j = star->ret__;
	else
		j = j - star->ret__;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}

void	print_s_width_m(t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	ft_putstr(star->aux_outnbr, &*star);
	if (star->hold > j)
		j = star->hold;
	else
		j = j - star->hold;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

void	print_char_width_m(t_bdr *star)
{
	int		help;
	int		j;
	int		i;
	char	charr;

	help = 0;
	j = 0;
	i = 0;
	j = va_arg(star->list, int);
	i = va_arg(star->list, int);
	charr = (char)i;
	ft_putchar(charr, &*star);
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

void	print_u_width_m(t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 10, 'a');
	star->kpr5 = ft_strlen(character);
	ft_putstr(character, &*star);
	if (star->kpr5 > j)
		j = star->kpr5;
	else
		j = j - star->kpr5;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}

void	print_x_width_m(t_bdr *star)
{
	int		help;
	int		j;
	char	*character;
	size_t	num;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	num = 0;
	num = va_arg(star->list, size_t);
	character = malloc(num);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6 = ft_strlen(character);
	ft_putstr(character, &*star);
	if (star->kpr6 > j)
		j = star->kpr6;
	else
		j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}
