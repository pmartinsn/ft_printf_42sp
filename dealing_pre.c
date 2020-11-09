/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_pre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:43:01 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/09 17:09:33 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_precision(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'u')
	| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))
		no_flags(fmt, &*aux, &*star);
	tobeconv = malloc(malloc_index(fmt, &*aux));
	tobeconv = converter(tobeconv, fmt, &*aux);
	if (fmt[*aux] == '0')/* && (fmt[*aux + 1] == 's'))*/
	{//	*aux = *aux + 2;
		//j = j ;char	*tbvv;
		*aux = *aux + 1;
		d_pre_zer(tobeconv, fmt, &*aux, &*star);
		/*char	*tbvv;
		tbvv = malloc(malloc_index(fmt, &*aux));
		if ((fmt[*aux] >= '1' && fmt[*aux] <= '9'))
			tbvv = converter(tbvv, fmt, &*aux);
		if (fmt[*aux] == 's')
		{
			int	i;
			int	help;

			i = 0;
			help = 0;
			*aux = *aux + 1;
			star->hold = ft_atoi(tbvv);
			if (!(star->aux_outnbr = va_arg(star->list, char*)))
				star->aux_outnbr = "(null)";
			while ((i < star->hold) && star->aux_outnbr[help] != '\0')
			{
			
				ft_putchar(star->aux_outnbr[help], &*star);
				help++;
				i++;
			}
		}
		free(tbvv);*/
	}
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_pre(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_preci_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
}

void	dealing_preci_two(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		dealing_preci_three(tbv, fmt, &*aux, &*star);
}

void	dealing_preci_three(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}
