/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_zero_printers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:16:58 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/25 18:27:06 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	ft_print_int_zero(char *tobeconv, t_bdr *star)
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
		ezeroi(j, help, &*star);
	free(character);
}

void	ezeroi(int j, int help, t_bdr *star)
{
	ft_putchar('-', &*star);
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	star->kpr8 = star->kpr8 * -1;
	ft_putnbr(star->kpr8, &*star);
}

void	print_u_zero(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_u(num, 10, 'a');
	star->kpr5 = ft_strlen(character);
	if (star->kpr5 > j)
		j = star->kpr5;
	else
		j = j - star->kpr5;
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_x_zero(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	star->conversion = 'x';
	j = ft_atoi(tobeconv);
	num = 0;
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
	free(character);
}

void	print_xx_zero(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	star->conversion = 'x';
	j = ft_atoi(tobeconv);
	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A', &*star);
	star->kpr6 = ft_strlen(character);
	j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}
