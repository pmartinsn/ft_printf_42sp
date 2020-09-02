/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:44:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/02 11:57:50 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"
/*
typedef struct 
{
	char zero;
	int width;
	int precision;
	char minus;
} st_flags;

char	ft_discovery(char *a, char *b)
{
	
}
*/
int				ft_printf(const char *fmt, ...)
{
/*	typedef struct st_variables
	{
		int i;
		int j;
		char *temp;
		char *keeper;
	} st_variables;
	
	*/
	
	va_list	prtf;
	va_start(prtf, fmt);
	
	/*
	j = 0;
	while (fmt[i + 1] != '\0' && fmt[i])
	{
		keeper[j] = fmt[i];
		i++;
		j++;
		if(fmt[i] == '%'){
			ft_discovery(keeper[j], fmt[i]);
		}
		while (fmt[i] != '%' && fmt[i] )
		{			
			temp = va_arg(prtf, char*);
			j++;
			i++;
		
		}
		//escrever função de validação 
		if(fmt[i] == '%')
		{
			i++;
			
		
			if( (fmt[i] == 'd') | (fmt[i] == 'i') | (fmt[i] == 'o')|\
			(fmt[i] == 'x') | (fmt[i] == 'X') | (fmt[i] == 'u') )
			{
				j++;
				ft_putnbr(va_arg(prtf, int));
			}
			if((fmt[i] == 's') | (fmt[i] == 'c'))
			{
				j++;
				temp = va_arg(prtf, char*);
				ft_putstr(temp);
			}
			if((fmt[i] == 'f') | (fmt[i] == 'e') | (fmt[i] == 'E') |\
			(fmt[i] == 'g') | (fmt[i] == 'G'))
			{
				j++;
				keeper = va_arg(prtf, double);
				temp = ft_itoa(keeper);
				ft_putstr(temp);
			}
			i++;
			if(fmt[i] == '\n')
				ft_putchar('\n'); 
		
	}*/ va_end(prtf); 
//	}
return(0);}