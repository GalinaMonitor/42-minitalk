#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "../ft_printf/ft_printf/libft/libft.h"

void	ft_decrypt(int i, siginfo_t *info, void *context);
void	ft_crypt(int byte, char *argv);
void	ft_talkback(int sig);
