/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigamas <abigamas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:38:36 by abigamas          #+#    #+#             */
/*   Updated: 2024/11/29 17:25:37 by abigamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_archive(char *line_readed, int fd)
{
	char	*buffer;
	char	*aux;
	int		number_bytes;

	buffer = (char *)gnl_ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	number_bytes = 1;
	while (!gnl_ft_strchr(line_readed, '\n') && number_bytes)
	{
		number_bytes = read(fd, buffer, BUFFER_SIZE);
		if (number_bytes < 0)
			return (free(buffer), free(line_readed), NULL);
		if (number_bytes == 0)
			return (free(buffer), line_readed);
		buffer[number_bytes] = '\0';
		aux = line_readed;
		line_readed = gnl_ft_strjoin(line_readed, buffer);
		free(aux);
	}
	return (free(buffer), buffer = NULL, line_readed);
}

char	*create_line(char *line_readed)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	if (!line_readed)
		return (NULL);
	while (line_readed[i] && line_readed[i] != '\n')
		i++;
	if (line_readed[i] == '\n')
		i++;
	result = (char *)gnl_ft_calloc(i + 1, sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = line_readed[j];
		j++;
	}
	return (result);
}

char	*reload_line_readed(char *line_readed)
{
	int		size;
	int		i;
	int		final_size;
	char	*result;
	int		j;

	if (!line_readed)
		return (NULL);
	size = gnl_ft_strlen(line_readed);
	i = 0;
	while (line_readed[i] && line_readed[i] != '\n')
		i++;
	final_size = size - i;
	if (!final_size)
		return (free(line_readed), line_readed = NULL, NULL);
	result = (char *)gnl_ft_calloc(final_size, sizeof(char));
	if (!result)
		return (free(line_readed), line_readed = NULL, NULL);
	j = 0;
	while (j < final_size)
		result[j++] = line_readed[++i];
	return (free(line_readed), line_readed = NULL, result);
}

char	*get_next_line(int fd)
{
	static char	*line_readed[1024];
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_readed[fd] = read_archive(line_readed[fd], fd);
	if (!line_readed[fd])
		return (line_readed[fd] = NULL, NULL);
	if (!line_readed[fd][0])
		return (free(line_readed[fd]), line_readed[fd] = NULL, NULL);
	final_line = create_line(line_readed[fd]);
	if (!final_line)
		return (free(line_readed[fd]), line_readed[fd] = NULL, NULL);
	line_readed[fd] = reload_line_readed(line_readed[fd]);
	return (final_line);
}
