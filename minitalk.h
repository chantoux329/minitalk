/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:15:47 by chkala-l          #+#    #+#             */
/*   Updated: 2023/09/23 01:21:57 by chkala-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdlib.h>

char	*ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);
int		ft_isdigit(char *c);

#endif