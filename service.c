#include "minitalk.h"

int	get_pid(char *pid)
{
	int	result;

	result = ft_atoi(pid);
	while (*pid)
	{
		if (ft_isdigit(*pid))
			pid++;
		else
			return -1;
	}
	return (result);
}
