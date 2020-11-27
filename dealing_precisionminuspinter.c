/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_precisionminuspinter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:06:49 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/27 10:50:14 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	ft_print_int_pre(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->kpr8);
	star->ret__ = ft_strlen(star->aux_outnbr);
	if (j > 0)
	{
		j = j - star->ret__;
		if (star->kpr8 >= 0)
		{
			while (help < j)
			{
				ft_putchar('0', &*star);
				help++;
			}
			ft_putnbr(star->kpr8, &*star);
		}
		else
			e_pre(j, help, &*star);
	}
	free(star->aux_outnbr);
}

void	e_pre(int j, int help, t_bdr *star)
{
	ft_putchar('-', &*star);
	j = j + 1;
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	star->aux_outnbr = ft_itoa(star->kpr8);
	help = 1;
	while(star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
}

void	print_u_pre(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	char	*character;
	size_t	num;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_u(num, 10/*, 'a'*/);
	star->kpr5 = ft_strlen(character);
	j = j - star->kpr5;
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_x_pre(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	star->conversion = 'x';
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a', &*star);
	star->kpr6 = ft_strlen(character);
	j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(character, &*star);
//	free(character);
}
