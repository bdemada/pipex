/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:39:39 by bde-mada          #+#    #+#             */
/*   Updated: 2023/06/07 12:28:37 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	execute_branch(t_struct *param)
{
	int		exit_status;

	exit_status = 0;
	if (param->pid == 0)
	{
		close(param->fd_pipe[READ_END]);
		dup2(param->fd_pipe[WRITE_END], STDOUT_FILENO);
		execute(param, 0);
	}
	if (param->pid != 0)
	{
		close(param->fd_pipe[WRITE_END]);
		dup2(param->fd_pipe[READ_END], STDIN_FILENO);
		waitpid(-1, &exit_status, WNOHANG);
		if (!WIFEXITED(exit_status))
			errors(38, param);
		if (WIFEXITED(exit_status) && WEXITSTATUS(exit_status))
			errors(exit_status, param);
	}
}

//		ft_printf("PARENT:%s line:%d, pid:%d\n", __func__, __LINE__, getpid());

static void	forks_creation(t_struct *param)
{
	if (pipe(param->fd_pipe) == -1)
		errors(86, param);
	parse_arg(param);
	if (!param->path)
		write_cmdnotfound(param->cmd[0]);
	param->pid = fork();
	if (param->pid == -1)
	{
		close(param->fd_in);
		close(param->fd_out);
		close(param->fd_pipe[READ_END]);
		close(param->fd_pipe[WRITE_END]);
		errors (10, param);
	}
	execute_branch(param);
	del_list(&(param->cmd));
	del(&(param->path));
	close(param->fd_pipe[READ_END]);
	close(param->fd_pipe[WRITE_END]);
}

void	pipex(t_struct *param, int argc)
{
	while (param->arg_pos < argc - 2)
	{
		forks_creation(param);
		param->arg_pos++;
	}
	parse_arg(param);
	if (!param->path)
	{
		write_cmdnotfound(param->cmd[0]);
		free_alloc(param);
		exit(127);
	}
	dup2(param->fd_out, STDOUT_FILENO);
	execute(param, 1);
	close(param->fd_out);
	free_alloc(param);
}

static t_struct	*generate_struct(int argc, char *argv[], char **envp)
{
	t_struct	*param;
	int			i;

	i = 0;
	param = (t_struct *)malloc(sizeof(t_struct));
	if (!param)
		errors(12, param);
	param->commands = argv;
	param->envp = envp;
	param->argc = argc;
	param->arg_pos = 2;
	param->cmd = NULL;
	param->path = NULL;
	while (envp && envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
			i++;
	if (!envp || !*envp)
		param->path_list = NULL;
	else if (envp[i])
	{
		param->path_list = ft_split(envp[i] + 5, ':');
		if (!param->path_list)
			errors(12, param);
	}
	param->is_here_doc = check_here_doc(param, argc);
	return (param);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_struct	*param;

	if (argc < 5)
		errors(22, NULL);
	param = generate_struct(argc, argv, envp);
	pipex(param, argc);
	return (0);
}
