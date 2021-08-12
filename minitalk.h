#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

# define SUCCESS 0
# define WRONG_INPUT -1
# define WRONG_PID -2
# define CANT_SEND -3

void	ft_decrypt(int i, siginfo_t *info, void *context);
int		ft_crypt_bit(int byte, int pid);
void	ft_talkback(int sig);
int		ft_crypt_letter_resend(int byte, int pid);

#endif
