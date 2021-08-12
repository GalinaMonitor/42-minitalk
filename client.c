/*
**@file					client.c
**@author				Gmonitor (gmonitor@student.21-school.ru)
**@date					2021-08-07
**
**@brief				Function crypts char to binary code and sends it **						by (SIGUSR1, SIGUSR2)
**
**@used_functions		{none}
*/

#include "minitalk.h"

int ack_g = 0;

int ft_crypt_bit(int byte, int pid)
{
	int count = 0;
	while(count <= 7)
	{
		if (byte >> count & 1)
		{
			if (kill(pid, SIGUSR1) != 0)
				return (WRONG_PID);
		}
		else
			if (kill(pid, SIGUSR2) != 0)
				return (WRONG_PID);
		count++;
		usleep(500);
	}
	return (SUCCESS);
}

void	ft_talkback(int sig)
{
	if (sig == SIGUSR2 && ack_g == -1)
	{
		write(1, "Connection started\n", 19);
		ack_g = 1;
	}
	else if (sig == SIGUSR2 && ack_g == -1)
	{
		write(1, "Connection closed\n", 18);
		ack_g = 0;
	}
	if (sig == SIGUSR1 && ack_g == -1)
	{
		write(1, "Signal received\n", 16);
		ack_g = 1;
	}
}

int ft_crypt_letter_resend(int byte, int pid)
{
	int resend;
	int error;

	error = SUCCESS;
	resend = 3;
	while (resend-- > 0)
	{
		ack_g = -1;
		error = ft_crypt_bit(byte, pid);
		if (ack_g == 1)
			return SUCCESS;
		if (resend == 0)
			return (CANT_SEND);
	}
	return error;
}

void	ft_set_handler(struct sigaction *ack)
{
	ack->sa_flags = SA_RESTART;
	ack->sa_handler = ft_talkback;
	sigemptyset(&ack->sa_mask);
	sigaddset(&ack->sa_mask, SIGUSR1);
	sigaddset(&ack->sa_mask, SIGUSR2);

	sigaction(SIGUSR1, ack, 0);
	sigaction(SIGUSR2, ack, 0);
}

int main(int argc, char **argv)
{
	int ind_letter;
	struct sigaction ack;
	int pid;
	int error;

	error = 0;
	ind_letter = 0;
	ft_set_handler(&ack);
	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		write(1, "Wrong input", 11);
		return (WRONG_INPUT);
	}
	error = ft_crypt_letter_resend(0, pid);
	while (argv[2][ind_letter] != '\0' && ack_g == 1)
	{
		error = ft_crypt_letter_resend(argv[2][ind_letter], pid);
		if (error == 0)
			ind_letter++;
	}
	error = ft_crypt_letter_resend(0, pid);
	return (SUCCESS);
}
