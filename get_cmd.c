/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:15:15 by amenesca          #+#    #+#             */
/*   Updated: 2022/07/25 13:27:06 by amenesca         ###   ########.fr       */
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
	if(ft_memchr(argv, '/', 1))
	{
		path = ft_split(argv, ' ');
		if (access(path[0], F_OK | X_OK) == 0)
		{
			split = ft_split(argv, '/');
			while(split[i])
				i++;
			cmd = ft_split(split[i - 1], ' ');
		}
		else
			return (0);
	}
	else
		cmd = ft_split(argv, ' ');
	return (cmd);
}
