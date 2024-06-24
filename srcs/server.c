/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:39 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/24 15:22:55 by paulo-do         ###   ########.fr       */
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
char *concatenate_an_evaporate(char *str, char c)
{
	int		i = 0;
	char	*temp;

	while(str[i] != '\0')
		i++;
	temp = (char *) ft_calloc(sizeof(char), i + 2);
	i = 0;
	while(str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	free(str);
	temp[i] = c;


	temp[i + 1] = '\0';
	//ft_printf("temp : %s\n", temp);
	return temp;

}
void	signal_handler(int signal, siginfo_t *info, void *s)
{
	static unsigned char	bit = 0;
	static int				i = 8;
	static char *str = NULL;
	if(!str)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
	}
	(void)s;
	usleep(100);
	i--;
	if (signal == SIGUSR1)
		bit |= (1 << i);
	else if (signal == SIGUSR2)
		bit &= ~(1 << i);
	if(i != 0)
		kill(info->si_pid, SIGUSR1);
	if(i == 0)
	{
		str = concatenate_an_evaporate(str, bit);
		if(bit == '\0')
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
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