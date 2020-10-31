#include "ft_printf.h"

void	dealing_zero(const char *fmt, int *aux, bdr *star)
{
	int		index;
	char	*tobeconv;
	
	index= 0;
	tobeconv = malloc(*aux * 3);
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i')| (fmt[*aux] == 'u') 
	|(fmt[*aux] == 'x')|(fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	if((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux]  <= '9') )
	{
		tobeconv[index]= fmt[*aux];
		index++;
		*aux = *aux + 1;
		while(fmt[*aux]  >= '0' && fmt[*aux]  <= '9')
		{
			tobeconv[index]= fmt[*aux];
			index++;
			*aux = *aux + 1;
		}
	}
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux +1;
		ft_print_int_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		print_u_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		print_x_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
	else if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		print_X_zero(tobeconv, &*star);
		print_while(fmt, &*aux, &*star);
	}
free(tobeconv);	
}