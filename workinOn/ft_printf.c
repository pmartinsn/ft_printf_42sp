/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:44:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/09 16:59:23 by pmartins         ###   ########.fr       */
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
int	dealing_minus(const char *fmt, int *aux, va_list list)
{
//	printf("\nentrou dealing minus\n");
	int index;
	char *tobeconv;
	
	index= 0;
	tobeconv = malloc(*aux * 3);
	// tem qe descobrir se tem um numero depois...
	//se só tiver o '-' não faz nada, se tiver algum numero depois ai ele dá eesse valor em espaçosmenos a quantidade de caracteres na variavel
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'x')
	| (fmt[*aux] == 'X') | (fmt[*aux] == 'u'))
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
				if((fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'x')
				| (fmt[*aux] == 'X') | (fmt[*aux] == 'u'))
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
				if((fmt[*aux] == 'c') | (fmt[*aux] == 's'))
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
			}			
		}

	}
	/*if(fmt[*aux] == '.'){
	}*/
	return(*aux);	
}
	

int		no_flags(const char *fmt, int *aux, va_list list) {
	if( (fmt[*aux] == 'd') | (fmt[*aux] == 'i') | (fmt[*aux] == 'o')
	/*| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))*/ /*(fmt[*aux] == 'u') u é um caso especialfuncao ŕa chamar o numero excedente*/ )
	{
		*aux = *aux +1;
		ft_putnbr(va_arg(list, int));
	}
	if((fmt[*aux] == 's') | (fmt[*aux] == 'c'))
	{
		*aux = *aux +1;
		ft_putstr(va_arg(list, char*));
	}
	if((fmt[*aux] == 'p') | (fmt[*aux] == '%'))
	{
		*aux = *aux +1;
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
	/*if(fmt[*aux] == '.'){
		returned = dealing_precision(fmt, &aux, list);
	}
	if(fmt[*aux] == '0'){
		returned = dealing_zero(fmt, &aux, list);
	}
	if(fmt[*aux] == '*'){
		returned = dealing_star(fmt, &aux, list);
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
	}else
	{
		no_flags(fmt, &*aux, list);
		/*caso ele não achei flags pra onde vai? */
	}
	
//	if(fmt[*aux] == 'i'){
//	printf("%s\n",fmt);
//	temp = va_arg(list, int);
//	printf("%i\n",temp);
//	}
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
	/*
	typedef struct st_variables
	{
		char
		int j;
		char *temp;
		char *keeper;
	};
	
	struct st_variables em1;
	em1.i = 1;
	*/
	
	
	//va_list	prtf;
	//va_start(prtf, fmt);
	
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
			
		
			if( (fmt[i] == 'd') | (fmt[i] == 'i') | (fmt[i] == 'x') | (fmt[i] == 'X') | (fmt[i] == 'u') )
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
			if(	(fmt[i] == 'p') |	)
			{
				j++;
				keeper = va_arg(prtf, double);
				temp = ft_itoa(keeper);
				ft_putstr(temp);
			}
			i++;
			if(fmt[i] == '\n')
				ft_putchar('\n'); 
		
	}*/ //va_end(prtf); 
//	}
//return(0);}