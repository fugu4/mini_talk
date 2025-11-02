#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

extern volatile sig_atomic_t	g_ack; 

void	send_char(pid_t pid, unsigned char c);
#endif