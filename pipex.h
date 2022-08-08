/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:15:39 by amenesca          #+#    #+#             */
/*   Updated: 2022/08/01 15:24:40 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdio.h>

char	*path(char **str, char **cmd);
char	**cmd(char *argv);
int		child1(char *argv[], char **envp, int *fd);
int		child2(char *argv[], char **envp, int *fd);
void	if_file_error(char *str);
void	pipe_error(void);
void	path_error(char *str);
void	fork_error(void);
void	cmd_not_found(char *str);

#endif
