/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:39 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/24 14:09:48 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"
//char	*ft_create_message(char *message, char bit)
//{
//	int i = 0;
//	char *new_message;
//	if(!message)
//		message= (char *)malloc(sizeof (char) * 2);
//	while(message[i] != '\0')
//		i++;
//	new_message = (char *)malloc(sizeof (char) * (i + 2));
//	if (!new_message)
//	{
//		free(message);
//		return (NULL);
//	}
//	i = 0;
//	while (message[i] != '\0')
//	{
//		new_message[i] = message[i];
//		i++;
//	}
//	new_message[i] = bit;
//	new_message[i + 1] = '\0';
//	return new_message;
//}

void	signal_handler(int signal, siginfo_t *info, void *s)
{
	static unsigned char	bit = 0;
	static int				i = 8;

	(void)s;
	i--;
	if (signal == SIGUSR1)
		bit |= (1 << i);
	else if (signal == SIGUSR2)
		bit &= ~(1 << i);
	if(i == 0)
	{
		ft_printf("%c", bit);
		bit = 0;
		i = 8;
		kill(info->si_pid, SIGUSR2);
	}
	usleep(50);
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
		printf("The PID is: %d\n", pid);
		printf("Waiting for a message...\n");

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
		ft_printf("\033[0;31mError invalid args\033[0m\n");
	return(0);
}