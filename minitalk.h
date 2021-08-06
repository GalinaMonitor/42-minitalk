#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libft/libft.h"

void	ft_decrypt(int i, siginfo_t *info, void *context);
void	ft_crypt(int byte, int pid);
void	ft_talkback(int sig);
