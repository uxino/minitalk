/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:28:37 by museker           #+#    #+#             */
/*   Updated: 2023/08/01 02:54:25 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
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
		ft_putstr("eksik veya fazla argüman girdiniz!!\n");
		return (1);
	}
	pid = atoi(argv[1]);
	message = argv[2];
	if (pid <= 0) 
	{
		ft_putstr("Invalid PID:\n");
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
