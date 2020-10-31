/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flag_b_wnbrs_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:40:59 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 18:41:03 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int_wnumb(char *tobeconv, bdr *star)
{
	int		help;
	int		j;
	char	*character;
	
	character = "tryme";
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	star->ret__ = ft_strlen(character);
	if(star->ret__ > j)
		j = star->ret__;
		else
		j =  j - star->ret__;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putnbr(star->kpr8, &*star);
	free(character);

}

void	print_s_wnumb(char *tobeconv, bdr *star)
{
	int	help;
	int	j;


	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	if(star->hold > j)
		j = star->hold;
		else j =  j -star->hold;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
}