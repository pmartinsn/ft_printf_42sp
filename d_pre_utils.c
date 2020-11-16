/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_pre_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:39:37 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/16 17:39:38 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	pri_i_pre_n(t_bdr *star)
{
	star->hold = va_arg(star->list, int);
	star->helpint = ft_itoa(star->hold);
	if (star->hold != 0)
		ft_putnbr(star->hold, &*star);
	star->hold = ft_strlen(star->helpint);
	star->keeper = star->keeper + star->hold;
	free(star->helpint);
}

void	pri_pre_u_wzero(char *tbv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 10, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(star->aux_outnbr);
}

void	pri_pre_x_wzero(char *tbv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 16, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(star->aux_outnbr);
}

void	pri_pre_xx_wzero(char *tbv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 16, 'A');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(star->aux_outnbr);
}

void	p_p_snumb(char *tobeconv, t_bdr *star)
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
	j = j - 2;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr("0x", &*star);
	free(character);
}
