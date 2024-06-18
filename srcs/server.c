/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:24:30 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/14 20:45:18 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

char *ft_join_bits(char *str, unsigned char bit)
{
	char *new_str;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new_str)
		return NULL;
	int	i = 0;
	while (str[i] != '\0')
	{
		new_str[i]  = str[i];
		i++;
	}
	new_str[i] = bit;
	new_str[i + 1] = '\0';
	free (str);
	usleep(50);
	return new_str;
}

void signal_handler(int signal)
{
	static unsigned char bit = 0b00000000;
	static int i = 8;
	static int flag = 1;
	static int t = 0;
	static char	*temp;
	if(flag == 1)
	{
		free(temp);
		temp = malloc(1);
		temp[0] = '\0';
		flag = 0;
	}
//	if(signal == EOF) // #TODO THIS IS WORNG   THIS NEEDS TO KNOW WHEN I SIGNAL ENDS!
//	{
//		write(1, temp, t);
//		flag = 1;
//		t = 0;
//		bit = 0b00000000;
//		return;
//	 }
	//#TODO FIX THIS THE &= ~(1 << i)   IT WORKS BUT NOT SIMPLE ENOUGH

	/*
	 * HERE I CHECK THE SIGNAL IS SIGUR1 OR SIGUR2 EACH HAS A VALUE 1 OR 0 USING THIS I BUID THE BIT
	 */
	i--;
	if (signal == SIGUSR1)
		bit |= (1 << i); // mete a 1
	else if (signal == SIGUSR2)
		bit &= ~(1 << i); // nao mete a 1
	if(i == 0)
	 {
	/*
	 * here when the i is at 0 it means the bit has been passed so we do a join bits where we put thr bit at the end of
	 * the string and i get reseted for the next bit
	 */
		t++;
		temp = ft_join_bits(temp, bit);
	 	i = 8;
	 }
	usleep(50);
}

int main(int argc, char *argv[])
{
	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	//get_pid gives you the process id duh
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		signal((SIGUSR1 + SIGUSR2), signal_handler);
		pause();
	}

	return(0);
}

