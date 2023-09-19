/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:38:53 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/19 18:20:44 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bin_to_char(int signum, char* c)
{
	
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
	
}

int	main(int argc, char **argv)
{
	pid_t pid_server;
	struct sigaction	sa;
	struct siginfo_t test;

	(void)argv;
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sa.sa_sigaction
	si_pid = 
	if (argc != 1)
	{
		ft_putstr("error: nb argument incorrect\n");
		return (1);
	}
	pid_server = getpid();
	printf("le PID du server est: %d \n", pid_server);
	return (0);
}