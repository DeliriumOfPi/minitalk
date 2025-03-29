#include "minitalk.h"

void	process_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit_received = 0;
	static char character = 0;

	character = (character << 1) | (signum == SIGUSR1);
	bit_received++;
	if (bit_received == 8)
	{
		if (character == '\0')
			character = '\n';
		if (write(1, &character, 1) == -1)
			exit(EXIT_FAILURE);
		bit_received = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	listen()
{
	struct sigaction	action;

	action.sa_sigaction = process_signal;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	if (write(1, "\n", 1) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
}

int	main(void)
{
	if (ft_putnbr_fd(getpid(), 1) == -1)
		exit(EXIT_FAILURE);
	listen();
	return (0);
}
