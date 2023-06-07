/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:46:36 by bde-mada          #+#    #+#             */
/*   Updated: 2023/06/07 12:26:57 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

static int	write_notsuchfile(char *in_file)
{
	if (errno == 13)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(in_file, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (0);
	}
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(in_file, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (0);
}

int	open_files(t_struct *param, int argc)
{
	param->fd_out = open(param->commands[argc - 1], \
								O_WRONLY | O_CREAT | O_TRUNC, 0644);
	param->fd_in = open(param->commands[1], O_RDONLY);
	if (param->fd_in != -1)
		dup2(param->fd_in, STDIN_FILENO);
	if (param->fd_in == -1)
		return (write_notsuchfile(param->commands[1]));
	if (param->fd_out == -1)
		errors(13, param);
	return (0);
}
