/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:49:45 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/30 20:28:59 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <inttypes.h>

typedef struct
{
	va_list	list;
	int		count;
	int		returned_s;
	char	*aux_outnbr;
	char	*helpint;
	int		hold;
	int		keeper;
	int		kpr2;
	int		kpr3;
	int		kpr4;
	int		kpr5;
	int		kpr6;
	int		kpr7;
	int		kpr8;
	int		ret_p;
	int		ret__;
	int		count_arg;
	int		yndex;
	int		yndex2;
	int		variables_counted;
	int		bugfix;
	int		ret_sortie;
	int		returned;
} 	bdr;


void	ft_putnbr(int nb, bdr *star);
void	ft_putchar( char c, bdr *star);
void	ft_putstr(char *s,  bdr *star);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *str);
int		ft_printf(const char *fmt, ...);
void	init_bdr(bdr *star);
void	no_minus_flags(const char *fmt, int *aux, bdr *star);
void	no_flags(const char *fmt, int *aux, bdr *star);
void	find_flag(const char *fmt, int *aux, bdr *star);
int		sortie(const char *fmt, int *aux, bdr *star);
int		get_info(const char *fmt, bdr *star);
int		print_int_noflag(bdr *star);
int		print_s_noflag(bdr *star);
int		print_p_noflag(bdr *star);
void	no_flags2(const char *fmt, int *aux, bdr *star);
char	*ft_itoa_base(size_t nb, int base, char updown/*, bdr *star*/);
int		print_percent_noflag(bdr *star);
int		print_x_noflag( bdr *star);
int		print_X_noflag( bdr *star);
int		print_u_noflag(bdr *star);
void	dealing_minus(const char *fmt, int *aux, bdr *star);
void	init_bdr(bdr *star);
void	ft_print_int_wnumb(char *tobeconv, bdr *star);
void	nfw_nbr(const char *fmt, int *aux, bdr *star);
void	ft_print_int_minuswnumb(char *tobeconv, bdr *star);
void	print_s_wnumb(char *tobeconv, bdr *star);
void	print_s_minuswnumb(char *tobeconv, bdr *star);
void	print_char_minuswnumb(char *tobeconv, bdr *star);
void	print_char_wnumb(char *tobeconv, bdr *star);
void	print_p_minuswnumb(char *tobeconv, bdr *star);
void	print_p_wnumb(char *tobeconv, bdr *star);
void	print_u_wnumb(char *tobeconv,bdr *star);
void	print_u_minuswnumb(char *tobeconv,bdr *star);
void	print_x_wnumb(char *tobeconv, bdr *star);
void	print_x_minuswnumb(char *tobeconv, bdr *star);
void	print_X_wnumb(char *tobeconv, bdr *star);
void	print_X_minuswnumb(char *tobeconv, bdr *star);
void	dealing_precision(const char *fmt, int *aux, bdr *star);
void	print_X_pre(char *tobeconv, bdr *star);
void	print_x_pre(char *tobeconv, bdr *star);
void	print_u_pre(char *tobeconv,bdr *star);
void	print_s_pre(char *tobeconv, bdr *star);
void	ft_print_int_pre(char *tobeconv, bdr *star);
void	print_char_pre(char *tobeconv, bdr *star);
void	check_and_pass(const char *fmt, int *aux, bdr *star);
void	verify_flags_minus(const char *fmt, int *aux, bdr *star);
void	dealing_width_two(const char *fmt, int *aux, bdr *star);
char	*converter(char *tobeconv, const char *fmt, int *aux);
void	dealing_minus_two(char *tobeconv, const char *fmt, int *aux, bdr *star);
void	print_X_width_m(bdr *star);
void	print_p_width_m(bdr *star);
void	print_X_width(bdr *star);
void	print_p_width(bdr *star);
void	print_while(const char *fmt, int *aux, bdr *star);
void	dealing_zero(const char *fmt, int *aux, bdr *star);
void	ft_print_int_zero(char *tobeconv, bdr *star);
void	print_u_zero(char *tobeconv,bdr *star);
void	print_x_zero(char *tobeconv, bdr *star);
void	print_X_zero(char *tobeconv, bdr *star);
void	ft_print_int_width( bdr *star);
void	print_s_width(bdr *star);
void	print_char_width(bdr *star);
void	print_u_width(bdr *star);
void	print_x_width(bdr *star);
void	verify_dwm_two(const char *fmt, int *aux, bdr *star);
void	verify_dwm(const char *fmt, int *aux, bdr *star);
void	print_u_width_m(bdr *star);
void	print_x_width_m(bdr *star);
void	print_char_width_m(bdr *star);
void	print_s_width_m(bdr *star);
void	ft_print_int_width_m( bdr *star);
void	dealing_width_m(const char *fmt, int *aux, bdr *star);
void	dealing_width(const char *fmt, int *aux, bdr *star);
int		find_number_value(char *tobeconv, bdr *star);
int		print_u_noflag(bdr *star);
int		print_char_noflag(bdr *star);

#endif
