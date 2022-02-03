/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:25:23 by ksaffron          #+#    #+#             */
/*   Updated: 2022/01/27 19:17:59 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minitalk.h"

void	ft_handler(int signum, siginfo_t *siginfo, void *context)
{
	static char	c = 0;
	static int	pid = 0;
	static int	i = 0;

	(void) context;
	if (siginfo->si_pid != pid || !pid)
	{
		pid = siginfo->si_pid;
		c = 0;
		i = 0;
	}
	c |= (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (c == 0)
			kill(pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	else
		c <<= 1;
	kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	my_struct;

	(void) argv;
	my_struct.sa_flags = SA_SIGINFO;
	my_struct.sa_sigaction = ft_handler;
	if (argc != 1)
	{
		ft_putstr_fd("Error arguments!\n", 1);
		return (0);
	}
	sigaction(SIGUSR1, &my_struct, NULL);
	sigaction(SIGUSR2, &my_struct, NULL);
	ft_putstr_fd("PID:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
