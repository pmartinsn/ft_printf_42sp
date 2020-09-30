/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:07:39 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/12 21:29:32 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
