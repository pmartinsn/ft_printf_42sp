/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:43:30 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/27 07:38:04 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"

void				nfw_nbr(const char *fmt, int *aux, bdr *star)
{
	int index;
	char *tobeconv;
	
	index= 0;
	tobeconv = malloc(*aux * 3);
	if((fmt[*aux] != '0') && (fmt[*aux]  >= '1' && fmt[*aux]  <= '9') )
	{	//printf("entrou na verificação\n");	
		tobeconv[index]= fmt[*aux];
		index++;
		*aux = *aux + 1;
		while(fmt[*aux]  >= '0' && fmt[*aux]  <= '9')
		{
			tobeconv[index]= fmt[*aux];
			index++;
			*aux = *aux + 1;
		
			if((fmt[*aux] != '1') | (fmt[*aux] != '2') | (fmt[*aux] != '3')
			| (fmt[*aux] != '4') | (fmt[*aux] != '5') | (fmt[*aux] != '6')
			| (fmt[*aux] != '7') | (fmt[*aux] != '8') | (fmt[*aux] != '9')
			| (fmt[*aux] != '0'))
			{
				if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
				{
					*aux = *aux +1;
					star->ret__ = ft_print_int_wnumb(tobeconv, &*star);
				}
			}
		}
	}
	free(tobeconv);
}


void	dealing_minus(const char *fmt, int *aux, bdr *star)
{
	int index;
	char *tobeconv;
	
	index= 0;
//	star->ret_minustotal = 0;
	tobeconv = malloc(*aux * 3);
	if((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		//star->retminus1 = 
		no_flags(fmt, &*aux, &*star);
		/*star->ret_minustotal = star->ret_minustotal + star->retminus1;
		star->retminus1 = 0;*/
	}
	if((fmt[*aux] != '0') && (fmt[*aux]  >= '1' && fmt[*aux]  <= '9') )
	{	//printf("entrou na verificação\n");	
		tobeconv[index]= fmt[*aux];
		index++;
		*aux = *aux + 1;
		while(fmt[*aux]  >= '0' && fmt[*aux]  <= '9')
		{
			tobeconv[index]= fmt[*aux];
			index++;
			*aux = *aux + 1;
		
			if((fmt[*aux] != '1') | (fmt[*aux] != '2') | (fmt[*aux] != '3')
			| (fmt[*aux] != '4') | (fmt[*aux] != '5') | (fmt[*aux] != '6')
			| (fmt[*aux] != '7') | (fmt[*aux] != '8') | (fmt[*aux] != '9')
			| (fmt[*aux] != '0'))
			{
				if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
				{
					*aux = *aux +1;
					ft_print_int_minuswnumb(tobeconv, &*star);
					
				//	 SÓ INVERTER A ORDEM DE IMPRESSÃO PARA FAZER AS OUTRAS
				//	printf("retwnum:%d\n", star->ret_minustotal);
					/*int j;
					int i;
					int y;
					int help;
					char *character;
					help = 0;
					j = ft_atoi(tobeconv);
					i = va_arg(star->list, int);
					character = ft_itoa(i);
					y = ft_strlen(character);
					j = j - y;
					ft_putnbr(i);
					while(help < j){
						ft_putchar(' ');
						help++;
					}*/
				}
				if((fmt[*aux] == 's'))
				{
					*aux = *aux +1;
					int j;
					char *i;
					int y;
					int help;
					help = 0;
					j = ft_atoi(tobeconv);
					i = va_arg(star->list, char*);
						y = ft_strlen(i);
					j = j - y;
					ft_putstr(i);
					while(help < j){
						ft_putchar(' ');
						help++;
					}
				}
				if(fmt[*aux] == 'c')
				{
					*aux = *aux +1;
					int j;
					int i;
					char charr;
					int help;
					help = 0;
					j = ft_atoi(tobeconv);
					i = va_arg(star->list, int);
					charr = (char)i;
					j = j - 1;
					ft_putchar(charr);
					while(help < j){
						ft_putchar(' ');
						help++;
					}
				}
				if((fmt[*aux] == 'p'))
				{//FALTA RESOLVER ISSO AQUI MOOÇAAAA
					
					*aux = *aux +1;
					
					}
				}
			}
		}	
		free(tobeconv);
	}

	/*}
	if(fmt[*aux] == '.'){
	}
	
		
}*/
void	find_flag(const char *fmt, int *aux, bdr *star)
{	
//	int returned_ff = 0;
//	int temp = 0;
	if(fmt[*aux] == '-')
	{
		*aux = *aux +1;
		 dealing_minus(fmt, &*aux, &*star); 
	//	returned_ff = star->ret_minustotal + returned_ff;
	//	star->ret_minustotal = star->ret_minustotal + returned_ff;
	//	star->ret_minustotal = 0;
	}
	/*if(fmt[*aux] == '.'){
		*aux = *aux +1;
		returned_ff = dealing_precision(fmt, &*aux, star->list);
	}*/
	//if(fmt[*aux] == '0'){
	//	returned = dealing_zero(fmt, &*aux, star->list);
	//}
	/*
	if(fmt[*aux] == '*'){
		returned = dealing_star(fmt, &*aux,star->list);
	}*/
//	return(returned_ff);
}
int sortie(const char *fmt, int *aux, bdr *star)
{
	int rett;

	rett = 0;	
	if((fmt[*aux] == '-') | (fmt[*aux] == '.')| (fmt[*aux] == '0') 
	|(fmt[*aux] == '*'))
	{
		find_flag(fmt, &*aux, &*star);
	}if((fmt[*aux] != '0') && (fmt[*aux]  >= '1' && fmt[*aux]  <= '9'))
		nfw_nbr(fmt, &*aux, &*star);//SEM FLAGS MAS COM NUMEROS
	else
	{
	//	printf("\naux antes das flags:%i\n", *aux);
	//	returned_sortie2 = 
		no_flags(fmt, &*aux, &*star);
	/*	rett =  rett + returned_sortie2;
		returned_sortie2 = 0;*/
		/*caso ele não achei flags pra onde vai? */
	}
return(/*returned_sortie + returned_sortie2*/rett);
}

int					get_info(const char *fmt, bdr *star)
{
	int	aux;
	
	aux = 0;
	star->chars_counted = count_chars(fmt, &*star);
	printf("--------saida chars:%i\n",star->chars_counted);
	while (fmt[aux])
	{	
		if((fmt[aux] == '%') && fmt[aux +1] == '%')
		{
			aux = aux + 2;
			ft_putchar('%');
		}
		if((fmt[aux] == '%') && (fmt[aux +1] != '%'))
		{
			aux++;
			star->returned_s = sortie(fmt, &aux, &*star);
		}
		if (fmt[aux] != '\0' && fmt[aux] != '%')
		{
			//printf("%i",i);
			ft_putchar(fmt[aux]);
			aux++;
		}
	}
//	index = star->returned_s + star->chars_counted ;
	return (star->chars_counted /*+ star->variables_counted*/);
}
int				ft_printf(const char *fmt, ...)
{
	bdr star;
	int		result;
	int		result2;
	
	result = 0;
	result2 = 0;
	init_bdr(&star);
	star.variables_counted = count_variables1(fmt);
	printf("----saida variaveis:%i\n",star.variables_counted);
	va_start(star.list, fmt);
	result = get_info(fmt, &star);
	va_end(star.list);
	result2 = star.variables_counted + result;
	return(result2);
}