/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:39:49 by bde-mada          #+#    #+#             */
/*   Updated: 2023/06/07 12:09:39 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (c);
	return (0);
}

void	write_cmdnotfound(char *cmd)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
}

void	parse_arg(t_struct *param)
{
	int		i;
	char	*tmp_path;

	i = 0;
	tmp_path = NULL;
	param->cmd = split_args(param->commands[param->arg_pos]);
	if (!param->cmd)
		errors(12, param);
	param->path = ft_strdup(param->cmd[0]);
	if (!access(param->path, F_OK))
		return ;
	else
		del(&(param->path));
	while (param->path_list && param->path_list[i])
	{
		if (*(param->cmd[0]) != '/')
			tmp_path = ft_strjoin(param->path_list[i], "/");
		if (tmp_path && param->cmd[0])
			param->path = ft_strjoin(tmp_path, param->cmd[0]);
		free(tmp_path);
		if (!access(param->path, F_OK))
			return ;
		del(&(param->path));
		i++;
	}
}

void	execute(t_struct *param, int last)
{
	del_list (&(param->path_list));
	if (!param->path)
	{
		if (param->arg_pos < param->argc - 2)
		{
			free_alloc(param);
			exit(1);
		}
		else
			errors(127, param);
	}
	if (param->fd_in == -1 && param->arg_pos == 2)
	{
		errors(0, param);
	}
	if (execve(param->path, param->cmd, param->envp) == -1)
	{
		write_cmdnotfound(param->cmd[0]);
		if (errno == 13 && !last)
			errors(0, param);
		else
			errors(8, param);
	}
}
