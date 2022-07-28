/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:22:12 by amenesca          #+#    #+#             */
/*   Updated: 2022/07/28 14:36:00 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	if_file_error(char *str)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	pipe_error(void)
{
	perror("");
	exit(EXIT_FAILURE);
}

void	fork_error(void)
{
	perror("");
	exit(EXIT_FAILURE);
}

void	path_error(char *str)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char *str)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
