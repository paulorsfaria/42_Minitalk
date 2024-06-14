/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:24:30 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/14 18:21:07 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>



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
	static char	*temp;
	if(flag == 1)
	{
		free(temp);
		temp = malloc(1);
		temp[0] = '\0';
		flag = 0;
	}
	if(signal == (SIGUSR1 + SIGUSR2))
	{
		printf("%s\n", temp);
		flag = 1;
		return;
	 }

	i--;
	if (signal == SIGUSR1)
		bit |= (1 << i); // mete a 1
	else if (signal == SIGUSR2)
		bit &= ~(1 << i); // nao mete a 1
	if(i == 0)
	 {
		 temp = ft_join_bits(temp, bit);
	 	i = 8;
	 }

	usleep(50);
}

int main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal((SIGUSR1 + SIGUSR2), signal_handler);

	while (1)
		pause();
	return(0);
}






















//
//unsigned char bit = 0b00000000;
//void ft_print_bits(int b)
//{
//	static int i;
//
//	if (b == 1)
//		bit |= (1 << i); // mete a 1
//	else
//		bit &= ~(1 << i); // nao mete a 1
//	i++;
//	if(i == 8)
//		i = 0;
//	printf("I AM HERE\n");
//}
//
//char *ft_join_bits(char *str, unsigned char bit)
//{
//	char	*temp;
//	temp = malloc(sizeof(char) * (ft_strlen(str) + 2));
//	if (!temp)
//		return NULL;
//	int	i = 0;
//	printf("I AM HERE\n");
//	while (str[i] != '\0')
//	{
//		temp[i]  = str[i];
//		i++;
//	}
//	temp[i] = bit;
//	temp[i + 1] = '\0';
//	free (str);
//	return temp;
//}
//
//int main()
//{
//	char *str;
//	str = ft_calloc(0 ,2);
//	if(!str)
//		free(str);
//	printf("the pid is: %d\n", getpid());
//	pause();
//
//	ft_print_bits(bit);
//	str = ft_join_bits(str, bit);
//	usleep(100);
//	printf("the string is: %s\n", str);
//	while (1)
//		;
//	usleep(10000000);
//	return 0;
//}
