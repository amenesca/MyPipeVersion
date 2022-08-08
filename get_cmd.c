/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:15:15 by amenesca          #+#    #+#             */
/*   Updated: 2022/08/01 15:09:03 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd(char *argv)
{
	char	**cmd1;
	char	**split;
	char	**path;
	int		i;

	i = -1;
	if (ft_memchr(argv, '/', 1))
	{
		path = ft_split(argv, ' ');
		if (access(path[0], F_OK | X_OK) == 0)
		{
			split = ft_split(argv, '/');
			while (split[++i])
			cmd1 = ft_split(split[i], ' ');
		}
		else
		{
			path_error(path[0]);
			return (0);
		}
	}
	else
		cmd1 = ft_split(argv, ' ');
	return (cmd1);
}
