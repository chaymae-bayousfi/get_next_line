/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:36:42 by cbayousf          #+#    #+#             */
/*   Updated: 2024/12/08 19:37:46 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_new_line(int fd, char *new_line)
{
	char	*buffer;
	int		size_buff;
	char	*tmp;

	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(new_line), NULL);
	size_buff = 1;
	while (!ft_strchr(new_line, '\n') && size_buff != 0)
	{
		size_buff = read(fd, buffer, BUFFER_SIZE);
		if (size_buff < 0)
		{
			free(new_line);
			new_line = NULL;
			return (free(buffer), buffer = NULL, NULL);
		}
		buffer[size_buff] = '\0';
		tmp = new_line;
		new_line = ft_strjoin(new_line, buffer);
		free(tmp);
	}
	free(buffer);
	buffer = NULL;
	return (new_line);
}

static char	*ft_write_new_line(char *new_line)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!new_line || !*new_line)
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	line = ft_substr(new_line, 0, i);
	if (!line)
		return (free(new_line), new_line = NULL, NULL);
	return (line);
}

static char	*ft_get_new_line(char *new_line)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	if (!new_line)
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	if (new_line[i] == '\0')
		return (free(new_line), new_line = NULL, NULL);
	j = i;
	while (new_line[j] != '\0')
		j++;
	new = ft_substr(new_line, i, j - i);
	if (!new)
		return (free(new_line), new_line = NULL, NULL);
	free (new_line);
	new_line = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*new_line[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd > OPEN_MAX)
		return (NULL);
	new_line[fd] = ft_read_new_line(fd, new_line[fd]);
	if (!new_line[fd])
		return (NULL);
	line = ft_write_new_line(new_line[fd]);
	if (!line)
		return (free(new_line[fd]), new_line[fd] = NULL, NULL);
	new_line[fd] = ft_get_new_line(new_line[fd]);
	return (line);
}
