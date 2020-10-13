/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:23:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/02 13:37:09 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);




int main()
{
	int 			return_printf= 0;
	int 			return_ft_printf= 0;
	unsigned int 	numero = 13;
	int				nbr = -999911188;
	unsigned int 	hexa = 12;
	char 			bob[] = "won";
	char 			nan[] = "thing";
	char 			jan[] ="some";
	char 			limit[] ="help";
	char 			h = 'h';
	int				duo = 2145.34563377777;
	char 			*test = "teste";
	printf("....int:%020i....intDandI:%020d.hexa:%x.\n", numero, duo, hexa);
	//ft_printf("....int:%-i....intDandI:%-10d.hexa:%-x.\n", numero, duo, hexa);
	printf("int:%0d.unsgDecInt:%0u.\n",  nbr, numero);
	//ft_printf("int:%-10d.unsgDecInt:%-10u.\n",  nbr, numero);
	printf(".String:%-.10s........char:%-10c.Pointer:%-30p.Percentage:%%.\n", bob,  h ,&test);
	      return_printf = printf("%-c%-c%-c%-i.%-i.%-i.%-s123%%%%%%456789%%%%123456789%-s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%c\n",h,h,h,duo,nbr, nbr, nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa ,hexa, hexa,h);
	return_ft_printf = ft_printf("%-c%-c%-c%-i.%-i.%-i.%-s123%%%%%%456789%%%%123456789%-s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%c\n",h,h,h,duo,nbr, nbr,nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa , hexa, hexa,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
	      return_printf = printf("%-c%-c%-c%-i.%-i.%-i.%-s%-s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%-c\n",h,h,h,duo,nbr, nbr, nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa ,hexa, hexa,h);
	return_ft_printf = ft_printf("%-c%-c%-c%-i.%-i.%-i.%-s%-s.%-s.%-i.%-c.%-p.%-u.%-x.%-X.%-x.%X..%-x.%-X.%-c\n",h,h,h,duo,nbr, nbr,nan,jan,limit,nbr,h,&test, numero, hexa, hexa,  hexa, hexa , hexa, hexa,h);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
		      return_printf = printf("%-i.%-20i.\n",duo,nbr);
	    return_ft_printf = ft_printf("%-i.%-20i.\n",duo,nbr);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
			  
			//printf("\nthis is the RETURN of ft_printf:%i\n", test);
}

/*int	print_x_noflag( bdr *star)
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
	printf("\nentrou  no X\n");
	size_t	num;
	char *character;
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, 16, 'A');
	star->kpr7= ft_strlen(character);
	ft_putstr(character);
	free(character);
	return(star->kpr7);
}*/