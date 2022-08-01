/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:15:15 by amenesca          #+#    #+#             */
/*   Updated: 2022/08/01 12:34:10 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd(char *argv)
{
	char	**cmd;
	char	**split;
	char	**path;
	int		i;

	i = 0;
	if (ft_memchr(argv, '/', 1))
	{
		path = ft_split(argv, ' ');
		if (access(path[0], F_OK | X_OK) == 0)
		{
			split = ft_split(argv, '/');
			while (split[i])
				i++;
			cmd = ft_split(split[i - 1], ' ');
		}
		else
		{
			path_error(path[0]);
			return (0);
		}
	}
	else 
	{
		i = 0;
		cmd = ft_split(argv, ' ');
		while (cmd[i])
		{
			cmd[i] = ft_strtrim(cmd[i], "'\"");
			i++;
		}
	}
	return (cmd);
}
