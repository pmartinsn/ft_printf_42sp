#include "ft_printf.h"

/*void				no_minus_flags(const char *fmt, int *aux, bdr *star)
{

}*/
void	ft_print_int_minuswnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;

	char *character;
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	ft_putnbr(star->kpr8);
	star->kpr8 = ft_strlen(character);
	j = j - star->kpr8;
	while(help < j)
	{
		ft_putchar(' ');
		help++;
	}
//	printf("TESTE:%s\n", tobeconv);
//	star->ret__ =  j + star->kpr8 - ft_strlen(tobeconv);
	free(character);
//	printf("retunr:%d\n", star->ret__);
//	return(star->ret__);
}//Agora não funciona mais this motherfucker