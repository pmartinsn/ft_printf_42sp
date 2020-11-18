/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_width_call_m.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:40:29 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/18 10:27:54 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	verify_dwm(const char *fmt, int *aux, t_bdr *star)
{
//	int		i;
//	int		j;
	char	*tbv;

	tbv = malloc(malloc_index(fmt, &*aux));
	if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
		{
			tbv = converter(tbv, fmt, &*aux);
			*aux = *aux + 1;
			star->kpr3 = ft_atoi(tbv);
			star->kpr2 = va_arg(star->list, int);
			min_s_pre_ww(star->kpr3, star->hold, &*star);
		}
		e_vdwm(fmt, &*aux, &*star);
		if (fmt[*aux] == '*')
		{
			*aux = *aux + 1;
			if (fmt[*aux] == 's')
			{
				int i;
				int j;
				*aux = *aux + 1;
				j = va_arg(star->list, int);
				i = va_arg(star->list, int);
				min_s_pre_ww(j, i, &*star);
			}
		}
	}
}

void	e_vdwm(const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == '0')
		*aux = *aux + 1;
	if (fmt[*aux] == 's')
	{
		star->kpr3 = 0;
		*aux = *aux + 1;
		star->hold = va_arg(star->list, int);
		star->aux_outnbr = va_arg(star->list, char*);
		while (star->kpr3 < star->hold)
		{
			ft_putchar(' ', &*star);
			star->kpr3++;
		}
	}
}

void	min_s_pre_ww(int j, int i, t_bdr *star)
{
	int	help;

	help = 0;
	if (!(star->aux_outnbr = va_arg(star->list, char*)))
		star->aux_outnbr = "(null)";
	star->hold = ft_strlen(star->aux_outnbr);
	if ((j > 0) && (i > 0))
	{
		j = j - i;
		while ((help < i) && star->aux_outnbr[help] != '\0')
		{
			ft_putchar(star->aux_outnbr[help], &*star);
			help++;
		}
		help = 0;
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else if ((j > 0) && (i < 0))
	{
		i = i * -1;
		j = j - star->hold;
		ft_putstr(star->aux_outnbr, &*star);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else if ((j < 0) && (i > 0))
	{
		j = j * -1;
		j = j - star->hold;
		ft_putstr(star->aux_outnbr, &*star);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else if ((j < 0) && (i < 0))
	{
		j = j * -1;
		i = i * -1;
		j = j - star->hold;
		ft_putstr(star->aux_outnbr, &*star);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
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
