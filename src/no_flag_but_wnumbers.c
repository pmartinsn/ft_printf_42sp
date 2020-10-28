#include "ft_printf.h"

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
		ft_putchar(' ',  &*star);
		help++;
	}
	ft_putnbr(star->kpr8, &*star);
//	printf("TESTE:%s\n", tobeconv);
//	star->ret__ =  j + star->kpr8 - ft_strlen(tobeconv);
	free(character);
	return(star->ret__);
}
void	print_s_wnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;

//	char *character;
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
//	star->hold = ft_strlen(character);
	j = j - star->hold;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
	ft_putstr(star->aux_outnbr, &*star);
}
void	print_char_wnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	int i;
	char charr;
	i = va_arg(star->list, int);
	charr = (char)i;
	j = j - 1;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
	ft_putchar(charr,  &*star);
}
void	print_p_wnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	
	free(character);
	j = j - 14;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
}