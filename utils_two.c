/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:00:42 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/12 14:27:45 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	pri_per_zerownbr(char *tbv, t_bdr *star)
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
		ft_putchar('0', &*star);
		help++;
	}
	ft_putchar('%', &*star);
}

int		find_number_value(char *tobeconv, t_bdr *star)
{
	star->yndex = ft_atoi(tobeconv);
	return (star->yndex);
}

void	pri_pre_wnbr(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;
//printf("xiiii");
	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
				star->aux_outnbr = "(null)";
	star->hold = ft_strlen(star->aux_outnbr);
	if (star->hold < i)
		j = j - star->hold;
	else
		j = j - i;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	help = 0;
	while ((help < i) && star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
}

void	pri_nbr_pre(char *tbv, t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
				star->aux_outnbr = "(null)";
	star->hold = ft_strlen(star->aux_outnbr);
/*	if (star->hold < i)
		j = j - star->hold;
	else
		j = j - i;*/
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

void	p_nbr_pre_i(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;

	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	star->kpr8 = va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->kpr8);
	star->hold = ft_strlen(star->aux_outnbr);
/*	if (star->hold > i)
		j = j - star->hold;
	else*/
		j = j - i;
	if(star->kpr8 >= 0)
	{
		if (star->hold >= i)
			j = j - (star->hold - i);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
		help = 0;
		i = i - star->hold;
		while (help < i)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr8, &*star);
	}
	else
	{
		if (star->hold >= i)
			j = j - (star->hold - i);
		else
			j = j - 1;
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
		help = 0;
		ft_putchar('-', &*star);
		i = i - star->hold;
		i = i + 1;
		while (help < i)
		{
			ft_putchar('0', &*star);
			help++;
		}
		star->kpr8 = star->kpr8 * -1;
		ft_putnbr(star->kpr8, &*star);
	}
	free (star->aux_outnbr);
}

void	pri_pre_u_wnbr(char *tbv, char *tbvv, t_bdr *star)
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
	star->aux_outnbr = ft_itoa_base(num, 10, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
/*	if (star->hold < i)
		j = j - star->hold;
	else*/
	j = j - i;
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	help = 0;
	i = i - star->kpr5;
	while (help < i)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
	/*while ((help < i) && star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}*/
	free(star->aux_outnbr);
}