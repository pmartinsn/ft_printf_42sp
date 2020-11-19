/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:33:26 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/19 09:59:49 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char*)s;
	while (n--)
	{
		*(ptr) = '\0';
		ptr++;
	}
}
