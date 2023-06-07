/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:43:57 by bde-mada          #+#    #+#             */
/*   Updated: 2023/06/07 12:41:21 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define RED		"\x1b[31m"
# define RED_BLIN	"\e[1;5;31m"
# define BLUE_BG	"\x1B[44m"
# define BOLD		"\e[1m"
# define NONE		"\e[m"

// Settings for the pipe fd[]
# define READ_END		0
# define WRITE_END		1

# define INPUT_ERR_MSG "\tInput should be as follows:\n \
		./pipex in_file cmd1 cmd2 out_file\n"

typedef struct s_struct{
	char	**commands;
	char	**envp;
	int		argc;
	int		arg_pos;
	char	**path_list;
	char	**cmd;
	char	*path;
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	int		is_here_doc;
	char	*here_buff;
	pid_t	pid;
}				t_struct;

void	del(char **ptr);
void	*free_list(char **list, int i);
void	del_list(char ***ptr);
int		free_alloc(t_struct *param);
void	errors(int error_id, t_struct *param);

int		ft_isquote(int c);
void	write_cmdnotfound(char *cmd);
void	parse_arg(t_struct *param);
void	execute(t_struct *param, int last);
void	file_open(t_struct *param, int func_mode);

int		open_files(t_struct *param, int argc);

char	**split_args(char *str);

#endif
