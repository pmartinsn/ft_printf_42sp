/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:49:45 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/11 18:33:45 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.two.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <inttypes.h>

void	ft_putnbr(int nb, t_bdr *star);
void	ft_putchar(char c, t_bdr *star);
void	ft_putstr(char *s, t_bdr *star);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *str);
int		ft_printf(const char *fmt, ...);
void	init_bdr(t_bdr *star);
void	no_minus_flags(const char *fmt, int *aux, t_bdr *star);
void	no_flags(const char *fmt, int *aux, t_bdr *star);
void	no_flags_two(const char *fmt, int *aux, t_bdr *star);
void	find_flag(const char *fmt, int *aux, t_bdr *star);
int		sortie(const char *fmt, int *aux, t_bdr *star);
int		get_info(const char *fmt, t_bdr *star);
int		print_int_noflag(t_bdr *star);
int		print_s_noflag(t_bdr *star);
int		print_p_noflag(t_bdr *star);
void	no_flags2(const char *fmt, int *aux, t_bdr *star);
char	*ft_itoa_base(size_t nb, int base, char updownne);
int		print_percent_noflag(t_bdr *star);
int		print_x_noflag(t_bdr *star);
int		print_xx_noflag(t_bdr *star);
int		print_u_noflag(t_bdr *star);
void	dealing_minus(const char *fmt, int *aux, t_bdr *star);
void	init_bdr(t_bdr *star);
void	ft_print_int_wnumb(char *tobeconv, t_bdr *star);
void	nfw_nbr(const char *fmt, int *aux, t_bdr *star);
void	ft_print_int_minuswnumb(char *tobeconv, t_bdr *star);
int		print_s_wnumb(char *tobeconv, t_bdr *star);
int		print_s_minuswnumb(char *tobeconv, t_bdr *star);
void	print_char_minuswnumb(char *tobeconv, t_bdr *star);
void	print_char_wnumb(char *tobeconv, t_bdr *star);
void	print_p_minuswnumb(char *tobeconv, t_bdr *star);
void	print_p_wnumb(char *tobeconv, t_bdr *star);
void	print_u_wnumb(char *tobeconv, t_bdr *star);
void	print_u_minuswnumb(char *tobeconv, t_bdr *star);
void	print_x_wnumb(char *tobeconv, t_bdr *star);
void	print_x_minuswnumb(char *tobeconv, t_bdr *star);
void	print_xx_wnumb(char *tobeconv, t_bdr *star);
void	print_xx_minuswnumb(char *tobeconv, t_bdr *star);
void	dealing_precision(const char *fmt, int *aux, t_bdr *star);
void	dealing_preci_two(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	dealing_preci_three(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	print_xx_pre(char *tobeconv, t_bdr *star);
void	print_x_pre(char *tobeconv, t_bdr *star);
void	print_u_pre(char *tobeconv, t_bdr *star);
void	print_s_pre(char *tobeconv, t_bdr *star);
void	ft_print_int_pre(char *tobeconv, t_bdr *star);
void	print_char_pre(char *tobeconv, t_bdr *star);
void	check_and_pass(const char *fmt, int *aux, t_bdr *star);
void	verify_flags_minus(const char *fmt, int *aux, t_bdr *star);
void	dealing_width_two(const char *fmt, int *aux, t_bdr *star);
char	*converter(char *tobeconv, const char *fmt, int *aux);
void	dealing_min_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	dealing_minus_three(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	print_xx_width_m(t_bdr *star);
void	print_p_width_m(t_bdr *star);
void	print_xx_width(t_bdr *star);
void	print_p_width(t_bdr *star);
void	print_while(const char *fmt, int *aux, t_bdr *star);
void	dealing_zero(const char *fmt, int *aux, t_bdr *star);
void	dea_zero_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	ft_print_int_zero(char *tobeconv, t_bdr *star);
void	print_u_zero(char *tobeconv, t_bdr *star);
void	print_x_zero(char *tobeconv, t_bdr *star);
void	print_xx_zero(char *tobeconv, t_bdr *star);
void	ft_print_int_width(t_bdr *star);
void	print_s_width(t_bdr *star);
void	print_char_width(t_bdr *star);
void	print_u_width(t_bdr *star);
void	print_x_width(t_bdr *star);
void	verify_dwm_two(const char *fmt, int *aux, t_bdr *star);
void	verify_dwm(const char *fmt, int *aux, t_bdr *star);
void	print_u_width_m(t_bdr *star);
void	print_x_width_m(t_bdr *star);
void	print_char_width_m(t_bdr *star);
void	print_s_width_m(t_bdr *star);
void	ft_print_int_width_m(t_bdr *star);
void	dealing_width_m(const char *fmt, int *aux, t_bdr *star);
void	dealing_width(const char *fmt, int *aux, t_bdr *star);
int		find_number_value(char *tobeconv, t_bdr *star);
int		print_u_noflag(t_bdr *star);
int		print_char_noflag(t_bdr *star);
void	print_per_minwnbr(char *tbv, t_bdr *star);
void	vry_nfw_three(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	print_per_zero(char *tbv, t_bdr *star);
void	print_per_m(char *tbv, t_bdr *star);
void	pri_pre_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	print_per_m(char *tbv, t_bdr *star);
void	print_per_wnbr(char *tbv, t_bdr *star);
void	pri_per_wnbr(char *tbv, t_bdr *star);
void	pri_per_zerownbr(char *tbv, t_bdr *star);
void	vry_nfw_four(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
int		pri_min_pre_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	dealing_minus_four(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	deal_min_zero_perc(const char *fmt, int *aux, t_bdr *star);
int		malloc_index(const char *fmt, int *aux);
void	pri_nbr_pre(char *tbv, t_bdr *star);
void	d_pre_zer(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	ft_jumpzero(const char *fmt, int *aux);
void	print_s_zero(char *tbv,  t_bdr *star);
void	p_nbr_pre_i(char *tbv, char *tbvv, t_bdr *star);
void	p_min_pre_i(char *tbv, char *tbvv, t_bdr *star);
void	pri_i_pre_n(t_bdr *star);

#endif
