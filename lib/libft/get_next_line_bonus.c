/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-mada <bde-mada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:08:43 by bde-mada          #+#    #+#             */
/*   Updated: 2023/05/26 15:20:28 by bde-mada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*parse_new(char *next)
{
	int		pos;
	char	*new_next;

	pos = 0;
	while (next[pos] && next[pos] != '\n')
		pos++;
	if (!next[pos])
	{
		free(next);
		return (NULL);
	}
	new_next = (char *)malloc((ft_strlen_gnl(next) - pos) * sizeof(char));
	if (!new_next)
		return (NULL);
	pos++;
	ft_strlcpy_gnl(new_next, next + pos, ft_strlen_gnl(next) - pos + 1);
	free(next);
	return (new_next);
}

char	*get_current_line(char *next)
{
	int		pos;
	char	*line;

	pos = 1;
	if (!*next)
		return (NULL);
	while (next[pos] && next[pos - 1] != '\n')
		pos++;
	line = (char *)malloc((pos + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(line, next, pos + 1);
	return (line);
}

char	*parse_old(int fd, char *next)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(next, '\n') && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(next);
			return (NULL);
		}
		buffer[bytes] = '\0';
		next = ft_strjoin_gnl(next, buffer);
	}
	free(buffer);
	return (next);
}

char	*get_next_line(int fd, int mode)
{
	static char	*next[4096];
	char		*line;

	if (mode)
	{
		free(next[fd]);
		return (NULL);
	}
	if (fd < 0 || fd > 1024)
		return (0);
	if (BUFFER_SIZE <= 0)
	{
		free(next[fd]);
		return (0);
	}
	next[fd] = parse_old(fd, next[fd]);
	if (!next[fd])
		return (NULL);
	line = get_current_line(next[fd]);
	next[fd] = parse_new(next[fd]);
	return (line);
}

/* int	main(void)
{
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*buffer;

	i = 0;
	fd1 = 0;
	fd2 = 0;
	fd3 = 0;
	str1 = NULL;
	str2 = NULL;
	str3 = NULL;
	fd1 = open("myfile", O_RDONLY);
//	fd2 = open("myfile-copy", O_RDONLY);
//	fd3 = open("myfile-copy2", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
		return (-1);
	printf("fd: %d\n", fd1);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	read(fd1, buffer, 1);
	printf("Initial read: %s\n", buffer);
	str1 = get_next_line(fd1);
	printf("Current line: %d\n", i++);
	printf("Line content: %s\n\n\n", str1);
	while (str1)
	{
		str1 = get_next_line(fd1);
//		str2 = get_next_line(fd2);
//		str3 = get_next_line(fd3);
		printf("\nCurrent line: %d\n", i++);
		printf("Line content in fd1: %s\n\n\n", str1);
//		printf("Line content in fd2: %s\n", str2);
//		printf("Line content in fd3: %s\n", str3);
	}
	close(fd1);
//	close(fd2);
//	close(fd3);
	return (0);
} */

//gcc -Wall -Wextra get_next_line.c get_next_line.h get_next_line_utils.c

/* gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line.h
get_next_line_utils.c */