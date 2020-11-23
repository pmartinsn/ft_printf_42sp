/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:46:50 by pmartins          #+#    #+#             */
/*   Updated: 2020/11/23 15:08:55 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.two.h"

void	check_and_pass(const char *fmt, int *aux, t_bdr *star)
{
	char	*tbv;
	int		i;
	tbv = malloc(malloc_index(fmt, &*aux));
	*aux = *aux + 1;
	if (fmt[*aux] == '*')
	{
		*aux = *aux + 1;
		if ((fmt[*aux] == 'd') | (fmt[*aux] == 'i'))
		{
			*aux = *aux + 1;
			e_starprestari(&*star);
		}
		if (fmt[*aux] == 's')
		{
			i = 0;
			*aux = *aux + 1;
			star->hold = va_arg(star->list, int);
			star->kpr5 = va_arg(star->list, int);
			if (star->hold < 0)
				star->hold = star->hold * -1;
			if (star->kpr5 < 0)
				star->kpr5 = star->kpr5 * -1;
			star->aux_outnbr = va_arg(star->list, char*);
			star->hold = star->hold - star->kpr5;
			while (i < star->hold)
			{
				ft_putchar(' ', &*star);
				i++;
			}
		}
		if ((fmt[*aux] == 'X') | (fmt[*aux] == 'x') | (fmt[*aux] == 'u'))
			e_starprestar(fmt, &*aux, &*star);
	}
	if (fmt[*aux] == '0')
		*aux = *aux + 1;
	if (fmt[*aux] == 's')
	{
		i = 0;
		*aux = *aux + 1;
		star->hold = va_arg(star->list, int);
		star->aux_outnbr = va_arg(star->list, char*);
		while (i < star->hold)
		{
			ft_putchar(' ', &*star);
			i++;
		}
	}
	free(tbv);
	tbv = NULL;
}

void	e_starprestar(const char *fmt, int *aux, t_bdr *star)
{
	//int	i;

	//i = 0;
	//*aux = *aux + 1;
	if (fmt[*aux] == 'X')
		p_uxxx_starpstar(&*aux, 16, 'A', &*star);
	else if (fmt[*aux] == 'x')
		p_uxxx_starpstar(&*aux, 16, 'a', &*star);
	else if (fmt[*aux] == 'u')
		p_uxxx_starpstar(&*aux, 10, 'a', &*star);
}

void	p_uxxx_starpstar(int *aux, int c, char a, t_bdr *star)
{
	int		help;
	int		j;
	size_t	num;
	char	*character;

	help = 0;
	j = *aux;
	j = 0;
	star->hold = 0;
	j = va_arg(star->list, int);
	star->hold = va_arg(star->list, int);
	num = va_arg(star->list, size_t);
	character = ft_itoa_base(num, c, a);
	star->kpr5 = ft_strlen(character);
	if (star->hold < 0)
			star->hold = star->hold * -1;
		if (j < 0)
			j = j * -1;
	j = j - star->hold - star->kpr5;
	if (num > 0)
		ft_putstr(character, &*star);
	if (num == 0)
		j = j + 1;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
	
	free(character);
	character = NULL;
	*aux = *aux + 1;
}

void	dealing_width_two(const char *fmt, int *aux, t_bdr *star)
{
	if (fmt[*aux] == 'p')
	{
		*aux = *aux + 1;
		print_p_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'u')
	{
		*aux = *aux + 1;
		print_u_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'x')
	{
		*aux = *aux + 1;
		print_x_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
	else if (fmt[*aux] == 'X')
	{
		*aux = *aux + 1;
		print_xx_width(&*star);
		print_while(fmt, &*aux, &*star);
	}
}

char	*converter(char *tobeconv, const char *fmt, int *aux)
{
	int index;

	if ((fmt[*aux] != '0') && (fmt[*aux] >= '1' && fmt[*aux] <= '9'))
	{
		index = 0;
		tobeconv[index] = fmt[*aux];
		index++;
		*aux = *aux + 1;
		while (fmt[*aux] >= '0' && fmt[*aux] <= '9')
		{
			tobeconv[index] = fmt[*aux];
			index++;
			*aux = *aux + 1;
		}
	}
	return (tobeconv);
}

int		malloc_index(const char *fmt, int *aux)
{
	int	index;
	int i;

	index = 0;
	i = 0;
	i = *aux;
	if ((fmt[i] != '0') && (fmt[i] >= '1' && fmt[i] <= '9'))
	{
		index++;
		i++;
		while (fmt[i] >= '0' && fmt[i] <= '9')
		{
			index++;
			i++;
		}
	}
	return (index);
}

void	print_per_minwnbr(char *tbv, t_bdr *star)
{
	int j;
	int help;

	j = 0;
	help = 0;
	j = ft_atoi(tbv);
	ft_putchar('%', &*star);
	if (j < 1)
		j = 1;
	else
		j = j - 1;
	while (help < j)
	{
		ft_putchar(' ', &*star);
		help++;
	}
}
