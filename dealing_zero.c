/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:17:10 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/29 10:35:35 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	dealing_zero(const char *fmt, int *aux, t_bdr *star)
{
	char	*tobeconv;

	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'u')
	| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))
		no_flags(fmt, &*aux, &*star);
	else if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;	
		if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux + 1;
			print_int_zflag(&*star);
		}
		else if (fmt[*aux] == '0')
		{
			*aux = *aux + 1;
			if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
			{
				*aux = *aux + 1;
				print_int_zflag(&*star);
			}
		}
	}
	else if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux + 1;
			p_int_wid_zero(&*star);
			print_while(fmt, &*aux, &*star);
		}
		else if (fmt[*aux] == '.')
		{
			*aux = *aux + 1;
			if (fmt[*aux] == '*')
			{
				*aux = *aux + 1;
				if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
				{
					*aux = *aux + 1;
					e_starprestari(&*star);
				}
				else if ((fmt[*aux] == 'X') | (fmt[*aux] == 'x') | (fmt[*aux] == 'u'))
					e_starprestar(fmt, &*aux, &*star);
			}
		}
	}
	tobeconv = ft_calloc(malloc_index(fmt, &*aux), sizeof(char));
	tobeconv = converter(tobeconv, fmt, &*aux);
	e_zhalf(tobeconv, fmt, &*aux, &*star);
	dea_zero_two(tobeconv, fmt, &*aux, &*star);
	free(tobeconv);
	tobeconv = NULL;
}

void	e_starprestari(t_bdr *star)
{
	int	help;

	help = 0;
	star->kpr3 = va_arg(star->list, int);
	star->kpr2 = va_arg(star->list, int);
	star->kpr4 = va_arg(star->list, int);
	star->aux_outnbr = ft_itoa(star->kpr4);
	star->hold = ft_strlen(star->aux_outnbr);
	star->kpr5 = star->kpr2; 
	if (star->kpr2 < 0)
		star->kpr2 = star->kpr2 * -1;
	star->kpr2 = star->kpr2 - star->hold;
	e_starprei(help, &*star);
	free(star->aux_outnbr);
	star->aux_outnbr = NULL;
}


void	e_starprei(int help, t_bdr *star)
{
	int j;
	j = 0;
//	if (star->kpr5 <= 1)
//		j = 1;
	if ((star->kpr5 == 0) && star->kpr4 == 0)
	{
		ft_putchar(' ', &*star);
		ft_putchar(' ', &*star);
	}
	else if ((star->kpr4 == 0) && (star->kpr5 > star->hold) )
	{
		star->kpr5 = star->kpr5 -star->hold;
		while(help <= star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
	}
	else if ((star->hold == 1) && (star->kpr5 > star->hold) && (star->kpr4 != 0))
	{
		star->kpr5 = star->kpr5 -star->hold -1;
		while(help <= star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr4 , &*star);
	}
	/*else if ((star->kpr5 > star->hold) && star->kpr4 > 0)
	{
		star->kpr5 = star->kpr5 -star->hold;
		help = 0;
		while(help <= star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr4 , &*star);
	}*/
	else if ((star->hold == 1) && (star->kpr5 = 0 ) )
	{
			ft_putnbr(star->kpr4 , &*star);
			ft_putchar(' ', &*star);	
	}
	else if ((star->hold == 1) && (star->kpr5 = 1 ))
	{
			ft_putnbr(star->kpr4 , &*star);
			ft_putchar(' ', &*star);	
	}
	else if ((star->kpr4 == 0) && (star->kpr5 = 1 ))
	{
			//ft_putnbr(star->kpr4 , &*star);
			ft_putchar('0', &*star);
			ft_putchar(' ', &*star);	
	}
	else if ((star->kpr4 == 0) && (star->kpr2 != 0) )
	{
			ft_putchar('0', &*star);
			if (star->kpr5 > 0)
				ft_putchar(' ', &*star);
	}
	else if ((star->kpr5 < 0 ) && (star->kpr4 > 0))
	{
	/*	star->kpr5 = star->kpr5 -star->hold;
		while(help < star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}*/
		ft_putnbr(star->kpr4, &*star);
	}
	else if ((star->kpr5 < 0) && (star->kpr4 < 0))
	{
		ft_putchar('-', &*star);
		/*star->kpr5 = star->kpr5 +1;
		star->kpr5 = star->kpr5 -star->hold;
		while(help < star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}*/
		help = 1;
		while (help < star->hold)
		{
			ft_putchar(star->aux_outnbr[help], &*star);
			help++;
		}
	}
	else if ((star->kpr4 < 0))
	{
		ft_putchar('-', &*star);
		help = 0;
		star->kpr5 = star->kpr5 + 1;
		j = star->kpr5;
		star->kpr5 = star->kpr5 -star->hold;
		while(help < star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
		help = 1;
		while (help < star->hold)
		{
			ft_putchar(star->aux_outnbr[help], &*star);
			help++;
		}
		help = 0;
		star->kpr3 = star->kpr3 - j -1;
		while(help < star->kpr3)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
		else if ((star->kpr4 > 0))
	{
		help = 0;
		j = star->kpr5;
	//	star->kpr5 = star->kpr5 - star->hold;
		star->kpr5 = star->kpr5 - star->hold;
		while(help < star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr4, &*star);
		help = 0;
		//if (star->kpr5 < 0)
		//	star->kpr5 = star->kpr5 * -1;
		star->kpr3 = star->kpr3 - j;
		while(help < star->kpr3)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
/*	else if (star->kpr2 >= star->kpr5)
		ft_putnbr(star->kpr4, &*star);
	if ((j == 1) && (star->kpr3 <= 3))
	{
		help = 0;
		while (help < star->kpr2)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}*/
	/*if ((star->kpr3 > star->kpr5 ))
	{
		star->kpr5 = star->kpr3 -star->kpr5 -star->hold;		
		help = 0;
		while (help < star->kpr5)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}*/
}

void	e_starpreitwo(int help, t_bdr *star)
{
//	int j;
//	j = 0;
//	if (star->kpr5 <= 1)
//		j = 1;
	if ((star->kpr5 == 0) && star->kpr4 == 0)
		ft_putchar(' ', &*star);
	else if ((star->kpr4 == 0) && (star->kpr5 > star->hold))
	{
		star->kpr5 = star->kpr5 -star->hold;
		while(help <= star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
	}
	else if ((star->kpr4 == 0) && (star->kpr2 != 0) && (star->kpr2 > 0))
		ft_putchar('0', &*star);
	else if ((star->kpr5 > star->kpr2) && (star->kpr4 > 0))
	{
		star->kpr5 = star->kpr5 -star->hold;
		while(help < star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
		ft_putnbr(star->kpr4, &*star);
	}
	else if ((star->kpr5 > star->kpr2) && (star->kpr4 < 0))
	{
		ft_putchar('-', &*star);
		star->kpr5 = star->kpr5 +1;
		star->kpr5 = star->kpr5 -star->hold;
		while(help < star->kpr5)
		{
			ft_putchar('0', &*star);
			help++;
		}
		help = 1;
		while (help < star->hold)
		{
			ft_putchar(star->aux_outnbr[help], &*star);
			help++;
		}
	}
	else if (star->kpr2 >= star->kpr5)
		ft_putnbr(star->kpr4, &*star);
	if ((star->kpr3 > star->kpr5 ))
	{
		star->kpr5 = star->kpr3 -star->kpr5 -star->hold;		
		help = 0;
		while (help < star->kpr5)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
}


void	e_zhalf(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
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
			/*if ((fmt[*aux] == 'd') || (fmt[*aux] == 'i'))
			{
				*aux = *aux + 1;
				print_int_noflag(&*star);
				print_while(fmt, &*aux, &*star);
			}*/
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
		else if ((fmt[*aux] == 'i') | (fmt[*aux] == 'd'))
		{
			*aux = *aux + 1;
			print_int_noflag(&*star);
			print_while(fmt, &*aux, &*star);
		}
	}
}

void	dea_zero_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux + 1;
		ft_print_int_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	e_dztwo(tobeconv, fmt, &*aux, &*star);
	if (fmt[*aux] == '.')
	{
		*aux = *aux + 1;
		if ((fmt[*aux] == 'i') | (fmt[*aux] == 'd'))
			ft_print_int_zero(tobeconv, &*star);
		else if (fmt[*aux] == '0')
			d_pre_zer(tobeconv, fmt, &*aux, &*star);
		else if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
			e_zeronb(tobeconv, fmt, &*aux, &*star);
		else
		{
			*aux = *aux + 1;
			pri_nbr_pre(tobeconv, &*star);
		}
		print_while(fmt, &*aux, &*star);
	}
}

void	e_zeronb(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
	char	*tbvv;

	tbvv = ft_calloc(malloc_index(fmt, &*aux), sizeof(char));
	tbvv = converter(tbvv, fmt, &*aux);
	if (fmt[*aux] == 's')
		pri_pre_wnbr(tobeconv, tbvv, &*star);
	else if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		p_nbr_pre_i(tobeconv, tbvv, &*star);
	else if (fmt[*aux] == 'u')
		pri_pre_u_wnbr(tobeconv, tbvv, &*star);
	else if (fmt[*aux] == 'x')
		pri_pre_x_wnbr(tobeconv, tbvv, &*star);
	else if (fmt[*aux] == 'X')
		pri_pre_xx_wnbr(tobeconv, tbvv, &*star);
	*aux = *aux + 1;
	free(tbvv);
	tbvv = NULL;
}

void	e_dztwo(char *tobeconv, const char *fmt, int *aux, t_bdr *star)
{
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
	else if (((fmt[*aux] == '%') && (fmt[*aux - 1] == '0')) || ((fmt[*aux] == '%') && (fmt[*aux - 1] >= '1' && fmt[*aux -1] <= '9')))
	{
		*aux = *aux + 1;
		pri_per_zerownbr(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
}
