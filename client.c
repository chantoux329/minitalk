/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:38:57 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/12 18:30:03 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	main(int argc, char **argv)
{
	int	i;

	(void)argv;
	if (argc != 3)
	{
		ft_putstr("error: nb argument incorrect\n");
		return (1);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			ft_putstr("PID incorret\n");
			return (1);
		}
		i++;
	}
	return (0);
}