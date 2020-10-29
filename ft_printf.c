/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:43:30 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/29 10:58:19 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"

void	find_flag(const char *fmt, int *aux, bdr *star)
{	
	if(fmt[*aux] == '-')
	{
		*aux = *aux +1;
		 dealing_minus(fmt, &*aux, &*star); 
	}
	else if(fmt[*aux] == '.'){
		*aux = *aux +1;
		dealing_precision(fmt, &*aux, &*star);
	}
	//if(fmt[*aux] == '0'){
	//	returned = dealing_zero(fmt, &*aux, &*star);
	//}
	/*
	if(fmt[*aux] == '*'){
		returned = dealing_star(fmt, &*aux,&*star);
	}*/
//	return(returned_ff);
}
int sortie(const char *fmt, int *aux, bdr *star)
{	
	if((fmt[*aux] == '-') | (fmt[*aux] == '.')| (fmt[*aux] == '0') 
	|(fmt[*aux] == '*'))
	{
		find_flag(fmt, &*aux, &*star);
	}if((fmt[*aux] != '0') && (fmt[*aux]  >= '1' && fmt[*aux]  <= '9'))
		nfw_nbr(fmt, &*aux, &*star);//SEM FLAGS MAS COM NUMEROS
	else
	{
		no_flags(fmt, &*aux, &*star);
	}
return(0);
}

int					get_info(const char *fmt, bdr *star)
{
	int	aux;
	
	aux = 0;
	while (fmt[aux])
	{	
		if((fmt[aux] == '%') && fmt[aux +1] == '%')
		{
			aux = aux + 2;
			ft_putchar('%',  &*star);
		}
		if((fmt[aux] == '%') && (fmt[aux +1] != '%'))
		{
			aux++;
			star->returned_s = sortie(fmt, &aux, &*star);
		}
		if (fmt[aux] != '\0' && fmt[aux] != '%')
		{
			//printf("%i",i);
			ft_putchar(fmt[aux],  &*star);
			aux++;
		}
	}

	return (0);
}
int				ft_printf(const char *fmt, ...)
{
	bdr star;
//	int		result;
//	int		result2;
	
//	result = 0;
//	result2 = 0;
	init_bdr(&star);
//	star.variables_counted = count_variables1(fmt);
//	printf("----saida variaveis:%i\n",star.variables_counted);
	va_start(star.list, fmt);
	//result = 
	get_info(fmt, &star);
	va_end(star.list);
//	result2 = star.variables_counted + result;
	return(star.count);
}