/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:38:53 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/17 19:24:53 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	main(int argc, char **argv)
{
	pid_t i;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("error: nb argument incorrect\n");
		return (1);
	}
	i = getpid();
	printf("le PID du server est: %d \n", i);
	return (0);
}