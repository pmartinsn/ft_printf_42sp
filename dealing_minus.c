/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:18 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/12 09:42:10 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_minus(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	verify_flags_minus(fmt, &*aux, &*star);
	tobeconv = malloc(malloc_index(fmt, &*aux));
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
	else
		dealing_minus_four(tbv, fmt, &*aux, &*star);
}

void	dealing_minus_four(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	char	*tbvv;

	tbvv = malloc(malloc_index(fmt, &*aux));
	if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_minuswnumb(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '%')
	{
		*aux = *aux + 1;
		print_per_minwnbr(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == '.')
	{//cai aqui se tiver dois numeros um antes e um depois do "."
		*aux = *aux + 1;
		if (fmt[*aux] == '0')
			d_pre_zer(tbv, fmt, &*aux, &*star);
		if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
		{
			tbvv = converter(tbvv, fmt, &*aux);
			//*aux = *aux + 1;
			if (fmt[*aux] == 's')
			{
				*aux = *aux + 1;
				pri_min_pre_wnbr(tbv, tbvv, &*star);
				
			}
			else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
			{
				*aux = *aux + 1;
				p_min_pre_i(tbv, tbvv, &*star);
			}
		}
		else
		{
			*aux = *aux + 1;
			pri_nbr_pre(tbv, &*star);
		}
		print_while(fmt, &*aux, &*star);
	}
	free(tbvv);
}

void	d_pre_zer(char *tbv, const char *fmt, int *aux, t_bdr *star)
{
	int		help;
	int		j;
	int		i;
//	char	*tbv;
	char	*tbvv;
//printf("teste");
	help = 0;
	j = 0;
	i = 0;
	*aux = *aux + 1;
//	tbv = malloc(malloc_index(fmt, &*aux));1111
	tbvv = malloc(malloc_index(fmt, &*aux));
	tbvv = converter(tbvv, fmt, &*aux);
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	if (tbvv[0] == '0')
		p_int_pre_zero(tbv, &*star);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		star->keeper = va_arg(star->list, int);
		star->aux_outnbr = ft_itoa(star->keeper);
		star->hold = ft_strlen(star->aux_outnbr);
		if (star->hold < i)
			j = j - star->hold;
		else
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
	free(star->aux_outnbr);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		if (!(star->aux_outnbr = va_arg(star->list, char*)))
					star->aux_outnbr = "(null)";
		star->hold = ft_strlen(star->aux_outnbr);
		if (star->hold < i)
			j = j - star->hold;
		else
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
	free(tbvv);
}

void	p_min_pre_i(char *tbv, char *tbvv, t_bdr *star)
{
	int	help;
	int	j;
	int	i;

	help = 0;
	j = 0;
	i = 0;
	star->keeper = 0;
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	star->kpr8 = va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->kpr8);
	star->hold = ft_strlen(star->aux_outnbr);
/*	if (star->hold > i)
		j = j - star->hold;
	else*/
	star->keeper = i;
	j = j - i;
	if (star->kpr8 >= 0)
	{
		star->keeper = star->keeper - star->hold;
		while (help < star->keeper)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr8, &*star);
		help = 0;
		if (star->hold >= i)
			j = j - (star->hold - i);
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else
	{
		ft_putchar('-', &*star);
		star->keeper = star->keeper - star->hold;
		star->keeper = star->keeper + 1;
		while (help < star->keeper)
		{
			ft_putchar('0', &*star);
			help++;
		}
		star->kpr8 = star->kpr8 * -1;
		ft_putnbr(star->kpr8, &*star);
		help = 0;
		if (star->hold >= i)
			j = j - (star->hold - i);
		else
			j = j - 1;
		while (help < j)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	free (star->aux_outnbr);
}