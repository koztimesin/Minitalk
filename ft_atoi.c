/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:26:39 by ksaffron          #+#    #+#             */
/*   Updated: 2022/01/28 12:26:20 by ksaffron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/minitalk.h"
#include "./header/minitalk_bonus.h"

static size_t	ft_isspace(size_t c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\t' || c == '\f')
		return (1);
	return (0);
}

static int	ft_get_nb(const char *str, int minus, int *nb)
{
	while (*str >= '0' && *str <= '9')
	{
		if (*nb > 469762049 && minus == 1)
			return (0);
		if (*nb > 469762049 && minus == 0)
			return (-1);
		*nb = ((*nb * 10) + (*str - '0'));
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		minus;
	int		nb;
	int		flag;

	nb = 0;
	minus = 0;
	flag = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '+')
	{
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	if (*str == '-')
		minus = 1;
	if (*str == '-')
		str++;
	flag = ft_get_nb(str, minus, &nb);
	if (flag <= 0)
		return (flag);
	if (minus)
		nb = -nb;
	return (nb);
}
