/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:23:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/19 15:21:25 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);
int main()
{
	int 	return_printf = 0;
	int 	return_ft_printf = 0;
//	unsigned int 	numero = 243;
//	int				nbr = 64;
//	unsigned int 	hexa = 22222;
//	char 			jan[] = "ABCDE";
//	char 			h = 'h';
//	char 			*test = "teste";
	
	//testes do Mazoize
	int		a = -4;

	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	char	*s = "-2147483648";
//	char	*t = "0x12345678";
//	char	*u = "-0";

    	//		return_printf = printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d);
//cd 4			ft_printf("%5.i", 0);
		        				      printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
		return_ft_printf = ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
	
	 			return_printf = printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
		return_ft_printf = ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
	//////////testes antigos 
//	return_ft_printf = ft_printf("%-09s.", "ho low\0 hidden");
//	  printf("\nreturn_ft_printf:%i\n", return_ft_printf);
//		 return_printf = printf("%-3i%-2s%-2c.%-2p.%-2u.%-2x.%-2X.%-2d\n", nbr, jan, h, &test, numero, hexa, hexa, hexa);
//      return_ft_printf = ft_printf("%-3i%-2s%-2c.%-2p.%-2u.%-2x.%-2X.%-2d\n", nbr, jan, h, &test, numero, hexa, hexa, hexa);
//	printf("...return_printf:%i\n", return_printf);
//	printf("return_ft_printf:%i\n", return_ft_printf);
//	      return_printf = printf("%d\n",numero);
//	return_ft_printf = ft_printf("%d\n",numero);
//	printf("...............return_printf:%i\n", return_printf);
//	printf("............return_ft_printf:%i\n", return_ft_printf);
//	         	     return_printf = printf("%-c%-c%-c%-c%-c%-c\n",h,h,h,h,h,h);
//	           return_ft_printf = ft_printf("%-c%-c%-c%-c%-c%-c\n",h,h,h,h,h,h);
//	printf("...............return_printf:%i\n", return_printf);
//	printf("------------return_ft_printf:%i\n", return_ft_printf);
}