/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:38:53 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/23 01:20:00 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *pid_clt, void *rien)
{
	static int	bit;
	static int	i;

	(void)rien;
	if (signum == SIGUSR1)
		i |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
	kill (pid_clt->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	server_sa;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("error: nb argument incorrect\n");
		return (1);
	}
	else
	{
		pid_server = getpid();
		sigemptyset(&server_sa.sa_mask);
		server_sa.sa_sigaction = &sig_handler;
		server_sa.sa_flags = SA_SIGINFO;
		ft_putstr("le PID du server est: ");
		ft_putnbr((int)pid_server);
		ft_putstr(" \n");
		sigaction(SIGUSR1, &server_sa, NULL);
		sigaction(SIGUSR2, &server_sa, NULL);
		while (1)
			continue ;
	}
	return (0);
}
