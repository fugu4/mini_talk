static void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i;
	int	timeout;

	i = 8;
	while (i--)
	{
		g_ack = 0;
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		
		timeout = 0;
		while (g_ack == 0 && timeout < 1000)
		{
			usleep(100);
			timeout++;
		}
		if (timeout >= 1000)
		{
			ft_printf("Error: Server timeout\n");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;
	int					i;

	if (argc != 3)
		return (ft_printf("Usage: ./client <PID> <message>\n"), 1);
	pid = (pid_t)ft_atoi(argv[1]);
	
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	
	i = -1;
	while (argv[2][++i])
		send_char(pid, argv[2][i]);
	send_char(pid, '\0');
	ft_printf("Message sent successfully!\n");
	return (0);
}