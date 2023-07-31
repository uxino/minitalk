/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:28:52 by museker           #+#    #+#             */
/*   Updated: 2023/08/01 02:55:17 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	reversebitwise(int signal)
{
	static int	i;
	static char	c;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	printf("pid: %d\n", getpid());
	signal(SIGUSR1, reversebitwise);
	signal(SIGUSR2, reversebitwise);
	while (1)
	{
		pause();
	}
}
