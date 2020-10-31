/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flag_but_wnumbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:41:07 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 18:41:08 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_wnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;
	int i;

	help = 0;
	j = 0;
	i = 0;
	j = ft_atoi(tobeconv);
	char charr;
	i = va_arg(star->list, int);
	charr = (char)i;
	if( j < 1)
		j = 1;
		else j = j - 1;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putchar(charr,  &*star);
}

void	print_p_wnumb(char *tobeconv, bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	character ="tryme";
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	if( j < 14)
		j = 14;
		else j =  j - 14;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	free(character);
}

void	print_u_wnumb(char *tobeconv,bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	character ="tryme";
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 10, 'a');
	star->kpr5= ft_strlen(character);
	if(star->kpr5 > j)
		j = star->kpr5;
		else j =  j -star->kpr5;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_x_wnumb(char *tobeconv, bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	character ="tryme";
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6= ft_strlen(character);
	if(star->kpr6 > j)
		j = star->kpr6;
		else j =  j -star->kpr6;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_X_wnumb(char *tobeconv, bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	character ="tryme";
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr6= ft_strlen(character);
	if(star->kpr6 > j)
		j = star->kpr6;
		else j = j -star->kpr6;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}