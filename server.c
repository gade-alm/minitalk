/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:48:04 by gade-alm          #+#    #+#             */
/*   Updated: 2022/06/14 13:54:05 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

void	handle_sigusr(int sig)
{
	static int		binary[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	static int		i = 0;
	static char		sum = 0;

	if (sig == SIGUSR1)
		i++;
	if (sig == SIGUSR2)
		sum = sum + binary[i++];
	if (i >= 8)
	{
		write(1, &sum, 1);
		i = 0;
		sum = 0;
	}
}

int	main(void)
{
	int					pid;

	write (1, "PID: ", 5);
	pid = getpid();
	ft_putnbr(pid);
	write (1, "\n", 1);
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
	{
		pause();
	}
	return (0);
}
