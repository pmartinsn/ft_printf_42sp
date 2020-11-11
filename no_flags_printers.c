/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flags_printers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:39:44 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/11 18:29:18 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

int	print_s_noflag(t_bdr *star)
{
	if(!(star->aux_outnbr = va_arg(star->list, char*)))
	{
		ft_putstr("(null)", &*star);
		return (0);
	}
	star->hold = ft_strlen(star->aux_outnbr);
	ft_putstr(star->aux_outnbr, &*star);
	return (star->hold);
}

int	print_int_noflag(t_bdr *star)
{
	star->hold = va_arg(star->list, int);
	star->helpint = ft_itoa(star->hold);
	ft_putnbr(star->hold, &*star);
	star->hold = ft_strlen(star->helpint);
	star->keeper = star->keeper + star->hold;
	free(star->helpint);
	return (star->keeper);
}

int	print_char_noflag(t_bdr *star)
{
	int		i;
	char	charr;

	i = 0;
	i = va_arg(star->list, int);
	charr = (char)i;
	ft_putchar(charr, &*star);
	return (1);
}

int	print_p_noflag(t_bdr *star)
{
	size_t	num;
	char	*character;

	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr3 = ft_strlen(character);
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	free(character);
	return (star->kpr3 + 2);
}

int	print_u_noflag(t_bdr *star)
{
	size_t	num;
	char	*character;

	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 10, 'a');
	star->kpr5 = ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	return (star->kpr5);
}
