/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_width_printers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:44:38 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/27 20:42:42 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	ft_print_int_width(t_bdr *star)
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
	if (j < 0)
	{
		j = j * -1;
		j = j - star->ret__;
		ft_putnbr(star->kpr8, &*star);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else
		e_prei(j, help, &*star);
	free(character);
}

void	e_prei(int j, int help, t_bdr *star)
{
	j = j - star->ret__;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putnbr(star->kpr8, &*star);
}

void	print_s_width(t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	if (j < 0)
	{
		j = j * -1;
		j = j - star->hold;
		ft_putstr(star->aux_outnbr, &*star);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else
		e_presw(j, help, &*star);
}

void	e_presw(int j, int help, t_bdr *star)
{
	j = j - star->hold;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
}

void	print_char_width(t_bdr *star)
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
	if (j < 1)
		j = 1;
	else
		j = j - 1;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putchar(charr, &*star);
}


void	ft_star_int_width(t_bdr *star)
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
	if (j < 0)
	{
		j = j * -1;
		j = j - star->ret__;
		ft_putnbr(star->kpr8, &*star);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else
		e_pi(j, help, &*star);
	free(character);
}

void	e_pi(int j, int help, t_bdr *star)
{
	j = j - star->ret__;
	ft_putnbr(star->kpr8, &*star);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}