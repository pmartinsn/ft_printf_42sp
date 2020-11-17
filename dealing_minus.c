/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:18 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/17 11:43:48 by pmartins         ###   ########.fr       */
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
	{
		*aux = *aux + 1;
		if (fmt[*aux] == 's')
		{
			*aux = *aux + 1;
			pri_nbr_pre(tbv, &*star);
		}
		else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux + 1;
			p_int_pre_zero(tbv, &*star);
		}
		else if (fmt[*aux] == 'u') 
		{
			*aux = *aux + 1;
			pri_pre_u_wzero(tbv, &*star);
		}
		else if (fmt[*aux] == 'x') 
		{
			*aux = *aux + 1;
			pri_pre_x_wzero(tbv, &*star);
			print_while(fmt, &*aux, &*star);
		}
		else if (fmt[*aux] == 'X') 
		{
			*aux = *aux + 1;
			pri_pre_xx_wzero(tbv, &*star);
			print_while(fmt, &*aux, &*star);
		}
		else if (fmt[*aux] == '0')
		{
			*aux = *aux + 1;
			if (fmt[*aux] == 's')
			{
				*aux = *aux + 1;
				pri_nbr_pre(tbv, &*star);
			}		
			else if ((fmt[*aux] == 'i')| (fmt[*aux] == 'd'))
			{
				*aux = *aux + 1;
				p_int_pre_zero(tbv, &*star);
			}
			else if (fmt[*aux] == 'u') 
			{
				*aux = *aux + 1;
				pri_pre_u_wzero(tbv, &*star);
			}
			else if (fmt[*aux] == 'x') 
			{
				*aux = *aux + 1;
				pri_pre_x_wzero(tbv, &*star);
				print_while(fmt, &*aux, &*star);
			}
			else if (fmt[*aux] == 'X') 
			{
				*aux = *aux + 1;
				pri_pre_xx_wzero(tbv, &*star);
				print_while(fmt, &*aux, &*star);
			}
			else
				d_pre_zer(tbv, fmt, &*aux, &*star);
		}
		if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
		{
			tbvv = converter(tbvv, fmt, &*aux);
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
			else if (fmt[*aux] == 'u') 
			{
				*aux = *aux + 1;
				mim_pre_u_wnbr(tbv, tbvv, &*star);
			}
			else if (fmt[*aux] == 'x') 
			{
				*aux = *aux + 1;
				mim_pre_x_wnbr(tbv, tbvv, &*star);
			}
			else if (fmt[*aux] == 'X') 
			{
				*aux = *aux + 1;
				mim_pre_xx_wnbr(tbv, tbvv, &*star);
			}
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
	char	*tbvv;

	help = 0;
	j = 0;
	i = 0;
	tbvv = malloc(malloc_index(fmt, &*aux));
	tbvv = converter(tbvv, fmt, &*aux);
	j = ft_atoi(tbv);
	i = ft_atoi(tbvv);
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		e_minusdzone(j, i, help, &*star);
		
	free(star->aux_outnbr);
	}
	else if (fmt[*aux] == 's')
	{
		*aux = *aux + 1;
		e_minusdz(j, i, help, &*star);
	}
	free(tbvv);
}

void	e_minusdzone(int j, int i, int help, t_bdr *star)
{
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
}

void	e_minusdz(int j, int i, int help, t_bdr *star)
{
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
	star->keeper = i;
	j = j - i;
	if (star->kpr8 >= 0)
		e_minuspreione(j, i, help, &*star);
	else
		e_minusprei(j, i, help, &*star);
	free(star->aux_outnbr);
}

void	e_minuspreione(int j, int i, int help, t_bdr *star)
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

void	e_minusprei(int j, int i, int help, t_bdr *star)
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
