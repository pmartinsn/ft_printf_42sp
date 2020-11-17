/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_width_caller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:46 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 18:06:48 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_width(const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == '.')
		check_and_pass(fmt, &*aux, &*star);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'c')
	{
		*aux = *aux + 1;
		print_char_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_width_two(fmt, &*aux, &*star);
}

void	print_xx_width_m(t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
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

void	print_p_width_m(t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	if (j < 14)
		j = 14;
	else
		j = j - 14;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}

void	print_xx_width(t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr6 = ft_strlen(character);
	if (star->kpr6 > j)
		j = star->kpr6;
	else
		j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_p_width(t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	if (j < 14)
		j = 14;
	else
		j = j - 14;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	free(character);
}
