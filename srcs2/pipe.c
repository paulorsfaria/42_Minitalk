/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:40:02 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/10 15:40:02 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

extern char **environ;

int	main(void)
{
	char	*path = "/bin/cat";
	char	*cmd[5];

	cmd[0] = "cat";
	cmd[1] = "pipe.c";
	cmd[2] = NULL;
	if (execve(path, cmd, environ) < 0)
		perror(NULL);
	printf("if fail, this will be printed\n");
}