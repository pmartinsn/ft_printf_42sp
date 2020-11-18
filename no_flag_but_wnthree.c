/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flag_but_wnthree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:28:41 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/18 09:33:59 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

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
	j = j - i;
	j = j - 2;
	if (star->kpr5 >= i)
		j = j - (star->kpr5 - i);
	e_ppcnumb(j, i, help, &*star);
	free(star->aux_outnbr);
}

void	e_ppcnumb(int j, int i, int help, t_bdr *star)
{
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
}
