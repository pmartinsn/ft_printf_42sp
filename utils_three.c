/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:58:08 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/19 11:16:59 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

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
	j = j - i;
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	e_prexx(i, help, &*star);
	free(star->aux_outnbr);
}

void	pri_pre_x_wnbr(char *tbv, char *tbvv, t_bdr *star)
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
	j = j - i;
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	e_prexx(i, help, &*star);
	free(star->aux_outnbr);
}

void	pri_pre_xx_wnbr(char *tbv, char *tbvv, t_bdr *star)
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
	star->aux_outnbr = ft_itoa_base(num, 16, 'A');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	j = j - i;
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	e_prexx(i, help, &*star);
	free(star->aux_outnbr);
}

void	e_prexx(int i, int help, t_bdr *star)
{
	help = 0;
	i = i - star->kpr5;
	while (help < i)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
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
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	star->aux_outnbr = NULL;
}

void	pri_nbr_prei(char *tbv, t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	star->hold= va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->hold);
	star->hold = ft_strlen(star->aux_outnbr);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	star->aux_outnbr = NULL;
}