/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:15:33 by amenesca          #+#    #+#             */
/*   Updated: 2022/07/25 13:25:24 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (if_error());
		pid1 = child1(argv, envp, fd);
		pid2 = child2(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
