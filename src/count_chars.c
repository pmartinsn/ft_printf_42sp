#include "ft_printf.h"

int	count_chars(const char *fmt, bdr *star)
{
	while(fmt[star->yndex] != '\0')
	{
		if(fmt[star->yndex]== '%')
		{
			star->yndex++;
			if(fmt[star->yndex] != '%')
				star->count_arg++;//aqui eu tiroo % e o conversor da conta
			if(fmt[star->yndex] == '%')
			{
				star->yndex2 = star->yndex2 + 2;
				star->yndex++;
			}
			if((fmt[star->yndex] == '-') | (fmt[star->yndex] == '.') |
			(fmt[star->yndex] == '0') | (fmt[star->yndex] == '*'))
				star->bugfix++;
			/*if(fmt[star->yndex]  >= '1' && fmt[star->yndex]  <= '9')
					star->bugfix++;*/
		}
		star->yndex++;
	}
	if(star->yndex2 > 1)
		star->yndex = star->yndex - (star->yndex2 / 2);
	star->yndex = star->yndex -(star->count_arg * 2);;
	return(star->yndex - star->bugfix);
}