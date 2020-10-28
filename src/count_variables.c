#include "ft_printf.h"

int find_number_value(const char *fmt, int *ax, s_param *tail)
{	
	int index = 0;
	char *tobeconv;
	tobeconv = malloc(*ax * 3);
	while(fmt[*ax])
	{
		if((fmt[*ax] != '0') && (fmt[*ax]  >= '1' && fmt[*ax]  <= '9'))
		{
			tobeconv[index]= fmt[*ax];
			index++;
			*ax = *ax + 1;
			while(fmt[*ax]  >= '0' && fmt[*ax]  <= '9')
			{
				tobeconv[index]= fmt[*ax];
				index++;
				*ax = *ax + 1;
			}
			if((fmt[*ax] != '1') | (fmt[*ax] != '2') | (fmt[*ax] != '3')
			| (fmt[*ax] != '4') | (fmt[*ax] != '5') | (fmt[*ax] != '6')
			| (fmt[*ax] != '7') | (fmt[*ax] != '8') | (fmt[*ax] != '9')
			| (fmt[*ax] != '0'))
			{

				tail->hnbr= ft_atoi(tobeconv);
				break;	
			}
			
		}
	*ax = *ax + 1;
	}
	free(tobeconv);
	return(tail->hnbr);
}

int count_variables2(const char *fmt, s_param *tail)
{// tem um erro A IMPRESSÃO DOS CHARACTERES FORA DAS VARIAVEIS... VERIFICAR ISSO!!!
	int	ax;
	int aux = 0;
	ax = 0;
	while((fmt[ax] != '\0'))
	{
		if((fmt[ax] == '%') && (fmt[ax +1] != '%') && (fmt[ax +1] != '\0'))
			aux++;
		ax++;
	}
	if(aux >= 1)
	{	aux = ax;
		ax = 0;
		tail->keeper = 0;
		while(ax <= aux/*(fmt[ax] != '\0') && fmt*/)
		{
			if((fmt[ax] == '%') && (fmt[ax + 1] == '%'))
			{
				//ax = ax + 1;
//TEM QUE DIFERENCIAR QUANDO TEM E QUANDO NAO TEM
//VARIAVEL, OU ELE PODE QUEBRAR 
//ṔULOU A VARIAVEL E "ESQUECEU DE CONTAR ELA"
// TEM QUE PULAR SÓ OS NUMEROS PARES! É ISSO
				int i = 0;
				int y = ax;
				while(fmt[y] == '%')
				{
					y++;
					i++;
				}
				if( i % 2 == 0 )
				{
					ax = ax + i;
				}
				else
				{
					i = i - 1;
					ax = ax + i;
				}
				
			}
			if((fmt[ax] == '%') && (fmt[ax + 1] != '%'))
			{
				ax++;
				while((fmt[ax]) && (fmt[ax] != '%'))
				{
					if((fmt[ax] == 'd') || (fmt[ax] == 'i'))
					{
						if(fmt[ax -1] >= '0' && fmt[ax - 1]  <= '9')
						{ 
							int help = 0;
							help = ax;
							help--;
							while(fmt[help] >= '0' && fmt[help] <= '9')
							{
								help--;
							}
							tail->nbr = find_number_value(fmt, &help, &*tail);	
						}
						tail->hold = 0;
						tail->hold= va_arg(tail->list2, int);
						tail->helpint = ft_itoa(tail->hold);
						tail->hold = ft_strlen(tail->helpint);
						free(tail->helpint);
						if(tail->hold >= tail->nbr)
						{
							tail->keeper = tail->keeper + tail->hold;
							tail->hold = 0;
						}
						else
						{
							tail->keeper = tail->keeper + tail->nbr;
						//	tail->helpint = ft_itoa(tail->nbr);
						//	tail->keeper = tail->keeper - ft_strlen(tail->helpint);
							tail->nbr = 0;
						//	free(tail->helpint);
						}
						break;
					}
					if(fmt[ax] == 's')
					{
						if(fmt[ax -1] >= '0' && fmt[ax - 1]  <= '9')
						{ 
							int help = 0;
							help = ax;
							help--;
							while(fmt[help] >= '0' && fmt[help] <= '9')
							{
								help--;
							}
							tail->nbr = find_number_value(fmt, &help, &*tail);	
						}
					//	printf("%s",&fmt[ax]);
						tail->aux_outnbr = va_arg(tail->list2, char*);
						tail->hold = ft_strlen(tail->aux_outnbr);
						if(tail->hold >= tail->nbr)
						{
							tail->keeper = tail->keeper + tail->hold;
							tail->hold = 0;
						}
						else
						{
							tail->keeper = tail->keeper + tail->nbr;
						//	tail->helpint = ft_itoa(tail->nbr);
						//	tail->keeper = tail->keeper - ft_strlen(tail->helpint);
							tail->nbr = 0;
						//	free(tail->helpint);
						}
						break;
					}
					if(fmt[ax] == 'X') 
					{
						if(fmt[ax -1] >= '0' && fmt[ax - 1]  <= '9')
						{ 
							int help = 0;
							help = ax;
							help--;
							while(fmt[help] >= '0' && fmt[help] <= '9')
							{
								help--;
							}
							tail->nbr = find_number_value(fmt, &help, &*tail);	
						}
						size_t	num;
						char *character;
						num = va_arg(tail->list2, size_t);
						character = ft_itoa_base(num, 16, 'A');
						tail->hold= ft_strlen(character);
						free(character);
						if(tail->hold >= tail->nbr)
						{
							tail->keeper = tail->keeper + tail->hold;
							tail->hold = 0;
						}
						else
						{
							tail->keeper = tail->keeper + tail->nbr;
						//	tail->helpint = ft_itoa(tail->nbr);
						//	tail->keeper = tail->keeper - ft_strlen(tail->helpint);
							tail->nbr = 0;
						//	free(tail->helpint);
						}
						break;			
					}
					if(fmt[ax] == 'x')
					{
						if(fmt[ax -1] >= '0' && fmt[ax - 1]  <= '9')
						{ 
							int help = 0;
							help = ax;
							help--;
							while(fmt[help] >= '0' && fmt[help] <= '9')
							{
								help--;
							}
							tail->nbr = find_number_value(fmt, &help, &*tail);	
						}
						size_t	num;
						char *character;
						num = va_arg(tail->list2, size_t);
						character = ft_itoa_base(num, 16, 'a');
						tail->hold= ft_strlen(character);
						free(character);
						if(tail->hold >= tail->nbr)
						{
							tail->keeper = tail->keeper + tail->hold;
							tail->hold = 0;
						}
						else
						{
							tail->keeper = tail->keeper + tail->nbr;
						//	tail->helpint = ft_itoa(tail->nbr);
						//	tail->keeper = tail->keeper - ft_strlen(tail->helpint);
							tail->nbr = 0;
						//	free(tail->helpint);
						}
						break;			
					}
					if(fmt[ax] == 'u')
					{
						if(fmt[ax -1] >= '0' && fmt[ax - 1]  <= '9')
						{ 
							int help = 0;
							help = ax;
							help--;
							while(fmt[help] >= '0' && fmt[help] <= '9')
							{
								help--;
							}
							tail->nbr = find_number_value(fmt, &help, &*tail);	
						}
						size_t	num;
						char *character;
						num = va_arg(tail->list2, size_t);
						character = ft_itoa_base(num, 10, 'a');
						tail->hold= ft_strlen(character);
						free(character);
						if(tail->hold >= tail->nbr)
						{
							tail->keeper = tail->keeper + tail->hold;
							tail->hold = 0;
						}
						else
						{
							tail->keeper = tail->keeper + tail->nbr;
//tiro isso agora no count chars						//	tail->helpint = ft_itoa(tail->nbr);
						//	tail->keeper = tail->keeper - ft_strlen(tail->helpint);
							tail->nbr = 0;
						//	free(tail->helpint);
						}
						break;
					}
					if(fmt[ax] == 'p')
					{
						tail->nbr = va_arg(tail->list2, size_t);
						tail->nbr = 0;
						if(fmt[ax -1] >= '0' && fmt[ax - 1]  <= '9')
						{ 
							int help = 0;
							help = ax;
							help--;
							while(fmt[help] >= '0' && fmt[help] <= '9')
							{
								help--;
							}
							tail->nbr = find_number_value(fmt, &help, &*tail);	
						}
						if(tail->nbr <= 14)
							tail->keeper = tail->keeper + 14;
						else
						{
							tail->keeper = tail->keeper + tail->nbr;
						///	tail->helpint = ft_itoa(tail->nbr);
							//tail->keeper = tail->keeper - ft_strlen(tail->helpint);
							tail->nbr = 0;
						//	free(tail->helpint);
						}
						break;
					}
					if (fmt[ax] == 'c')
					{
						tail->nbr = va_arg(tail->list2, int);
						tail->nbr = 0;
						if(fmt[ax -1] >= '0' && fmt[ax - 1]  <= '9')
						{ 
							int help = 0;
							help = ax;
							help--;
							while(fmt[help] >= '0' && fmt[help]  <= '9')
								help--;
							tail->nbr = find_number_value(fmt, &help, &*tail);
						}
						if(tail->nbr >= 1)
						{
							tail->keeper = tail->keeper + tail->nbr;
						//	tail->helpint = ft_itoa(tail->nbr);
						//	tail->keeper = tail->keeper - ft_strlen(tail->helpint);
							tail->nbr = 0;
						//	free(tail->helpint);
						}
						else
							tail->keeper = tail->keeper + 1;
						break;	
					}//VERIFICAR COLO ESSAS VARIAVEIS INCLUENCIAM NA IMPRESSÃO PRA FAZER A CONTA
					//DE SOMAR O IMPRESO
					if((fmt[ax] == '-') | (fmt[ax] == '.') | (fmt[ax] == '0') | (fmt[ax] == '*'))
						ax++;
					if(fmt[ax]  >= '0' && fmt[ax]  <= '9')
						ax++;
				}
			}
			ax++;
		}
		ax++;
	}
	return(tail->keeper);
}


int	count_variables1(const char *fmt, ...)
{
	s_param tail;
	int		result;
	result = 0;
//	printf("voce chegou aqui?");
	init_tail(&tail);
	va_start(tail.list2, fmt);
	result = count_variables2(fmt, &tail);
	va_end(tail.list2);
	tail.keeper = 0;
	return(result);
}