/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:38:57 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/19 18:19:37 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signum, siginfo_t* info, void* context)
{
	
}

int char_to_bin(char c, int pid)
{
	
}
int	main(int argc, char **argv)
{
	int	i;
	pid_t pid_server;

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
	pid_server = argv[1];
	while (argv[2][i] != '\0')
	{
		
	}
	return (0);
}