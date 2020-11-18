/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_width_call_m.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:40:29 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/18 13:25:18 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	verify_dwm(const char *fmt, int *aux, t_bdr *star)
{
	char	*tbv;

	tbv = malloc(malloc_index(fmt, &*aux));
	if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
			e_vdwm(tbv, fmt, &*aux, &*star);
		else if (fmt[*aux] == '*')
		{
			*aux = *aux + 1;
			if (fmt[*aux] == 's')
			{
				*aux = *aux + 1;
				star->kpr3 = va_arg(star->list, int);
				star->kpr2 = va_arg(star->list, int);
				min_s_pre_ww(&*star);
			}
		}
	}
}

void	e_vdwm(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
	{
		tbv = converter(tbv, fmt, &*aux);
		*aux = *aux + 1;
		star->kpr2 = ft_atoi(tbv);
		star->kpr3 = va_arg(star->list, int);
		min_s_pre_ww(&*star);
	}
	if (fmt[*aux] == '0')
		*aux = *aux + 1;
	if (fmt[*aux] == 's')
	{
		star->kpr2 = 0;
		*aux = *aux + 1;
		star->hold = va_arg(star->list, int);
		star->aux_outnbr = va_arg(star->list, char*);
		while (star->kpr2 < star->hold)
		{
			ft_putchar(' ', &*star);
			star->kpr2++;
		}
	}
}

void	verify_dwm_two(const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	dealing_width_m(const char *fmt, int *aux, t_bdr *star)
{
	verify_dwm(fmt, &*aux, &*star);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		print_s_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'c')
	{
		*aux = *aux + 1;
		print_char_width_m(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else
		verify_dwm_two(fmt, &*aux, &*star);
}
