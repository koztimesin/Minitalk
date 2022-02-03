/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:05:59 by ksaffron          #+#    #+#             */
/*   Updated: 2022/01/27 16:00:47 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minitalk_bonus.h"

static void	ft_error(void)
{
	ft_putstr_fd("Error", 1);
	exit(0);
}

static void	ft_send(char *str, int pid)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= ft_strlen(str))
	{
		j = 128;
		while (j)
		{
			if (str[i] & j)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error();
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					ft_error();
			j = j / 2;
			usleep(500);
		}
	}
}

static void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
		exit(0);
	usleep(300);
}

int	main(int argc, char **argv)
{
	struct sigaction	my_struct;

	my_struct.sa_flags = SA_SIGINFO;
	my_struct.sa_handler = ft_handler;
	sigaction(SIGUSR1, &my_struct, NULL);
	sigaction(SIGUSR2, &my_struct, NULL);
	if (argc == 3)
	{
		ft_send(argv[2], ft_atoi(argv[1]));
	}
	else
		write(1, "Usage: ./client \'PID\' \"Message\"\n", 32);
}
