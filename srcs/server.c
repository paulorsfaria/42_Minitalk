/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:39 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/27 19:45:26 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

static char	*concatenate_an_evaporate(char *str, char c)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] != '\0')
		i++;
	temp = (char *) ft_calloc(sizeof(char), i + 2);
	i = 0;
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	free(str);
	temp[i] = c;
	temp[i + 1] = '\0';
	if (c == '\0')
	{
		ft_printf("%s\n", temp);
		free(temp);
		return (NULL);
	}
	return (temp);
}

static char	*ft_start_char(char *str)
{
	str = malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

static void	signal_handler(int signal, siginfo_t *info, void *s)
{
	static unsigned char	bit = 0;
	static int				i = 8;
	static char				*str;

	if (!str)
		str = ft_start_char(str);
	(void)s;
	usleep(100);
	i--;
	if (signal == SIGUSR1)
		bit |= (1 << i);
	else if (signal == SIGUSR2)
		bit &= ~(1 << i);
	if (i != 0)
		kill(info->si_pid, SIGUSR1);
	if (i == 0)
	{
		str = concatenate_an_evaporate(str, bit);
		bit = 0;
		i = 8;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sig;

	argc--;
	(void)argv;
	if (argc == 0)
	{
		pid = getpid();
		ft_printf("The PID is: %d\n", pid);
		ft_printf("Waiting for a message...\n");
		sig.sa_sigaction = signal_handler;
		sigemptyset(&sig.sa_mask);
		sig.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		usleep(50);
		while (!true != !false)
			pause();
	}
	else
	{
		ft_printf("\033[0;31mError\033[0m\n");
		ft_printf("\033[0;31mEx:./server\033[0m\n");
	}
	return (0);
}
