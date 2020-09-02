/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:23:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/02 16:31:01 by pmartins         ###   ########.fr       */
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
	int numero = 1511;
	int nbr = +11188;
	int hexa = 12;
	char bob[] = "wrecking";
	char h = 'h';
	float	keeper = 2.12345633;
	double	duo = 2.1234563377777;
	char *test = "teste";
	printf("....int:%i........char:%0c.Float:%0f.\n", numero, h, keeper);
	printf(".String:%0s....Double:%fhexa:%x.\n", bob, duo, hexa);
	printf("Pointer:%p.Percentage:%%.int:%d.unsgDecInt:%u.\n", &test, nbr, numero);
	//ft_printf("1-The int:%i The D :%d The Float:%f\n", numero, numero, keeper);
			  
			//printf("\nthis is the RETURN of ft_printf:%i\n", test);
}