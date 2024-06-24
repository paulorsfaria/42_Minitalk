/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:32 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/24 15:20:05 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"
void	ft_check_delivery(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("string delivered\n");
	else if (signal == SIGUSR2)
		ft_printf("bit delivered\n");

}
void	ft_send_bits(char c, int pid)
{
	int bit = 8;
	while (bit-- > 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
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
		if(!argv[2][0])
			return 0;
		while(argv[2][i] != '\0')
		{
			signal(SIGUSR1, ft_check_delivery);
			signal(SIGUSR2, ft_check_delivery);
			ft_send_bits(argv[2][i], pid);
			i++;
		}
		ft_send_bits('\0', pid);
	}
	else
		ft_printf("\033[0;31mEither you messed up with the args or i messed up\033[0m\n");
    return(0);
}