/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:11:48 by boschwie          #+#    #+#             */
/*   Updated: 2024/11/16 19:11:48 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static void	set_stash(int fd, char **stash)
{
	int		bytes_read;
	char	*buffer;
	char	*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_ptr(stash));
	buffer[BUFFER_SIZE] = '\0';
	while (!gnl_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_ptr(stash), free(buffer));
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			return (free(buffer));
		tmp = gnl_strjoin(*stash, buffer);
		if (!tmp)
			return (free_ptr(stash), free(buffer));
		*stash = tmp;
	}
	free(buffer);
}

static char	*extract_line(char *stash)
{
	char	*nl_pos;
	char	*line;

	nl_pos = gnl_strchr(stash, '\n');
	if (!nl_pos)
	{
		line = gnl_strdup(stash);
		if (!line)
			return (NULL);
		return (line);
	}
	line = gnl_substr(stash, 0, nl_pos - stash + 1);
	if (!line)
		return (NULL);
	return (line);
}

static void	refresh_stash(char **stash)
{
	char	*nl_pos;
	char	*tmp;

	nl_pos = gnl_strchr(*stash, '\n');
	if (!nl_pos || (gnl_strlen(nl_pos + 1) == 0))
		return (free_ptr(stash));
	tmp = gnl_strdup(nl_pos + 1);
	if (!tmp)
		return (free_ptr(stash));
	free_ptr(stash);
	*stash = tmp;
}

char	*get_next_line(int fd)
{
	static char	*stash[1025] = {NULL};
	char		*line;

	if (fd < 0)
		return (handle_stash(stash));
	if (fd > 1024 || BUFFER_SIZE <= 0)
	{
		free_ptr(&stash[fd]);
		return (NULL);
	}
	line = NULL;
	set_stash(fd, &stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line || line[0] == '\0')
	{
		free_ptr(&stash[fd]);
		return (NULL);
	}
	refresh_stash(&stash[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	int	fd;
// 	int	i;
// 	char	*res;

// 	i = 0;
// 	fd = open(av[1], O_RDONLY);
// 	while ((res = get_next_line(fd)))
// 	{
// 		printf("Line [%d] : %s", i, res);
// 		free(res);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
