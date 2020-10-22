#include "ft_printf.h"

void		no_flags(const char *fmt, int *aux, bdr *star)
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
//	return(star->ret_p);
}
int	ft_print_int_wnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;

	char *character;
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	star->ret__ = ft_strlen(character);
	j = j - star->ret__;
	while(help < j)
	{
		ft_putchar(' ');
		help++;
	}
	ft_putnbr(star->kpr8);
//	printf("TESTE:%s\n", tobeconv);
//	star->ret__ =  j + star->kpr8 - ft_strlen(tobeconv);
	free(character);
//	printf("retunr:%d\n", star->ret__);
	return(star->ret__);
}//Agora não funciona mais this motherfucker

