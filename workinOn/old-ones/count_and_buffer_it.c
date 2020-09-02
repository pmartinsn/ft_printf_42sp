#include "printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>	
#include <stdlib.h>

void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_itoa(float n);
int				ft_strlen(const char *str);

/*void	*count_and_buffer_it(va_list	prtf, char *fmt)
{
	int i;
	int j;
	char *aux;
	char *guardian;


	i = 0;
	j = 0;
	printf("entrou222");
	//va_start(prtf, fmt);
	while (fmt[i + 1] != '\0' && fmt[i])
	{
		i++;
		
		if( (fmt[i] == 'd') | (fmt[i] == 'i') | (fmt[i] == 'o')|\
			(fmt[i] == 'x') | (fmt[i] == 'X') | (fmt[i] == 'u') )
			{
				j++;
				ft_putnbr(va_arg(prtf, int));
			}
			if((fmt[i] == 's') | (fmt[i] == 'c'))
			{
				j++;
				aux = va_arg(prtf, char*);
				
			}
			if((fmt[i] == 'f') | (fmt[i] == 'e') | (fmt[i] == 'E') |\
			(fmt[i] == 'g') | (fmt[i] == 'G'))
			{
				j++;
				aux = va_arg(prtf, double);
			
			i++;
		}j = 0;
		
	} va_end(prtf);
	guardian = malloc(i + 1); 
	return(guardian);
}*/
