/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:46:36 by bde-mada          #+#    #+#             */
/*   Updated: 2023/06/07 12:29:15 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <string.h>

int	heredoc_to_stdin(t_struct *param)
{
	int		fd_pipe[2];
	pid_t	pid;

	if (pipe(fd_pipe) == -1)
		errors(86, param);
	pid = fork();
	if (pid == -1)
		errors(10, param);
	if (pid == 0)
	{
		close(fd_pipe[READ_END]);
		write(fd_pipe[WRITE_END], param->here_buff, \
				ft_strlen(param->here_buff));
		close(fd_pipe[WRITE_END]);
		errors(0, param);
	}
	else
	{
		close(fd_pipe[WRITE_END]);
		dup2(fd_pipe[READ_END], STDIN_FILENO);
		close(fd_pipe[READ_END]);
		waitpid(-1, NULL, WNOHANG);
	}
	param->fd_in = 0;
	return (0);
}

/*
- ptr[0] input
- ptr[1] read line
- ptr[2] tmp for free
*/
char	*parse_heredoc(char *limiter)
{
	char	*ptr[3];

	ptr[0] = NULL;
	while (1)
	{
		ptr[1] = get_next_line(STDIN_FILENO, 0);
		if (!ft_strncmp(limiter, ptr[1], ft_strlen(limiter)) \
				&& ptr[1][ft_strlen(limiter)] == '\n')
		{
			free(ptr[1]);
			get_next_line(0, 1);
			return (ptr[0]);
		}
		else
		{	
			ptr[2] = ptr[0];
			ptr[0] = ft_strjoin(ptr[0], ptr[1]);
			free (ptr[2]);
			free (ptr[1]);
		}
		if (!ptr[0])
			return (NULL);
	}
	return (ptr[0]);
}

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

int	check_here_doc(t_struct *param, int argc)
{
	param->here_buff = NULL;
	if (!ft_strcmp(param->commands[1], "here_doc"))
	{
		if (argc < 6)
			errors(12, param);
		param->fd_out = open(param->commands[argc - 1], \
							O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (param->fd_out == -1)
			errors(13, param);
		param->arg_pos++;
		param->here_buff = parse_heredoc(param->commands[2]);
		if (param->here_buff)
			heredoc_to_stdin(param);
		return (1);
	}
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
