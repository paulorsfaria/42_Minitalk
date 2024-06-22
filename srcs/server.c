/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:39 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/22 05:04:09 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"
#include <stdbool.h>

char	*ft_create_message(char *message, char bit)
{
	int i = 0;
	char *new_message;
	if(!message)
		message= (char *)malloc(sizeof (char) * 2);
	while(message[i] != '\0')
		i++;
	new_message = (char *)malloc(sizeof (char) * (i + 2));
	if (!new_message)
	{
		free(message);
		return (NULL);
	}
	i = 0;
	while (message[i] != '\0')
	{
		new_message[i] = message[i];
		i++;
	}
	new_message[i] = bit;
	new_message[i + 1] = '\0';
	return new_message;
}
void	signal_handler(int signal)
{
	static unsigned char bit = 0;
	static int			i = 8;
	static char temp[49999999];
	static int c = 0;
	i--;
	if (signal == SIGUSR1)
		bit |= (1 << i);
	else if (signal == SIGUSR2)
		bit &= ~(1 << i);
	if(i == 0)
	{
		temp[c] = bit;
		c++;
		temp[c] = '\0';
//		temp = ft_create_message(temp, bit);
		if(bit == '\0')
		{
			ft_printf("%s\n", temp);
//			free(temp);
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