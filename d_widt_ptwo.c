/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_widt_ptwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:46:31 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/26 08:34:33 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	print_u_width(t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	num = va_arg(star->list, size_t);
	character = ft_itoa_u(num, 10/*, 'a'*/);
	star->kpr5 = ft_strlen(character);
	if (star->kpr5 > j)
		j = star->kpr5;
	else
		j = j - star->kpr5;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
//	free(character);
	character = NULL;
}

void	print_x_width(t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	star->conversion = 'x';
	j = va_arg(star->list, int);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a', &*star);
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
//	free(character);
	character = NULL;
}

void	s_pre_width(t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	if (j < 0)
	{
		j = j * -1;
		j = j - star->hold;
		ft_putstr(star->aux_outnbr, &*star);
		/*while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}*/
	}
	else
		e_spre(j, help, &*star);
}

void	e_spre(int j, int help, t_bdr *star)
{
	while ((help < j) && star->aux_outnbr[help] != '\0')
	{
		ft_putchar(star->aux_outnbr[help], &*star);
		help++;
	}
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
