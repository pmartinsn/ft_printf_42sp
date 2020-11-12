/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:17:10 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/12 14:30:54 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_zero(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;
	//char	*tbv;

	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'u')
	| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))
		no_flags(fmt, &*aux, &*star);
	tobeconv = malloc(malloc_index(fmt, &*aux));
	tobeconv = converter(tobeconv, fmt, &*aux);
	if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	if ((fmt[*aux] == '0') || (fmt[*aux] == '-'))
	{
		if (fmt[*aux] == '-')
		{
			*aux = *aux + 1;
			dealing_minus(fmt, &*aux, &*star);
			print_while(fmt, &*aux, &*star);
		}
		ft_jumpzero(fmt, &*aux);
		if (fmt[*aux] == 's')
		{
			*aux = *aux + 1;
			print_s_noflag(&*star);
			print_while(fmt, &*aux, &*star);
		}
	}
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dea_zero_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

void	dea_zero_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	char	*tbvv;

	tbvv = malloc(malloc_index(fmt, &*aux));
	if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		pri_per_zerownbr(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '.')
	{//cai aqui se tiver dois numeros um antes e um depois do "."
		*aux = *aux + 1;
		if (fmt[*aux] == '0')
			d_pre_zer(tobeconv, fmt, &*aux, &*star);
		if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
		{
			tbvv = converter(tbvv, fmt, &*aux);
			//*aux = *aux + 1;
			if (fmt[*aux] == 's')
			{
				*aux = *aux + 1;
				pri_pre_wnbr(tobeconv, tbvv, &*star);
				
			}
			else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
			{
				*aux = *aux + 1;
				p_nbr_pre_i(tobeconv, tbvv, &*star);
			}
			else if (fmt[*aux] == 'u') 
			{
				*aux = *aux + 1;
				pri_pre_u_wnbr(tobeconv, tbvv, &*star);
			}
		}
		else
		{
			*aux = *aux + 1;
			pri_nbr_pre(tobeconv, &*star);
		}
		print_while(fmt, &*aux, &*star);
	}
	free(tbvv);
}

void	ft_jumpzero(const char *fmt, int *aux)
{
	while ((fmt[*aux] == '0') || (fmt[*aux] == '-'))
	{
		*aux = *aux + 1;
	}
}

void	print_s_zero(char *tbv,  t_bdr *star)
{
	int	help;
	int	j;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	if(!(star->aux_outnbr = va_arg(star->list, char*)))
	{
		j = j - 6;
		ft_putstr("(null)", &*star);
		while (help < j)
		{
			ft_putchar('0', &*star);
			help++;
		}
	}
	star->hold = ft_strlen(star->aux_outnbr);
	if (star->hold > j)
		j = 0;
	else
		j = j - star->hold;
	while (help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
}
