/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flags_prenters_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:39:26 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/25 18:46:54 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

int	print_x_noflag(t_bdr *star)
{
	size_t	num;
	char	*character;

	num = 0;
	star->conversion = 'x';
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a', &*star);
	star->kpr6 = ft_strlen(character);
	ft_putstr(character, &*star);
//	free(character);
	return (star->kpr6);
}

int	print_xx_noflag(t_bdr *star)
{
	size_t	num;
	char	*character;

	num = 0;
	star->conversion = 'x';
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A', &*star);
	star->kpr7 = ft_strlen(character);
	ft_putstr(character, &*star);
	//free(character);
	return (star->kpr7);
}
