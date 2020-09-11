/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:23:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/11 17:00:10 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_itoa(float n);
char			*ft_strdup(const char *src);
int				ft_strlen(char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putbnr_fd(int nb, int fd);

int main()
{
	int return_printf= 0;
	int return_ft_printf= 0;
	unsigned int numero = 5.1111111111;
	int nbr = -11188;
	unsigned int hexa = 12;
	char bob[] = "wrekingbal";
	char h = 'h';
	int	duo = 2.1234563377777;
	char *test = "teste";
	printf("....int:%-i....intDandI:%-10d.hexa:%-x.\n", numero, duo, hexa);
	ft_printf("....int:%-i....intDandI:%-10d.hexa:%-x.\n", numero, duo, hexa);
	printf("int:%-10d.unsgDecInt:%-10u.\n",  nbr, numero);
	ft_printf("int:%-10d.unsgDecInt:%-10u.\n",  nbr, numero);
	printf(".String:%-.10s........char:%-10c.Pointer:%-30p.Percentage:%%.\n", bob,  h ,&test);
	      return_printf = printf("12345++%.11i..%.20s==space--\n", nbr, bob);
	return_ft_printf = ft_printf("12345++%.11i..%.20s==space--\n", nbr, bob);
	printf("return_printf:%i\n", return_printf);
	printf("return_ft_printf:%i\n", return_ft_printf);
			  
			//printf("\nthis is the RETURN of ft_printf:%i\n", test);
}