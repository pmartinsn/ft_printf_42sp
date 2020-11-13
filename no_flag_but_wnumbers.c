/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flag_but_wnumbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:41:07 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/13 15:31:29 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	print_char_wnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	int		i;
	char	charr;

	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tobeconv);
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

void	print_p_wnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->hold = ft_strlen(character);
	/*if (j < 14)
		j = 14;
	else*/
	j = j - (star->hold + 2);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	free(character);
}

void	print_u_wnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 10, 'a');
	star->kpr5 = ft_strlen(character);
	/*if (star->kpr5 > j)
		j = star->kpr5;
	else*/
	j = j - star->kpr5;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_x_wnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6 = ft_strlen(character);
	/*if (star->kpr6 > j)
		j = star->kpr6;
	else*/
	j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_xx_wnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr6 = ft_strlen(character);
	/*if (star->kpr6 > j)
		j = star->kpr6;
	else*/
		j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	p_p_cnumb(char *tbv, char *tbvv, t_bdr *star)
{
	int		help;
	int		j;
	int		i;
	size_t	num;

	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 16, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	
	j = j - (star->kpr5 + 2);
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	help = 0;
	i = i - star->kpr5;
	ft_putstr("0x", &*star);
	while (help < i)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
	free(star->aux_outnbr);
}