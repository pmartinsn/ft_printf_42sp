/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minus_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:31:31 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 16:52:08 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	mim_pre_u_wnbr(char *tbv, char *tbvv, t_bdr *star)
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
	star->keeper = 0;
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 10, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	j = j - i;
	star->keeper = i;
	star->keeper = star->keeper - star->kpr5;
	e_minuspreu(j, i, help, &*star);
	free(star->aux_outnbr);
}

void	e_minuspreu(int j, int i, int help, t_bdr *star)
{
	while (help < star->keeper)
	{
		ft_putchar('0', &*star);
		help++;
	}
	help = 0;
	ft_putstr(star->aux_outnbr, &*star);
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}

void	mim_pre_x_wnbr(char *tbv, char *tbvv, t_bdr *star)
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
	star->keeper = 0;
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 16, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	j = j - i;
	star->keeper = i;
	star->keeper = star->keeper - star->kpr5;
	e_minusxx(j, i, help, &*star);
	free(star->aux_outnbr);
}

void	mim_pre_xx_wnbr(char *tbv, char *tbvv, t_bdr *star)
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
	star->keeper = 0;
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 16, 'A');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	j = j - i;
	star->keeper = i;
	star->keeper = star->keeper - star->kpr5;
	e_minusxx(j, i, help, &*star);
	free(star->aux_outnbr);
}

void	e_minusxx(int j, int i, int help, t_bdr *star)
{
	while (help < star->keeper)
	{
		ft_putchar('0', &*star);
		help++;
	}
	help = 0;
	ft_putstr(star->aux_outnbr, &*star);
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
