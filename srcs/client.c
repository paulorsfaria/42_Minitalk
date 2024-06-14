/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:00:32 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/14 05:47:13 by paulo-do         ###   ########.fr       */
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
		if (bitter >> i & 1)
			kill(pid, SIGUSR1);// shall send sig 1
		else
			kill(pid, SIGUSR2); //shall send sig 2
		usleep(150);
	}
}

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
	int i = 0;
		int pid = ft_atoi(argv[1]);
		while(argv[2][i] != '\0')
		{
			ft_send_bits(argv[2][i], pid);
			i++;
		}
		kill(pid, (SIGUSR1 + SIGUSR2));
}
	return(0);
}



























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
