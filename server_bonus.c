/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:35:03 by museker           #+#    #+#             */
/*   Updated: 2023/08/21 15:32:55 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);

void	reversebitwise(int signal, siginfo_t *sig, void *cnt)
{
	static int	i;
	static char	c;

	(void)cnt;
	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		kill(sig->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = 0;
	act.sa_sigaction = reversebitwise;
	ft_printf("pid: %d\n", getpid());
	if (sigaction(SIGUSR1, &act, NULL) == -1 
		||sigaction(SIGUSR2, &act, NULL) == -1)
		ft_printf("error!");
	while (1)
	{
		pause();
	}
}
