/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:37:18 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/02 13:59:43 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	init_bdr(t_bdr *star)
{
	star->count = 0;
	star->variables_counted = 0;
	star->hold = 0;
	star->keeper = 0;
	star->kpr2 = 0;
	star->kpr3 = 0;
	star->kpr4 = 0;
	star->kpr5 = 0;
	star->kpr6 = 0;
	star->kpr7 = 0;
	star->kpr8 = 0;
	star->ret_p = 0;
	star->ret__ = 0;
	star->count_arg = 0;
	star->yndex = 0;
	star->yndex2 = 0;
	star->bugfix = 0;
	star->ret_sortie = 0;
}
