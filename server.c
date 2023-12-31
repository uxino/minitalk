/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:28:52 by museker           #+#    #+#             */
/*   Updated: 2023/08/17 22:11:07 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);

void	reversebitwise(int signal)
{
	static int	i = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = 0;
	act.sa_handler = &reversebitwise;
	ft_printf("pid: %d\n", getpid());
	if (sigaction(SIGUSR1, &act, NULL) == -1 
		|| sigaction(SIGUSR2, &act, NULL) == -1)
		ft_printf("error");
	while (1)
	{
		pause();
	}
}
