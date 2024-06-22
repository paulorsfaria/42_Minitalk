/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:39 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/22 04:17:15 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"
#include <stdbool.h>

char	*ft_create_message(char *message, char bit,int flag)
{
	static int i = 0;
	if(flag == 1)
		i = 0;
	char *new_message;
	new_message = (char *)malloc(sizeof (char) * (i + 2));
	if (!new_message)
	{
		free(message);
		return (NULL);
	}
	new_message[i] = bit;
	i++;
	new_message[i] = '\0';
	if(flag == 1)
		i = 0;
	return new_message;
}
void	signal_handler(int signal)
{
	static unsigned char bit = 0;
	static int			i = 8;
	static char *temp;

	i--;
	if (signal == SIGUSR1)
		bit |= (1 << i);
	else if (signal == SIGUSR2)
		bit &= ~(1 << i);
	if(i == 0)
	{
		temp = ft_create_message(temp, bit, 0);
		if(bit == '\0' || bit == '\n')
		{
			temp = ft_create_message(temp, bit, 1);
			ft_printf("%s\n", temp);
			free(temp);
		}
		bit = 0;
		i = 8;
	}
	usleep(50);
}

int main(void)
{
	ft_printf("The pid is: %d\n", getpid());
	ft_printf("Waiting for a message...\n");

	while(!true != !false)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return(0);
}