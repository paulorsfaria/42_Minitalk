/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:32 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/22 01:36:09 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

void	ft_send_bits(char c, int pid)
{
	int bit = 8;
	while (bit-- > 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int main(int argc, char *argv[])
{
	int	pid;
	int	i;
	argc--;
	if (argc == 2)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while(argv[2][i] != '\0')
		{
			ft_printf("shiped 1 bit called: %c\n", argv[2][i]);
			usleep(20);
			ft_send_bits(argv[2][i], pid);
			i++;
		}
		ft_send_bits('\0', pid);
	}
	else
		ft_printf("Either you messed up with the args or i messed up\n");
    return(0);
}