#include "ft_printf.h"

void		no_flags(const char *fmt, int *aux, bdr *star)
{
	if((fmt[*aux] == 'd') || (fmt[*aux] == 'i'))
	{
		*aux = *aux +1;
		 print_int_noflag(&*star);
		 //if(fmt[*aux] != '%')
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux], &*star);
			*aux = *aux +1;
		}
		 
	}
	else if(fmt[*aux] == 's')
	{
		*aux = *aux +1;
		print_s_noflag(&*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux], &*star);
			*aux = *aux +1;
		}
	}
	else if(fmt[*aux] == 'c')
	{
		*aux = *aux +1;
		print_char_noflag(&*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux], &*star);
			*aux = *aux +1;
		}
	}
	else if(fmt[*aux] == 'p')
	{
		*aux = *aux +1;
		print_p_noflag(&*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux], &*star);
			*aux = *aux +1;
		}
	}
	else if(fmt[*aux] == 'u')
	{
		*aux = *aux +1;
		print_u_noflag(&*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux], &*star);
			*aux = *aux +1;
		}
	}
	 else if(fmt[*aux] == 'x')
	{
		*aux = *aux +1;
		print_x_noflag(&*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux], &*star);
			*aux = *aux +1;
		}
	}
	else if(fmt[*aux] == 'X')
	{
		*aux = *aux +1;
		print_X_noflag(&*star);
		while(fmt[*aux] != '%' && fmt[*aux] != '\0')
		{
		ft_putchar(fmt[*aux], &*star);
			*aux = *aux +1;
		}
	}
}

