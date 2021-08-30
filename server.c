/*
**@file					server.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-08-07
**
**@brief				Function receives signals from function-server	**						(SIGUSR1, SIGUSR2) and decrypt them to char.
**						When connection started/ended and after every 	**						decrypted char func sends ack signal.
**
**@used_functions		ft_decrypt, kill, ft_putchar_fd, ft_putnbr_fd, 	**						ft_putstr_fd, sig*, pause
*/

#include "minitalk.h"

void ft_decrypt(int i, siginfo_t *info, void *context)
{
	(void)context;
	static int byte = 0;
	static int count = 0;
	if (i == SIGUSR1)
		byte |= 0b00000001 << count;
	count++;

	if (count == 8)
	{
		if (byte == 0)
		{
			kill(info->si_pid, SIGUSR2);
			count = 0;
		}
		else
		{
			kill(info->si_pid, SIGUSR1);
			ft_putchar_fd(byte, 1);
			count = 0;
			byte = 0;
		}
	}
}

int main()
{
	struct sigaction decrypt;
	// decrypt.sa_flags = SA_RESTART;
	decrypt.sa_flags = SA_SIGINFO;

	decrypt.sa_sigaction = ft_decrypt;
	sigemptyset(&decrypt.sa_mask);

	ft_putstr_fd("My pid is ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nWaiting...\n", 1);

	sigaddset(&decrypt.sa_mask, SIGUSR1);
	sigaddset(&decrypt.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &decrypt, 0);
	sigaction(SIGUSR2, &decrypt, 0);
	while(1)
		pause();
	return 0;
}
