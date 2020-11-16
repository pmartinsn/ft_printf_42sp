/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_pre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:43:01 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/16 14:01:23 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_precision(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;
	
	tobeconv = malloc(malloc_index(fmt, &*aux));
	if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		if (fmt[*aux] == 's')
		{
			*aux = *aux + 1;
			print_s_width(&*star);
			print_while(fmt, &*aux, &*star);
		}
		else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux + 1;
			p_int_wid_pre(&*star);
			print_while(fmt, &*aux, &*star);
		}
	}
	else if (fmt[*aux] == 'x') 
	{
		*aux = *aux + 1;
		pri_pre_x_wzero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X') 
	{
		*aux = *aux + 1;
		pri_pre_xx_wzero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		pri_i_pre_n(&*star);
	}
	else if (fmt[*aux] == 'u') 
	{
		*aux = *aux + 1;
		pri_pre_u_wzero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'p') 
	{
		*aux = *aux + 1;
		p_p_snumb(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	tobeconv = converter(tobeconv, fmt, &*aux);
	if (fmt[*aux] == '0')
	{
		char	*tbvv;

		*aux = *aux + 1;
		tbvv = malloc(malloc_index(fmt, &*aux));
		if ((fmt[*aux] >= '0' && fmt[*aux] <= '9'))
		{
			tbvv = converter(tbvv, fmt, &*aux);
			if(*tbvv == 0)
				*aux = *aux + 1;
		}
		if (fmt[*aux] == 's')
		{
			int	i;

			i = 0;
			*aux = *aux + 1;
			star->hold = ft_atoi(tbvv);
			if (!(star->aux_outnbr = va_arg(star->list, char*)))
				star->aux_outnbr = "(null)";
			while ((i < star->hold) && star->aux_outnbr[i] != '\0')
			{
				ft_putchar(star->aux_outnbr[i], &*star);
				i++;
			}
			print_while(fmt, &*aux, &*star);
		}
		if ((fmt[*aux] == 'i') | (fmt[*aux] == 'd'))
		{
			*aux = *aux + 1;
			star->kpr8 = va_arg(star->list, int);
			
		}
		else if (fmt[*aux] == 'u') 
		{
			*aux = *aux + 1;
			pri_pre_u_wzero(tobeconv, &*star);
			print_while(fmt, &*aux, &*star);
		}
		else if (fmt[*aux] == 'x') 
		{
			*aux = *aux + 1;
			pri_pre_x_wzero(tobeconv, &*star);
			print_while(fmt, &*aux, &*star);
		}
		else if (fmt[*aux] == 'X') 
		{
			*aux = *aux + 1;
			pri_pre_xx_wzero(tobeconv, &*star);
			print_while(fmt, &*aux, &*star);
		}
		else if (fmt[*aux] == 'p') 
		{
			*aux = *aux + 1;
			p_p_snumb(tobeconv, &*star);
			print_while(fmt, &*aux, &*star);
		}
		free(tbvv);
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
	else if (fmt[*aux] == 'p') 
	{
		*aux = *aux + 1;
		print_p_pre(tbv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}

void	pri_i_pre_n(t_bdr *star)
{
	star->hold = va_arg(star->list, int);
	star->helpint = ft_itoa(star->hold);
	if (star->hold != 0)
		ft_putnbr(star->hold, &*star);
	star->hold = ft_strlen(star->helpint);
	star->keeper = star->keeper + star->hold;
	free(star->helpint);
}

void	pri_pre_u_wzero(char *tbv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 10, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(star->aux_outnbr);
}

void	pri_pre_x_wzero(char *tbv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 16, 'a');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(star->aux_outnbr);
}

void	pri_pre_xx_wzero(char *tbv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;

	help = 0;
	j = 0;
	j = ft_atoi(tbv);
	num = 0;
	num = va_arg(star->list, size_t);
	star->aux_outnbr = ft_itoa_base(num, 16, 'A');
	star->kpr5 = ft_strlen(star->aux_outnbr);
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(star->aux_outnbr);
}

void	p_p_snumb(char *tobeconv, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	num = 0;
	j = ft_atoi(tobeconv);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->hold = ft_strlen(character);
	/*if (j < 14)
		j = 14;
	else*/
	j = j - 2;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr("0x", &*star);
	//ft_putstr(character, &*star);
	free(character);
}