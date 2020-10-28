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
	ft_putnbr(star->kpr8, &*star);
	star->kpr8 = ft_strlen(character);
	j = j - star->kpr8;
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
	j = j - star->hold;
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
	j = j - 1;
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
	j = j - 14;
	while(help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
