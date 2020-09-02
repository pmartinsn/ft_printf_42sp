/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartins <pmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:30:46 by pmartins          #+#    #+#             */
/*   Updated: 2020/02/27 10:08:04 by pmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len(int n)
{
	unsigned long int	i;
	long				nb;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static	char		*ft_iszero(int n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

static char			*negative_itoa(int nb, int len)
{
	char		*str;
	long long	n;

	n = nb;
	n = n * -1;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[0] = '-';
	str[len] = '\0';
	while (n != '\0')
	{
		str[len - 1] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}

static	char		*ft_check_itoa(char *str, int n, int len)
{
	len--;
	while (n != '\0')
	{
		str[len] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}

char				*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	aux;

	len = ft_len(n);
	aux = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		return (ft_iszero(n));
	if (aux < 0)
		return (negative_itoa(n, len));
	else
		return (ft_check_itoa(str, n, len));
}
