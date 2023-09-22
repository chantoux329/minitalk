/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:38:57 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/23 01:06:58 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_getsignal = 0;

int	msg_errors(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("error: nb argument incorrect\n");
		return (1);
		exit(EXIT_FAILURE);
	}
	if (ft_isdigit(argv[1]) == 0)
	{
		ft_putstr("wrong PID");
		return (1);
		exit(EXIT_FAILURE);
	}
	if (argv[2] == NULL)
	{
		ft_putstr("no string to send");
		return (1);
		exit(EXIT_FAILURE);
	}
	else
		return (0);
}

void	send_bit(pid_t pid_server, int bit)
{
	if (bit == 1)
	{
		if (kill(pid_server, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (kill(pid_server, SIGUSR2) == -1)
			exit(EXIT_FAILURE);
	}
	usleep(1000);
}

void	send_to_server(char *str, pid_t pid)
{
	size_t	i;
	int		bit;
	int		bytes;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		bytes = 7;
		while (bytes >= 0)
		{
			bit = (c >> bytes) & 1;
			send_bit(pid, bit);
			bytes--;
			while (!g_getsignal)
				usleep(1000);
			g_getsignal = 0;
		}
		i++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
		ft_putstr("signal here!");
	if (signum == SIGUSR1)
		g_getsignal = 1;
}

int	main(int argc, char **argv)
{
	int					i;
	pid_t				pid_server;
	char				*char_to_send;
	char				*ligne;
	struct sigaction	sigact;

	(void)argv;
	msg_errors(argc, argv);
	pid_server = ft_atoi(argv[1]);
	i = 0;
	char_to_send = argv[2];
	ligne = "\n";
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_handler = &sig_handler;
	sigaction(SIGUSR2, &sigact, 0);
	sigaction(SIGUSR1, &sigact, 0);
	send_to_server(char_to_send, pid_server);
	send_to_server(ligne, pid_server);
	return (0);
}
