#include "ft_printf.h"

void	dealing_precision(const char *fmt, int *aux, bdr *star)
{
	int index;
	char *tobeconv;
	
	index= 0;
	tobeconv = malloc(*aux * 3);
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i')| (fmt[*aux] == 'u') 
	|(fmt[*aux] == 'x')|(fmt[*aux] == 'X'))
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
	}
	if((fmt[*aux] == '0') | (fmt[*aux +1] == 's'))
		*aux = *aux +2;
	if((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
	{
		*aux = *aux +1;
		ft_print_int_pre(tobeconv, &*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux],  &*star);
			*aux = *aux +1;
		}
	}
	else if(fmt[*aux] == 's')
	{
		int i;

		i = 0;
		*aux = *aux +1;
		i = find_number_value(tobeconv, &*star);
		if(i >= 1)
			print_s_noflag(&*star);				
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux],  &*star);
			*aux = *aux +1;
		}
	}
		/*else if(fmt[*aux] == 'c')
		{
			*aux = *aux +1;
			print_char_pre(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
				ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			}
		}
		else if(fmt[*aux] == 'p')
		{
			*aux = *aux +1;
			print_p_pre(tobeconv, &*star);
			while(fmt[*aux] != '%' && fmt[*aux] != '\0')
			{
				ft_putchar(fmt[*aux],  &*star);
				*aux = *aux +1;
			
			}
		}*/
	else if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		print_u_pre(tobeconv, &*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
			ft_putchar(fmt[*aux],  &*star);
			*aux = *aux +1;
		
		}
	}
	else if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		print_x_pre(tobeconv, &*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
			ft_putchar(fmt[*aux],  &*star);
			*aux = *aux +1;
		
		}
	}
	else if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		print_X_pre(tobeconv, &*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
			ft_putchar(fmt[*aux],  &*star);
			*aux = *aux +1;
		}
	}
free(tobeconv);	
}