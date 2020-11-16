/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_pre_prinr_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:12:21 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/16 19:43:27 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	print_xx_pre(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
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

void	print_s_pre(char *tobeconv, t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
		star->aux_outnbr = "(null)";
	star->hold = ft_strlen(star->aux_outnbr);
	while ((help < j) && star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
}

void	p_int_pre_zero(char *tobeconv, t_bdr *star)
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
	if (j > 0)
	{
		if (star->kpr8 >= 0)
		{
			while (help < j)
			{
				ft_putchar(' ', &*star);
				help++;
			}
		}
	}
	free(character);
}

void	print_p_pre(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6 = ft_strlen(character);
	j = j - star->kpr6;
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	free(character);
}
