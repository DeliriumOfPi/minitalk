#include "minitalk.h"

void	send_char(int server_pid, char c)
{
	int	bit_to_send;

	bit_to_send = 8;
	while (bit_to_send)
	{
		if ((c >> --bit_to_send) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
	}
}

void	send_message(int server_pid, char *message)
{
	while (*message)
		send_char(server_pid, *message++);
	send_char(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (-1);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
