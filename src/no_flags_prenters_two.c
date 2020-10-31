/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flags_prenters_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:39:26 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 18:17:44 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x_noflag( bdr *star)
{
	size_t	num;
	char	*character;

	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6= ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	return(star->kpr6);
}

int	print_X_noflag(bdr *star)
{
	size_t	num;
	char	*character;

	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr7= ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	return(star->kpr7);
}