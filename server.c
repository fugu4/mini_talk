#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	bit_count = 0;
	static int	character = 0;

	if (signal == SIGUSR1)
		character <<= 1;
	else if (signal == SIGUSR2)
		character = (character << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (character == 0)
			ft_printf("\n");
		else
			ft_printf("%c", character);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
