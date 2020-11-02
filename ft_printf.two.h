/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.two.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:49:45 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 14:06:06 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TWO_H
# define FT_PRINTF_TWO_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <inttypes.h>

typedef	struct	s_pf
{
	va_list	list;
	int		count;
	int		returned_s;
	char	*aux_outnbr;
	char	*helpint;
	int		hold;
	int		keeper;
	int		kpr2;
	int		kpr3;
	int		kpr4;
	int		kpr5;
	int		kpr6;
	int		kpr7;
	int		kpr8;
	int		ret_p;
	int		ret__;
	int		count_arg;
	int		yndex;
	int		yndex2;
	int		variables_counted;
	int		bugfix;
	int		ret_sortie;
	int		returned;
}				t_bdr;

#endif
