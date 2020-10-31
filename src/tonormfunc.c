/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tonormfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:40:00 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 16:40:03 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_X_width_m(bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr6= ft_strlen(character);
	ft_putstr(character, &*star);
	if(star->kpr6 > j)
		j = star->kpr6;
		else j = j -star->kpr6;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}

void	print_p_width_m(bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	if( j < 14)
		j = 14;
		else j =  j - 14;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}

void	print_X_width(bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
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

void	print_p_width(bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = va_arg(star->list, int);
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	if( j < 14)
		j = 14;
		else j = j - 14;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	free(character);
}

void	print_while(const char *fmt, int *aux, bdr *star)
{
	while(fmt[*aux] != '%' && fmt[*aux] != '\0')
	{
		ft_putchar(fmt[*aux],  &*star);
		*aux = *aux +1;
	}
}