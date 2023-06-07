/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:51:05 by bde-mada          #+#    #+#             */
/*   Updated: 2023/06/01 16:21:27 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//i[0] = quotes flag
//i[1] = in_word flag
//i[2] = count
static int	count_args(char *str)
{
	int	i[3];

	ft_bzero(i, 3 * sizeof(int));
	while (*str)
	{
		if ((*str == ' ' && !i[0]) || (*str == i[0]))
			i[1] = 0;
		if (*str == i[0])
		{
			i[0] = 0;
			str++;
		}
		if (i[0] == 0 && ft_isquote(*str))
			i[0] = ft_isquote(*str);
		if (*str && *str != ' ' && i[1] == 0)
		{
			i[1] = 1;
			i[2]++;
		}
		if (*str)
			str++;
	}
	if (i[0])
		return (0);
	return (i[2]);
}

//i = position index
//pos[0] = start index
//pos[1] = end index
//pos[2] = quotes flag
static int	*get_args_pos(char *str, int *pos)
{
	int	i;

	i = 0;
	pos[2] = 0;
	while (str[i] == ' ')
		i++;
	if (ft_isquote(str[i]))
		pos[2] = ft_isquote(str[i]);
	pos[0] = i;
	if (pos[2])
		i++;
	if (pos[2] == 0)
		while (str[i] && str[i] != ' ')
			i++;
	else
		while (str[i] && str[i] != pos[2])
			i++;
	pos[1] = i - pos[0];
	return (pos);
}

static char	**fill_args(int *i, int len, int *pos, char *str)
{
	char	**arg_list;

	arg_list = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!arg_list || !pos)
	{
		free(pos);
		return (NULL);
	}
	arg_list[len] = NULL;
	while (i[1] < len)
	{
		get_args_pos(&str[i[0]], pos);
		if (pos[2])
			arg_list[i[1]++] = ft_substr(&str[i[0]], pos[0] + 1, pos[1] - 1);
		else
			arg_list[i[1]++] = ft_substr(&str[i[0]], pos[0], pos[1]);
		if (!arg_list[i[1] - 1])
			return (free_list(arg_list, i[1] - 1));
		i[0] = i[0] + pos[0] + pos[1];
		if (pos[2])
			i[0]++;
	}
	return (arg_list);
}

//i[0] = str_pos
//i[1] = arg_pos
//pos[0] = start index
//pos[1] = end index
//pos[2] = quotes flag
char	**split_args(char *str)
{
	char	**arg_list;
	int		len;
	int		*i;
	int		*pos;

	i = ft_calloc(2, sizeof(int));
	len = count_args(str);
	if (len == 0)
		return (NULL);
	pos = (int *)ft_calloc(3, sizeof(int));
	arg_list = fill_args(i, len, pos, str);
	free(pos);
	free(i);
	return (arg_list);
}

/* int	main(int argc, char *argv[])
{
	char	**arg_list;
	int		i;

	i = -1;
	if (argc != 2)
		return (1);
	ft_printf("Hello\n");
	arg_list = split_args(argv[1]);
	while (arg_list && arg_list[++i])
		ft_printf("arg %d: %s\n", i, arg_list[i]);
	while (--i > -1)
		free(arg_list[i]);
	free(arg_list);
	return (0);
} */
