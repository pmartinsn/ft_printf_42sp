/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:44:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/11 16:57:52 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>
int				ft_strlen(char *str);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
void			ft_putstr(char *s);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
int dealing_zero(const char *fmt, int *aux, va_list list){
	
}
int dealing_precision(const char *fmt, int *aux, va_list list)
{
	int index;
	char *tobeconv;
	
	index= 0;
	tobeconv = malloc(*aux * 3);
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i') /*| (fmt[*aux] == 'x')
	| (fmt[*aux] == 'X') | (fmt[*aux] == 'u')*/)
		{
			*aux = *aux +1;
			ft_putnbr(va_arg(list, int));
		}
	if(fmt[*aux] == 's')//s sem numero imprime NADA
	{
		*aux = *aux +1;
		//ft_putstr(va_arg(list, char*));
	}
	while((fmt[*aux] == '1') | (fmt[*aux] == '2') | (fmt[*aux] == '3')
	| (fmt[*aux] == '4') | (fmt[*aux] == '5') | (fmt[*aux] == '6')
	| (fmt[*aux] == '7') | (fmt[*aux] == '8') | (fmt[*aux] == '9') 
	| (fmt[*aux] == '0'))
	{
		tobeconv[index]= fmt[*aux];
		index++;
		*aux = *aux + 1;
	}
	if((fmt[*aux] != '1') | (fmt[*aux] != '2') | (fmt[*aux] != '3')
	| (fmt[*aux] != '4') | (fmt[*aux] != '5') | (fmt[*aux] != '6')
	| (fmt[*aux] != '7') | (fmt[*aux] != '8') | (fmt[*aux] != '9')
	| (fmt[*aux] != '0'))
	{
		if((fmt[*aux] == 'd') | (fmt[*aux] == 'i')/* | (fmt[*aux] == 'x')
		| (fmt[*aux] == 'X') | (fmt[*aux] == 'u')*/)
		{
			*aux = *aux +1;
			int j;
			int i;
			int y;
			int help;
			char *character;
			help = 0;
			j = ft_atoi(tobeconv);
			i = va_arg(list, int);
			if(i < 0 )
			{
				i = i * -1;
				character = ft_itoa(i);
				y = ft_strlen(character);
				j = j - y;
				ft_putchar('-');
				while(help < j){
					ft_putchar('0');
					help++;
				}
			ft_putnbr(i);
			}else
			{
				character = ft_itoa(i);
				y = ft_strlen(character);
				j = j - y;
				while(help < j){
				ft_putchar('0');
					help++;
				}
				ft_putnbr(i);
			}
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
			i = va_arg(list, char*);
			y = ft_strlen(i);
			if( y < j){
				while(i[help] != '\0'){
				ft_putchar(i[help]);
				help++;
				}
			}
			if( y > j){
				while(help < j){
				ft_putchar(i[help]);
				help++;
				}
			}
		}
	}
	
	
	return(*aux);	
}
int	dealing_minus(const char *fmt, int *aux, va_list list)
{
//	printf("\nentrou dealing minus\n");
	int index;
	char *tobeconv;
	
	index= 0;
	tobeconv = malloc(*aux * 3);
	// tem qe descobrir se tem um numero depois...
	//se só tiver o '-' não faz nada, se tiver algum numero depois ai ele dá eesse valor em espaçosmenos a quantidade de caracteres na variavel
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i')/* | (fmt[*aux] == 'x')
	| (fmt[*aux] == 'X') | (fmt[*aux] == 'u')*/)
		{
			*aux = *aux +1;
			ft_putnbr(va_arg(list, int));
		}
	if((fmt[*aux] == 'c') | (fmt[*aux] == 's'))
	{
		*aux = *aux +1;
		ft_putstr(va_arg(list, char*));
		
	}
	if((fmt[*aux] != '0')){
		if((fmt[*aux] == '1') | (fmt[*aux] == '2') | (fmt[*aux] == '3')
			| (fmt[*aux] == '4') | (fmt[*aux] == '5')| (fmt[*aux] == '6')
			| (fmt[*aux] == '7')| (fmt[*aux] == '8')| (fmt[*aux] == '9'))
			{	//printf("entrou na verificação\n");	
			tobeconv[index]= fmt[*aux];
			index++;
			*aux = *aux + 1;
			if((fmt[*aux] == '1') | (fmt[*aux] == '2') | (fmt[*aux] == '3')
			| (fmt[*aux] == '4') | (fmt[*aux] == '5') | (fmt[*aux] == '6')
			| (fmt[*aux] == '7') | (fmt[*aux] == '8') | (fmt[*aux] == '9') 
			| (fmt[*aux] == '0'))
			{
				tobeconv[index]= fmt[*aux];
				index++;
				*aux = *aux + 1;
			}
			if((fmt[*aux] != '1') | (fmt[*aux] != '2') | (fmt[*aux] != '3')
			| (fmt[*aux] != '4') | (fmt[*aux] != '5') | (fmt[*aux] != '6')
			| (fmt[*aux] != '7') | (fmt[*aux] != '8') | (fmt[*aux] != '9')
			| (fmt[*aux] != '0'))
			{
				if((fmt[*aux] == 'd') | (fmt[*aux] == 'i')/* | (fmt[*aux] == 'x')
				| (fmt[*aux] == 'X') | (fmt[*aux] == 'u')*/)
				{
					*aux = *aux +1;
					int j;
					int i;
					int y;
					int help;
					char *character;
					help = 0;
					j = ft_atoi(tobeconv);
					i = va_arg(list, int);
					character = ft_itoa(i);
					y = ft_strlen(character);
					j = j - y;
					ft_putnbr(i);
					while(help < j){
						ft_putchar(' ');
						help++;
					}
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
					i = va_arg(list, char*);
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
					i = va_arg(list, int);
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
					/*
					*aux = *aux +1;
					int j;
					char *i;
					char *ptr;
					int y;
					int help;
					help = 0;
					j = ft_atoi(tobeconv);
					i = va_arg(list, char*);
					ptr= malloc(100);
					*ptr = &*i;
					y = ft_strlen(ptr);
					j = j - y;
					//printf("\n\n%s\n\n", i);
					ft_putstr(ptr);
					while(help < j)
					{
						ft_putchar(' ');
						help++;
					}
					*aux = *aux +1;
					int j;
					int *i;
					int y;
					int help;
					char *character;
					help = 0;
					j = ft_atoi(tobeconv);
					*i = va_arg(list, int);
					//printf("\n\n%i\n\n", i);
					character = ft_itoa(i);
					y = ft_strlen(character);
					j = j - y;
					ft_putstr(character);
					//ft_putnbr(i);
					while(help < j){
						ft_putchar(' ');
						help++;
					}*/
				}
			}			
		}

	}
	/*if(fmt[*aux] == '.'){
	}*/
	return(*aux);	
}
	

int		no_flags(const char *fmt, int *aux, va_list list) {
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	/*| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))*/ /*(fmt[*aux] == 'u') u é um caso especialfuncao ŕa chamar o numero excedente*/
	{
		*aux = *aux +1;
		ft_putnbr(va_arg(list, int));
	}
	if(fmt[*aux] == 's')
	{
		*aux = *aux +1;
		ft_putstr(va_arg(list, char*));
	}
	if(fmt[*aux] == 'c'){
		*aux = *aux +1;
		int i;
		char charr;
		i = va_arg(list, int);
		charr = (char)i;
		ft_putchar(charr);
	}
	if((fmt[*aux] == 'p') | (fmt[*aux] == '%'))
	{
		*aux = *aux +1;
		//FALTA DESCOBRIR COMO FAZ ESSA DROGA
	}
	return(*aux);
}


int	find_flag(const char *fmt, int *aux, va_list list)
{
//	printf("\nentrou find flag\n");
	int returned;
	if(fmt[*aux] == '-'){
		*aux = *aux +1;
		returned = dealing_minus(fmt, &*aux, list); 
	}
	if(fmt[*aux] == '.'){
		*aux = *aux +1;
		returned = dealing_precision(fmt, &*aux, list);
	}
	if(fmt[*aux] == '0'){
		returned = dealing_zero(fmt, &*aux, list);
	}/*
	if(fmt[*aux] == '*'){
		returned = dealing_star(fmt, &*aux, list);
	}*/
	return(returned);
}

int sortie(const char *fmt, int *aux, va_list list)
{
//	printf("\nentrou sortie\n");
//	int temp = 0;
	//va_list h=list;
	//int i= *aux;
	//printf("teste 2 :%i\n",*aux);
	int returned = 0;	
	//*aux = *aux +1;
//	printf("teste :%i\n",*aux);
	if((fmt[*aux] == '-') | (fmt[*aux] == '.')| (fmt[*aux] == '0') 
	|(fmt[*aux] == '*')){
		returned = find_flag(fmt, &*aux, list);
	}else//FALTA INCLUIR SEM FLAGS MAS COM NUMEROS
	{
		no_flags(fmt, &*aux, list);
		/*caso ele não achei flags pra onde vai? */
	}
	return(returned);
}

int					get_info(const char *fmt, va_list list)
{
	int	i;
	i = 0;
	int returned;
	returned = 0;
	//size_t	index;
	while (fmt[i])
	{		
		if (fmt[i] == '%')
		{
			i++;
//			printf("\nbefore sortie:%s\n",fmt);
			returned = sortie(fmt, &i, list );
			//return(returned);
		}
		else
			if (fmt[i] != '\0' && fmt[i] != '%'){
				//printf("%i",i);
				ft_putchar(fmt[i]);
				i++;
			}
	}
	return (returned);
}
int				ft_printf(const char *fmt, ...)
{
	va_list	list;
	int		result;
	
	va_start(list, fmt);
	result = get_info(fmt, list);
	va_end(list);
	return(result);
}