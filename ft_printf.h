/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:49:45 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/27 10:00:04 by pmartins         ###   ########.fr       */
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
char	*ft_itoa(long n);
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
char	*ft_itoa_base(size_t nb, int base, char updownne, t_bdr *star);
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
void	print_s_zero(char *tbv, t_bdr *star);
void	p_nbr_pre_i(char *tbv, char *tbvv, t_bdr *star);
void	p_min_pre_i(char *tbv, char *tbvv, t_bdr *star);
void	pri_i_pre_n(t_bdr *star);
void	p_int_pre_zero(char *tobeconv, t_bdr *star);
void	pri_pre_u_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	mim_pre_u_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	pri_pre_u_wzero(char *tbv, t_bdr *star);
void	pri_pre_xx_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	pri_pre_x_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	mim_pre_xx_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	mim_pre_x_wnbr(char *tbv, char *tbvv, t_bdr *star);
void	pri_pre_x_wzero(char *tbv, t_bdr *star);
void	pri_pre_xx_wzero(char *tbv, t_bdr *star);
void	p_p_snumb(char *tobeconv, t_bdr *star);
void	p_p_cnumb(char *tbv, char *tbvv, t_bdr *star);
void	print_p_pre(char *tobeconv, t_bdr *star);
void	p_s_pre_width(t_bdr *star);
void	min_s_pre_ww(t_bdr *star);
void	p_int_wid_zero(t_bdr *star);
void	p_int_wid_pre(t_bdr *star);
void	s_pre_width(t_bdr *star);
void	e_pre(int j, int help, t_bdr *star);
void	e_pre_star(const char *fmt, int *aux, t_bdr *star);
void	s_pre(char *tbvv, int *aux, t_bdr *star);
void	e_pre_x_xxdiu(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	d_pre_zero_two(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	dealing_preci_four(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	d_u_pre(char *tbv, int *aux, t_bdr *star);
void	e_spre(int j, int help, t_bdr *star);
void	e_prei(int j, int help, t_bdr *star);
void	e_presw(int j, int help, t_bdr *star);
void	e_prexx(int i, int help, t_bdr *star);
void	e_nprei(int j, int i, int help, t_bdr *star);
void	e_npreione(int j, int i, int help, t_bdr *star);
void	e_prewn(int j, int help, int i, t_bdr *star);
void	e_minusxx(int j, int i, int help, t_bdr *star);
void	e_minusprei(int j, int i, int help, t_bdr *star);
void	e_minuspreione(int j, int i, int help, t_bdr *star);
void	e_minuspreu(int j, int i, int help, t_bdr *star);
void	e_minusdz(int j, int i, int help, t_bdr *star);
void	e_minusdzone(int j, int i, int help, t_bdr *star);
void	e_minuspre(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	e_minuszero(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	e_minuszerotwo(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	e_checkminus(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	e_mnbr(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	ezeroi(int j, int help, t_bdr *star);
void	e_zhalf(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	e_zeronb(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	e_dztwo(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	e_pzeros(int j, int help, t_bdr *star);
void	e_pwidpre(int j, int help, t_bdr *star);
void	e_iwidzend(int j, int help, t_bdr *star);
void	e_iwidzstart(int j, int help, t_bdr *star);
void	e_minprei(int j, int i, int help, t_bdr *star);
void	e_printshalf(int j, int help, t_bdr *star);
void	e_ppcnumb(int j, int i, int help, t_bdr *star);
void	e_pswnumb(int j, int help, t_bdr *star);
void	e_vdwm(char *tbv, const char *fmt, int *aux, t_bdr *star);
void	e_swwone(int help, t_bdr *star);
void	e_swwtwo(int help, t_bdr *star);
void	e_swwthree(int help, t_bdr *star);
void	e_nfwfour(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	e_nfwfive(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
char	*verify_nfw(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	verify_nfw_two(char *tobeconv, const char *fmt, int *aux, t_bdr *star);
void	ft_bzero(void *s, size_t n);
void	pri_nbr_prei(char *tbv, t_bdr *star);
void	*ft_calloc(size_t count, size_t size);
void	e_starprestari(t_bdr *star);
void	e_starprei(int help, t_bdr *star);
void	p_uxxx_starpstar(int *aux, int c, char a, t_bdr *star);
void	e_starprestar(const char *fmt, int *aux, t_bdr *star);
void	p_u_starpstar(int *aux, int c,/* char a,*/ t_bdr *star);
char	*ft_itoa_u(unsigned int nb, int base/*, char updown*/);
int		print_int_zflag(t_bdr *star);
void	ft_pzero_int_wnumb(char *tobeconv, t_bdr *star);

#endif
