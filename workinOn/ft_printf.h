/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:49:45 by pmartins          #+#    #+#             */
/*   Updated: 2020/09/01 10:55:15 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include <xlocale.h>

void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_itoa(float n);
char			*ft_strdup(const char *src);
int				ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putbnr_fd(int nb, int fd);
int				ft_validade_and_parse(const char *fmt, va_list prtf);
int				parse_inner(const char *fmt, size_t *i, int *valid);
//size_t			ft_strlen(const char *str);

#endif
