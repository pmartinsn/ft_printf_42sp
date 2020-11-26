/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:23:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/26 14:26:34 by pmartins         ###   ########.fr       */
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
//	int 	bb = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
//	int		f = 42;
////	int		g = 25;
//	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
///	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	char	*s = "-2147483648";
//	char	*t = "0x12345678";
//	char	*u = "-0";



return_printf = printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0d, %0d\n", i, j, k, l, m, c, e, d);
return_ft_printf = ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0d, %0d\n", i, j, k, l, m, c, e, d);
	       return_printf = printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	 return_ft_printf = ft_printf("%-*x, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);

    	  return_printf = printf("./a	%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	return_ft_printf = ft_printf("./a	%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
	  return_printf = printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	 return_ft_printf = ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
	  return_printf = printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	 return_ft_printf = ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	   printf("...return_printf:%i\n", return_printf);
 printf("return_ft_printf:%i\n", return_ft_printf);

printf("\nTNot working as it should......Not working as it should........Not working as it should........Not working as it should.....Not working as it should.t\n");
  
	      printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	 return_ft_printf = ft_printf("%0*.*u, %0*.*u, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	   printf("HERE---->>>>...return_printf:%i\n", return_printf);
	   printf("HERE---->>>>return_ft_printf:%i\n", return_ft_printf);
	  return_printf = printf("HERE---->>>>%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	 return_ft_printf = ft_printf("HERE---->>>>%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);

	   
printf("\nThese are right......These are right.........These are right.......These are right....These are right\n");
/*//   	      return_printf = printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
 status
 	return_ft_printf = ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
  // printf("%0*.*u, %0*.*u, %0*.*X,%0*.*u, %0*.*u, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, i, a, b, i, a, b, i);
ft_printf("%0*.*u, %0*.*u, %0*.*X,%0*.*u, %0*.*u, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, i, a, b, i, a, b, i);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	  return_printf = printf("HERE---->>>>%1.s, %1.s, %1.s, %1.s, %1.s\n", n, o, p, q, r);
	 return_ft_printf = ft_printf("HERE---->>>>%1.s, %1.s, %1.s, %1.s, %1.s\n", n, o, p, q, r);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	    return_printf = printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
	 return_ft_printf = ft_printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	          return_printf = printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
	 return_ft_printf = ft_printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	   return_printf = printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
	 return_ft_printf = ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	       return_printf = printf("HERE---->>>>%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	 return_ft_printf = ft_printf("HERE---->>>>%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	  return_printf = printf("HERE---->>>>%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	 return_ft_printf = ft_printf("HERE---->>>>%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	  return_printf = printf("HERE---->>>>%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	 return_ft_printf = ft_printf("HERE---->>>>%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//		  //Partially working
//	       return_printf = printf(" %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x,9 %*.*X, %*.*u, %*.*x, %*.*X, %*.*u\n", a, b, l, a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m);
	 return_ft_printf = ft_printf(" %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x,9 %*.*X, %*.*u, %*.*x, %*.*X, %*.*u\n", a, b, l, a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m);
//		printf("HERE---->>>>...return_printf:%i\n", return_printf);
	   printf("HERE---->>>>return_ft_printf:%i\n", return_ft_printf);
 //printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
   //  printf("HERE---->>>>...return_printf:%i\n", return_printf);
	   printf("HERE---->>>>return_ft_printf:%i\n", return_ft_printf);
	 //  	      return_printf = printf(" %i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n",i,  j, k, l, m, n, c, c, j, j, j);
	return_ft_printf = ft_printf(" %i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n",i, j, k, l, m, n, c, c, j, j, j);
 // printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
	
//printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
	ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j);
//	printf("...return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
//		  return_printf = printf("%p, %x, %p, %x, %p, %x, %p, %x\n", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0);
	 return_ft_printf = ft_printf("%p, %x, %p, %x, %p, %x, %p, %x\n", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0);
//		 printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);
//	       return_printf = printf("%*p, %*x, %*p, %*x,    %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912,   a, (void *)1,   a, 1,   a, NULL,   a, 0);
	 return_ft_printf = ft_printf("%*p, %*x, %*p, %*x,    %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912,   a, (void *)1,   a, 1,   a, NULL,   a, 0);
//	   printf("...return_printf:%i\n", return_printf);
	   printf("return_ft_printf:%i\n", return_ft_printf);*/
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