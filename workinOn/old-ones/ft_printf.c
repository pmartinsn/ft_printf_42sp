/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:49:12 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/01 13:07:17 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//int				ft_printf(const char *fmt, ...)


	//Usar um WRITE dentro de um while pra imprimir
	//Pensa que o va_list é tipo o open o va_arg é tipo um read, e cada vez que damos o va_arg ele se encrementa.
	//na prototipagem do printf o const char* é a string que fica sempre entre "string" no printf da stdio.h
	// o que vem depois da virgula "..." são os especificadores quando a gente coloca um %d e tem que dizer qual 
	//é a variavel que queremos imprimir naquele %d.
	//a cada cacactere temos que verificar se ele é um % pq se for temos que ver qual tipo ele é, e isso vai apontar para uma 
	//outra variavel, aquelas depois da virgula, então o % é um sinalizador que o que tem depois não é apenas um char e sim um indicador 
	//do tipo de info que ele quer imprimir

	// no while que rod ela para a impressão,. falamos a algo=va_arg. Ai agora imprime o "algo"
	//va_list args;
	///va_start(args, fmt);{
	//va_arg(args, int);
	//}va_end(args);
//	PRECISO- aprender como funcionam as flags pra poder copiar o comportamento
//	*** depois*** usar as structs
/* FLAGS:
o "."
*/


/*d double
i int
s __STRING
c char
p endereço de ponteiro
n 
u 

variadic va_arg va_end va_copy

printf("Valor e data: %d %s/n", count, data)*/

#include "printf.h"



/*int	ft_printf(const char *fmt, ...)
{
	va_list	prtf;

	//printf("entrou");
	//char	*temp;
	
	float 	keeper;
	int i;
	//int index;

	int guardian;
	int 	j;
	//guardian = fmt;
	//printf("entrou2");
	

	//index = ft_strlen(fmt); 
	i = 0;
	j = 0;
	//printf("%s", guardian);
	//queria saber quaal o tamanho da string que entra, pra inicializar o guardian...
	//fazer uma função que conte exatamente quantos caracteres tem, a mesma base da printf com o varg/valist

	va_start(prtf, fmt);
	//guardian = ft_validade_and_parse(fmt, prtf);


	while (fmt[i + 1] != '\0' && fmt[i])
	{
		i++;
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
		
	} va_end(prtf); 
	}return(0);
}*/
