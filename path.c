/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:15:21 by amenesca          #+#    #+#             */
/*   Updated: 2022/07/28 14:31:29 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path(char **str, char **cmd)
{
	int		i;
	char	**paths;
	char	*temp;
	char	*cmd_path;

	i = -1;
	while (str[++i])
	{
		if (ft_strnstr(str[i], "PATH", 5))
			break ;
	}
	paths = ft_split(str[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	cmd_not_found(cmd[0]);
	return (0);
}
