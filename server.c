#include "minitalk.h"
#include <stdio.h>

static void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int		bit = 0;
	static int		c = 0;

	(void)ucontext;
	if (sig == SIGUSR2)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		bit = 0;
		c = 0;
	}
	if (info && info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}