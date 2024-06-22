/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:00:32 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/22 05:10:29 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../libraries/libft/includes/libft.h"

void ft_send_bits(unsigned char bitter, int pid)
{
	int i = 8;
	while (i--)
	{
		//checkes if the bit at the position i is 1 or 0
		if (bitter >> i & 1)
			kill(pid, SIGUSR1);// shall send sig 1
		else
			kill(pid, SIGUSR2); //shall send sig 2
		usleep(150);
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
//int main(int argc, char *argv[])
//{
//	if(argc == 3)
//	{
//		int i = 0;
//		int pid = ft_atoi(argv[1]);
//		// sends the string to the ./server
//		while(argv[2][i] != '\0')
//		{
//			ft_send_bits(argv[2][i], pid);
//			i++;
//		}
//		/*
//		 * KILL
//		 * IRONICALLY IT SENDS A SIGNAL AND DOEST
//		 * KILL A PROCESS UNLESS YOU SEND A SIGNAL TO KILL
//		*/
//		ft_send_bits('\0', pid);
//	}
//	else
//		ft_printf("Wrong number of parameter\nEx:./client <PID> <MESSAGE>");
//	return(0);
//}




//
//void ft_send_bits(unsigned char bitter, int pid)
//{
//	int i = 8;
//	while (i--)
//	{
//		if (bitter >> i & 1)
//			kill(pid, SIGUSR1);// shall send sig 1
//		else
//			kill(pid, SIGUSR2); //shall send sig 2
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	int i  = 0;
//
//	if (argc != 2)
//		return 1;
//	int pid = ft_atoi(argv[1]);
//	while (argv[2][i] != '\0')
//		ft_send_bits(argv[2][i++], pid);
//	return 0;
//}
