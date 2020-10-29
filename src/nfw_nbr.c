#include "ft_printf.h"

void	nfw_nbr(const char *fmt, int *aux, bdr *star)
{
	int index;
	char *tobeconv;
	
	index= 0;
	tobeconv = malloc(*aux * 3);
	if((fmt[*aux] >= 'a' && fmt[*aux] <= 'z') | (fmt[*aux] == 'X'))
	{
		no_flags(fmt, &*aux, &*star);
	}
	if((fmt[*aux] != '0') && (fmt[*aux]  >= '1' && fmt[*aux]  <= '9') )
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
		if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux +1;
			ft_print_int_wnumb(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
			ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			}
		}
		else if(fmt[*aux] == 's')
		{
			*aux = *aux +1;
			print_s_wnumb(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
			ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			}
		}
		else if(fmt[*aux] == 'c')
		{
			*aux = *aux +1;
			print_char_wnumb(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
				ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			}
		}
		else if(fmt[*aux] == 'p')
		{
			*aux = *aux +1;
			print_p_wnumb(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
				ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			
			}
		}
		else if(fmt[*aux] == 'u')
		{
			*aux = *aux +1;
			print_u_wnumb(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
				ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			
			}
		}
		else if(fmt[*aux] == 'x')
		{
			*aux = *aux +1;
			print_x_wnumb(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
				ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			
			}
		}
		else if(fmt[*aux] == 'X')
		{
			*aux = *aux +1;
			print_X_wnumb(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
				ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			
			}
		}
	free(tobeconv);
	}
}