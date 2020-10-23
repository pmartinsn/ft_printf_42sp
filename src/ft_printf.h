/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:49:45 by pmartins          #+#    #+#             */
/*   Updated: 2020/10/22 14:33:45 by pmartins         ###   ########.fr       */
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
	int returned_s;
	char	*aux_outnbr;
	char	*helpint;
	int	hold;
	int	keeper;
	int	kpr2;
	int	kpr3;
	int	kpr4;
	int kpr5;
	int kpr6;
	int kpr7;
	int kpr8;
//	int kpr9;
	int	ret_p;
	int ret__;
	int	count_arg;
	int	yndex;
	int	yndex2;
	int chars_counted;
	int variables_counted;
/*	int	ret_minustotal;
	int retminus1;
	int ret_dealing;*/
	int bugfix;
	int ret_sortie;
//	int returned_s;
} 	bdr;

typedef struct
{
	va_list	list2;
	char	*helpint;
	char	*aux_outnbr;
	int	hold;
	int	keeper;
	int hnbr;
	int nbr;
	
} 	s_param;


void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *src);
int				ft_strlen(const char *str);
int				ft_printf(const char *fmt, ...);
void			init_bdr(bdr *star);
void				no_minus_flags(const char *fmt, int *aux, bdr *star);
void				no_flags(const char *fmt, int *aux, bdr *star);
void				find_flag(const char *fmt, int *aux, bdr *star);
int				sortie(const char *fmt, int *aux, bdr *star);
int				get_info(const char *fmt, bdr *star);
int				print_int_noflag(/* int *aux,*/ bdr *star);
int				print_s_noflag(/* int *aux,*/ bdr *star);
int				print_p_noflag(/* int *aux,*/ bdr *star);
//int	count_args(const char *fmt, bdr *star);
int				count_chars(const char *fmt, bdr *star);
int				print_char_noflag(bdr *star);
void	no_flags2(const char *fmt, int *aux, bdr *star);
char			*ft_itoa_base(size_t nb, int base, char updown/*, bdr *star*/);
int				print_percent_noflag(bdr *star);
int				print_x_noflag( bdr *star);
int				print_X_noflag( bdr *star);
int				print_u_noflag(bdr *star);
void				dealing_minus(const char *fmt, int *aux, bdr *star);
void	init_tail(s_param *tail);
void	init_bdr(bdr *star);
int	ft_print_int_wnumb(char *tobeconv, bdr *star);
void				nfw_nbr(const char *fmt, int *aux, bdr *star);
void	ft_print_int_minuswnumb(char *tobeconv, bdr *star);
int find_number_value(const char *fmt, int *ax, s_param *tail);
int count_variables2(const char *fmt, s_param *tail);
int	count_variables1(const char *fmt, ...);
int	count_chars(const char *fmt, bdr *star);

//size_t			ft_strlen(const char *str);

#endif
