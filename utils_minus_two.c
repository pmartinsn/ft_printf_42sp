/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minus_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:45:05 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/25 17:49:42 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	print_x_minuswnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->conversion = 'x';
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a', &*star);
	star->kpr6 = ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
//	free(character);
}

void	print_xx_minuswnumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->conversion = 'X';
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A', &*star);
	star->kpr6 = ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
//	free(character);
}
