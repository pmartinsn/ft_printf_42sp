/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:43:30 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/30 18:08:28 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"

void	init_bdr(bdr *star){
	star->returned_s = 0;
	star->hold = 0;
	star->keeper = 0;
	star->kpr2 = 0;
	star->kpr3 = 0;
	star->kpr4 = 0;
	star->kpr5 = 0;
	star->kpr6 = 0;
	star->kpr7 = 0;
	star->ret_p = 0;
	star->ret__ = 0;
	star->count_arg = 0;
	star->yndex = 0;
	star->yndex2 = 0;
	star->retminus1 = 0;
	star->ret_minustotal = 0;
	star->ret_dealing = 0;
	star->bugfix = 0;
	star->ret_sortie = 0;

//	star->returned_s = 0;
	
}
// fazer uma função que conta argumentos
/*int	count_chars2(const char *fmt, bdr *star)
{
	while(fmt[star->yndex] != '\0')
	{
		if (fmt[star->yndex]== '%' && fmt[star->yndex +1] != '%')
		{
			star->count_arg++;
		}
		star->yndex++;
	}
	return(star->count_arg);
}*/
int	count_chars(const char *fmt, bdr *star)
{
	while(fmt[star->yndex] != '\0')
	{
		if(fmt[star->yndex]== '%')
		{
			star->yndex++;
			if(fmt[star->yndex] != '%')
				star->count_arg++;//aqui eu tiroo % e o conversor da conta
			if(fmt[star->yndex] == '%')
			{
				star->yndex2 = star->yndex2 + 2;
				star->yndex++;
			}
			if((fmt[star->yndex] == '-') | (fmt[star->yndex] == '.') |
			(fmt[star->yndex] == '0') | (fmt[star->yndex] == '*'))
				star->bugfix++;
		}
		star->yndex++;
	}
	if(star->yndex2 > 1)
		star->yndex = star->yndex - (star->yndex2 / 2);
	star->yndex = star->yndex -(star->count_arg * 2);;
	return(star->yndex - star->bugfix);
}
int	print_s_noflag(bdr *star)
{
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	ft_putstr(star->aux_outnbr);
	return(star->hold);
}
int	print_int_noflag(bdr *star)
{
	star->hold = va_arg(star->list, int);
	star->helpint = ft_itoa(star->hold);
	ft_putnbr(star->hold);
	star->hold=ft_strlen(star->helpint);
	star->keeper = star->keeper + star->hold;
	free(star->helpint);
	return(star->keeper);
}
int	print_char_noflag(bdr *star)
{
	int i;
	char charr;
	i = va_arg(star->list, int);
	charr = (char)i;
	ft_putchar(charr);
	return(1);
}
int	print_p_noflag(bdr *star)
{
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a'/*, &*star*/);
	star->kpr3= ft_strlen(character);
	ft_putstr("0x");
	ft_putstr(character);
	free(character);
	return(star->kpr3 + 2);
}
int	print_u_noflag(bdr *star)
{
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 10, 'a'/*, &*star*/);
	star->kpr5= ft_strlen(character);
	ft_putstr(character);
	free(character);
	return(star->kpr5);
}
int	print_x_noflag( bdr *star)
{
//	printf("\nentrou  no x\n");
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6= ft_strlen(character);
	ft_putstr(character);
	free(character);
	return(star->kpr6);
}
int	print_X_noflag(bdr *star)
{
//	printf("\nentrou  no X\n");
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr7= ft_strlen(character);
	ft_putstr(character);
	free(character);
	return(star->kpr7);
}
int		no_flags2(const char *fmt, int *aux, bdr *star)
{
	if(fmt[*aux] == 'p')
	{
		*aux = *aux +1;
		star->kpr3 = print_p_noflag(&*star);
		star->ret_p = star->ret_p + star->kpr3;
		star->kpr5 = 0;
	}
	if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		star->kpr5 = print_u_noflag(&*star);
		star->ret_p = star->ret_p + star->kpr5;
		star->kpr5 = 0;
	}
	if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		star->kpr6 = print_x_noflag(&*star);
		star->ret_p = star->ret_p + star->kpr6;
		star->kpr6 = 0;
	}
	if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		star->kpr7 = print_X_noflag(&*star);
		star->ret_p = star->ret_p + star->kpr7;
		star->kpr7 = 0;
	}
	return(star->ret_p);
}
int		no_flags(const char *fmt, int *aux, bdr *star)
{
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux +1;
		star->keeper = print_int_noflag(&*star);	
		star->ret_p = star->ret_p + star->keeper;
		star->keeper = 0;
	}
	if(fmt[*aux] == 's')
	{
		*aux = *aux +1;
		star->kpr2 = print_s_noflag(&*star);
		star->ret_p = star->ret_p + star->kpr2;
		star->kpr2 = 0;
	}
	if(fmt[*aux] == 'c')
	{
		*aux = *aux +1;
		star->kpr4 = print_char_noflag(&*star);
		star->ret_p = star->ret_p + star->kpr4;
		star->kpr4 = 0;
	}
	else/*(fmt[*aux] == 'p')| (fmt[*aux] == 'x') | (fmt[*aux] == 'X'))*/ /*(fmt[*aux] == 'u') u é um caso especialfuncao ŕa chamar o numero excedente*/
	{
		no_flags2(fmt, &*aux, &*star);
	}
	return(star->ret_p);
}
int	ft_print_int_wnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;
	int y;
	char *character;
	help = 0;
	j = 0;
	y = 0;
	j = ft_atoi(tobeconv);
	star->hold = va_arg(star->list, int);
	character = ft_itoa(star->hold);
	ft_putnbr(star->hold);
	star->hold = ft_strlen(character);
	y = star->hold;
	j = j - star->hold;
	while(help < j){
		ft_putchar(' ');
		help++;
	}
/*	printf("keeper:%d", star->keeper);
	printf("j:%d", j);
	printf("hold:%d\n", star->hold);*/
	
	star->keeper =  j + y;
	
	/*printf("keeper:%d", star->keeper);
	printf("j:%d", j);
	printf("hold:%d\n", star->hold);*/
	free(character);
	
	return(star->keeper);
}
int	dealing_minus(const char *fmt, int *aux, bdr *star)
{
	//printf("\nentrou dealing minustotal:%i\n",star->ret_minustotal );
	int index;
	char *tobeconv;
	
	index= 0;
	star->ret_minustotal = 0;
	tobeconv = malloc(*aux * 3);
	if((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
	///	printf("\nentrou dealing minus\n");
		star->retminus1 = no_flags(fmt, &*aux, &*star);
		star->ret_minustotal = star->ret_minustotal + star->retminus1;
		star->retminus1 = 0;
	}
	// tem qe descobrir se tem um numero depois...
	//se só tiver o '-' não faz nada, se tiver algum numero depois ai ele dá eesse valor em espaçosmenos a quantidade de caracteres na variavel
		
	if((fmt[*aux] != '0') && (fmt[*aux]  >= '1' && fmt[*aux]  <= '9') )
		
			{	//printf("entrou na verificação\n");	
			tobeconv[index]= fmt[*aux];
			index++;
			*aux = *aux + 1;
			if(fmt[*aux]  >= '0' && fmt[*aux]  <= '9')
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
				if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
				{
					*aux = *aux +1;
					star->ret__ = ft_print_int_wnumb(tobeconv, &*star);
					star->ret_minustotal = star->ret_minustotal + star->ret__ ;
					star->ret__ = 0;
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
			free(tobeconv);
		//	printf("ret:%d\n", star->ret_minustotal);
			return(star->ret_minustotal);// movi aqui temporariamente pq faltam o resto		
		}

	/*}
	if(fmt[*aux] == '.'){
	}
	
		
}*/
int	find_flag(const char *fmt, int *aux, bdr *star)
{	
	int returned_ff = 0;
	int temp = 0;
	if(fmt[*aux] == '-')
	{
		*aux = *aux +1;
	//	printf("\nentrou  no if do find flag\n");
		returned_ff = dealing_minus(fmt, &*aux, &*star); 
		temp = temp + returned_ff;
		returned_ff = 0;
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
	return(temp);
}
int sortie(const char *fmt, int *aux, bdr *star)
{
	int returned_sortie;
	int returned_sortie2;
	
	returned_sortie = 0;
	returned_sortie2 = 0;	
	if((fmt[*aux] == '-') | (fmt[*aux] == '.')| (fmt[*aux] == '0') 
	|(fmt[*aux] == '*'))
	{
		returned_sortie = find_flag(fmt, &*aux, &*star);
	//	star->ret_sortie =  star->ret_sortie + returned_sortie;
	//	returned_sortie = 0;
	}else//FALTA INCLUIR SEM FLAGS MAS COM NUMEROS
	{
	//	printf("\naux antes das flags:%i\n", *aux);
		returned_sortie2 = no_flags(fmt, &*aux, &*star);
	//	star->ret_sortie =  star->ret_sortie + returned_sortie2;
	//	returned_sortie2 = 0;
		/*caso ele não achei flags pra onde vai? */
	}
return(returned_sortie + returned_sortie2);
}

int					get_info(const char *fmt, bdr *star)
{
	int	aux;
//	int	index;
	
	aux = 0;
//	index = 0;
	star->chars_counted = count_chars(fmt, &*star);
	while (fmt[aux])
	{	
		if((fmt[aux] == '%') && fmt[aux +1] == '%')
		{
			aux = aux + 2;
			ft_putchar('%');
		//	star->returned_s = star->returned_s + 1;
		}
		if((fmt[aux] == '%') && (fmt[aux +1] != '%'))
		{
			aux++;
//			printf("\nbefore sortie:%s\n",fmt);
			star->returned_s = sortie(fmt, &aux, &*star);
			//return(returned);
		}
		if (fmt[aux] != '\0' && fmt[aux] != '%')
		{
			//printf("%i",i);
			ft_putchar(fmt[aux]);
			aux++;
		}
	}
//	star->returned_s = star->returned_s ;
	return (star->returned_s + star->chars_counted);
}
int				ft_printf(const char *fmt, ...)
{
	bdr star;
	int		result;
//	int y;
//star.chars_counted = count_chars(fmt, &star);
	init_bdr(&star);
	va_start(star.list, fmt);
	result = get_info(fmt, &star);
	va_end(star.list);
	
//	y = count_args(fmt, &star);
//	printf("\nresult antes:%i\n", result);
//	result = result - y;
//	printf("\nresult depois:%i\n", result);
	return(result);// + star.chars_counted);
}