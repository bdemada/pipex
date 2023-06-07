/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:48:02 by bde-mada          #+#    #+#             */
/*   Updated: 2023/06/02 18:18:57 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	del(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	*free_list(char **list, int i)
{
	while (i)
		free(list[i--]);
	free(list);
	return (NULL);
}

void	del_list(char ***ptr)
{
	int	i;

	i = -1;
	while (*ptr && ptr[0][++i])
	{
		free(ptr[0][i]);
		ptr[0][i] = NULL;
	}
	free(*ptr);
	*ptr = NULL;
}

int	free_alloc(t_struct *param)
{
	if (!param)
		return (0);
	if (param->here_buff)
		free(param->here_buff);
	if (param->path_list)
		del_list(&(param->path_list));
	if (param->cmd)
		del_list(&(param->cmd));
	if (param->path)
		free(param->path);
	free(param);
	return (0);
}

void	errors(int error_id, t_struct *param)
{
	if (!error_id)
		exit(free_alloc(param));
	if (error_id == 3)
		errno = 3;
	if (error_id == 22)
		errno = 22;
	if (error_id == 1)
		errno = 1;
	perror("pipex");
	if (error_id == 1)
		ft_putstr_fd("\tPath not found\n", 1);
	if (error_id == 2)
		ft_putstr_fd("\tError while opening files\n", 1);
	if (error_id == 10)
		ft_putstr_fd("\tChild could not be created\n", 1);
	if (error_id == 12)
		ft_putstr_fd("\tMemory error\n", 1);
	if (errno == 86)
		ft_putstr_fd("\tPipe could not be created\n", 1);
	if (error_id == 22)
		ft_putstr_fd(INPUT_ERR_MSG, 1);
	if (errno == 38)
		ft_putstr_fd("\tExecution error", 1);
	free_alloc(param);
	exit(errno);
}
