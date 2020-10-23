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
void	no_flags2(const char *fmt, int *aux, bdr *star)
{
	if(fmt[*aux] == 'p')
	{
		*aux = *aux +1;
		print_p_noflag(&*star);
	}
	if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		print_u_noflag(&*star);
	}
	if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		print_x_noflag(&*star);
	}
	if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		print_X_noflag(&*star);
	}
}