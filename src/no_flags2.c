#include "ft_printf.h"

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