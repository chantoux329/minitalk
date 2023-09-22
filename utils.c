/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:18:53 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/23 01:09:20 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (str);
}

void	ft_putnbr(int n)
{
	unsigned int		nb;
	char				c;

	if (n < 0)
	{
		nb = n * -1;
		write(1, "-", 1);
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	x;

	i = 0;
	n = 1;
	x = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
			i++;
	if (nptr[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ((nptr[i] != '\0') && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
			x = x * 10 + (nptr[i] - '0');
			i++;
	}
	return (n * x);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if ((c[i] >= '0' && c[i] <= '9'))
			return (1);
	}
	return (0);
}
