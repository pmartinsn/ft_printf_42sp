/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:18 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 14:14:04 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_minus(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	tobeconv = malloc(*aux * 3);
	verify_flags_minus(fmt, &*aux, &*star);
	tobeconv = converter(tobeconv, fmt, &*aux);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_min_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

void	dealing_min_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'c')
	{
		*aux = *aux + 1;
		print_char_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_minuswnumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_minus_three(tobeconv, fmt, &*aux, &*star);
}

void	dealing_minus_three(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	print_x_minuswnumb(char *tobeconv, t_bdr *star)
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
	ft_putstr(character, &*star);
	free(character);
	if (star->kpr6 > j)
		j = star->kpr6;
	else
		j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
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
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr6 = ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	if (star->kpr6 > j)
		j = star->kpr6;
	else
		j = j - star->kpr6;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
