#include "ft_printf.h"

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
	ft_putnbr(star->kpr8, &*star);
	star->kpr8 = ft_strlen(character);
	if(star->kpr8 > j)
		j = star->kpr8;
		else
		j =  j - star->kpr8;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	free(character);
}
void	print_s_minuswnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;

//	char *character;
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->aux_outnbr = va_arg(star->list, char*);
	star->hold = ft_strlen(star->aux_outnbr);
	ft_putstr(star->aux_outnbr, &*star);
	if(star->hold > j)
		j = star->hold;
		else j =  j -star->hold;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
}
void	print_char_minuswnumb(char *tobeconv, bdr *star)
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
	ft_putchar(charr, &*star);
	if( j < 1)
		j = 1;
		else j =  j - 1;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
}
void	print_p_minuswnumb(char *tobeconv, bdr *star)
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
	ft_putstr("0x", &*star);
	ft_putstr(character, &*star);
	free(character);
	if( j < 14)
		j = 14;
		else j =  j - 14;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
void	print_u_minuswnumb(char *tobeconv,bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 10, 'a');
	star->kpr5= ft_strlen(character);
	ft_putstr(character, &*star);
	if(star->kpr5 > j)
		j = star->kpr5;
		else j =  j -star->kpr5;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
	free(character);
}
void	print_x_minuswnumb(char *tobeconv, bdr *star)
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
	star->kpr6= ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	if(star->kpr6 > j)
		j = star->kpr6;
		else j =  j - star->kpr6;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
}
void	print_X_minuswnumb(char *tobeconv, bdr *star)
{
	int help;
	int j;
	
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr6= ft_strlen(character);
	ft_putstr(character, &*star);
	free(character);
	if(star->kpr6 > j)
		j = star->kpr6;
		else j =  j -star->kpr6;
	while(help < j)
	{
		ft_putchar(' ',  &*star);
		help++;
	}
}