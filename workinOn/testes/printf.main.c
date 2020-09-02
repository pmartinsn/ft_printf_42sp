/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 13:23:17 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/01 10:45:51 by pmartins         ###   ########.fr       */
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
	//short nbr = 11188.111;
	//char bob[] = "wrecking";
	char *h = "hdhfkdgjhdkgh";
	float	keeper = 2.12345633;
	//double	duo = 2.1234563377777;
	//int test;
	 printf("2-The int:%.c The char :%s The Float:%f\n", numero, h, keeper);
	    //printf("3-The String:%s The Double :%f \n", bob, duo);
	//ft_printf("1-The int:%i The D :%d The Float:%f\n", numero, numero, keeper);
			  
			//printf("\nthis is the RETURN of ft_printf:%i\n", test);
}