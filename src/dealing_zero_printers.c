#include "ft_printf.h"

void	ft_print_int_zero(char *tobeconv, bdr *star)
{
	int		help;
	int		j;
	char	*character;

	character = "tryme";
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	star->kpr8 = va_arg(star->list, int);
	character = ft_itoa(star->kpr8);
	star->ret__ = ft_strlen(character);
	if(star->ret__ > j)
		j = star->ret__;
		else
		j = j - star->ret__;
	while(help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putnbr(star->kpr8, &*star);
	free(character);
}

void	print_u_zero(char *tobeconv,bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 10, 'a');
	star->kpr5= ft_strlen(character);
	if(star->kpr5 > j)
		j = star->kpr5;
		else j = j -star->kpr5;
	while(help < j)
	{
		ft_putchar('0',  &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_x_zero(char *tobeconv, bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char *character;

	character = "tryme";
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'a');
	star->kpr6= ft_strlen(character);
	if(star->kpr6 > j)
		j = star->kpr6;
		else j = j -star->kpr6;
	while(help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}

void	print_X_zero(char *tobeconv, bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	character = "tryme";
	help = 0;
	j = 0;
	j = ft_atoi(tobeconv);
	num = 0;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr6= ft_strlen(character);
	if(star->kpr6 > j)
		j = star->kpr6;
		else j = j -star->kpr6;
	while(help < j)
	{
		ft_putchar('0', &*star);
		help++;
	}
	ft_putstr(character, &*star);
	free(character);
}