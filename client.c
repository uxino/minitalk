/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:28:37 by museker           #+#    #+#             */
/*   Updated: 2023/08/21 18:35:47 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = (10 * count) + (str[i] - '0');
		i++;
	}
	return (count * sign);
}

void	bitwise(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("eksik veya fazla argüman girdiniz!!\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	if (pid <= 0) 
	{
		ft_printf("Invalid PID:\n");
		return (1);
	}
	i = 0;
	while (message[i])
	{
		bitwise(pid, message[i]);
		i++;
	}
	bitwise(pid, '\n');
	return (1);
}
