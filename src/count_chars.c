#include "ft_printf.h"

int	count_chars(const char *fmt, bdr *star)
{
	int index = 0;
	int args = 0;
	while(fmt[index] != '\0')
	{
		if(fmt[index]== '%')
		{
			index++;
			if(fmt[index] != '%')
				args++;//aqui eu tiroo % e o conversor da conta
			if((fmt[index] == '-') | (fmt[index] == '.') |
			(fmt[index] == '0') | (fmt[index] == '*'))
			{
				star->bugfix++;
				index++;
			}
			if(fmt[index] >= '0' && fmt[index]  <= '9')
			{
				while(fmt[index] >= '0' && fmt[index]  <= '9')
				{
					star->bugfix++;
					index++;
				}
			}
			if(fmt[index] == '%')
			{
				int i = 1;
				while(fmt[index]== '%')
				{
					i++;
					index++;
				}
				if( i % 2 == 0 )
				{
					star->yndex2 = star->yndex2 + (i / 2);
					//star->yndex = star->yndex + i;
					//ax = ax + i;
				}
				else
				{
					args++;
					i = i - 1;
					star->yndex2 = star->yndex2 + (i / 2);
				//	star->yndex2 = star->yndex2 + i;
					//i = i - 1;
				//	ax = ax + i;
				}
			}
			
			/*if((fmt[index] == '-') | (fmt[index] == '.') |
			(fmt[index] == '0') | (fmt[index] == '*'))
				star->bugfix++;
			if(fmt[index] >= '0' && fmt[index]  <= '9')
				star->bugfix++;*/
		}
		if(fmt[index]== '\0')
				break;
		index++;
		
	}
	if(star->yndex2 > 1)
		index = index- star->yndex2;
	index = index -(args * 2);;
	return(index - star->bugfix);
}