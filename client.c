#include "minitalk.h"

volatile int g_confirm_received = 0;

void	send_char(int server_pid, char c)
{
	int	bit_to_send;

	bit_to_send = 8;
	while (bit_to_send)
	{
		g_confirm_received = 0;
		if ((c >> --bit_to_send) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (!g_confirm_received);
	}
}

void	send_message(int server_pid, char *message)
{
	while (*message)
		send_char(server_pid, *message++);
	send_char(server_pid, '\0');
}

void	confirm_received(int signum)
{
	g_confirm_received = 1;
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;

	if (argc != 3)
		return (-1);
	action.sa_handler = confirm_received;
	signal(SIGUSR1, confirm_received);
	signal(SIGUSR2, confirm_received);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
