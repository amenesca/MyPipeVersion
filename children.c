/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:15:06 by amenesca          #+#    #+#             */
/*   Updated: 2022/07/28 14:34:51 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child1(char *argv[], char **envp, int *fd)
{
	int		pid1;
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		if_file_error(argv[1]);
	pid1 = fork();
	if (pid1 < 0)
		fork_error();
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(file1, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path(envp, cmd(argv[2])), cmd(argv[2]), NULL);
	}
	return (pid1);
}

int	child2(char *argv[], char **envp, int *fd)
{
	int		pid2;
	int		file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file2 == -1)
		if_file_error(argv[4]); 
	pid2 = fork();
	if (pid2 < 0)
		fork_error();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve(path(envp, cmd(argv[3])), cmd(argv[3]), NULL);
	}
	return (pid2);
}
