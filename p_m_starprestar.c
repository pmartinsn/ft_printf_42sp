/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_m_starprestar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:07:04 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/30 11:44:33 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

int	e_mstarprestari(t_bdr *star)
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
	if ((star->kpr3 == 0) && (star->kpr4 == 0) && ((star->kpr5 > -1) && (star->kpr5 <= 0)))
		return (0);
	else if ((star->kpr3 == 2) && (star->kpr5 == -2))
		e_mstarpreitwo(help, &*star);
	else
		e_mstarprei(help, &*star);
	free(star->aux_outnbr);
	star->aux_outnbr = NULL;
	return (0);
}


void	e_mstarpreitwo(int help, t_bdr *star)
{
	int j;
	j = 0;
	if ((star->kpr5 == 0) && (star->kpr4 == 0) && (star->kpr3 < 0))
	{
		ft_putchar(' ', &*star);
		if (star->kpr3 < -1 )
			ft_putchar(' ', &*star);
	}
	else if ((star->kpr5 == 0) && (star->kpr4 == 0) && (star->kpr3 = 1))
	{
		ft_putchar(' ', &*star);
		//if (star->kpr3 < -1 )
		//	ft_putchar(' ', &*star);
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
		help = 0;
		star->kpr3 = star->kpr3 - j- star->hold ;
		while(help < star->kpr3)
		{
			ft_putchar(' ', &*star);
			help++;
		}
		help = 1;
		while (help < star->hold)
		{
			ft_putchar(star->aux_outnbr[help], &*star);
			help++;
		}
	}
	else if ((star->kpr4 >= 0))
	{
		help = 0;
		if (((star->kpr4 == 0) || (star->hold == 1)) && (star->kpr3 < 0))
			star->kpr3 = star->kpr3 *-1;
		j = 0;
		star->kpr5 = star->kpr5 - star->hold;
		while(j < star->kpr5)
		{
			ft_putchar('0', &*star);
			j++;
		}
		ft_putnbr(star->kpr4, &*star);
		help = 0;
		if (star->kpr3 > j)
		{
			star->kpr3 = star->kpr3 - star->hold - j;
			while(help < star->kpr3)
			{
				ft_putchar(' ', &*star);
				help++;
			}
		}
		
	}
}

void	e_mstarprei(int help, t_bdr *star)
{
	int j;
	j = 0;
	if ((star->kpr5 == 0) && (star->kpr4 == 0) && (star->kpr3 < 0))
	{
		ft_putchar(' ', &*star);
		if (star->kpr3 < -1 )
			ft_putchar(' ', &*star);
	}
	else if ((star->kpr5 == 0) && (star->kpr4 == 0) && (star->kpr3 = 1))
	{
		ft_putchar(' ', &*star);
		//if (star->kpr3 < -1 )
		//	ft_putchar(' ', &*star);
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
		star->kpr3 = star->kpr3 - j- star->hold ;
		while(help < star->kpr3)
		{
			ft_putchar(' ', &*star);
			help++;
		}
	}
	else if ((star->kpr4 >= 0))
	{
		help = 0;
		if (((star->kpr4 == 0) || (star->hold == 1)) && (star->kpr3 < 0))
			star->kpr3 = star->kpr3 *-1;
		j = 0;
		star->kpr5 = star->kpr5 - star->hold;
		while(j < star->kpr5)
		{
			ft_putchar('0', &*star);
			j++;
		}
		ft_putnbr(star->kpr4, &*star);
		help = 0;
		if (star->kpr3 > j)
		{
			star->kpr3 = star->kpr3 - star->hold - j;
			while(help < star->kpr3)
			{
				ft_putchar(' ', &*star);
				help++;
			}
		}
	}
}
