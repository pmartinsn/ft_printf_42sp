/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_flag_printers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:44:03 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/25 18:02:33 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	ft_print_int_minuswnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	ft_putnbr(star->kpr8, &*star);
	star->kpr8 = ft_strlen(character);
	j = j - star->kpr8;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}

void	print_char_minuswnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	int		i;
	char	charr;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
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

void	print_p_minuswnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	star->conversion = 'p';
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a', &*star);
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	free(character);
	star->hold = ft_strlen(character);
	j = j - (star->hold + 2);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	//free(character);
}

void	print_u_minuswnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_u(num, 10, 'a');
	star->kpr5 = ft_strlen(character);
	ft_putstr(character, &*star);
	j = j - star->kpr5;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}
