/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:27:03 by jde-maga          #+#    #+#             */
/*   Updated: 2016/05/20 16:45:54 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	line_tools(char *temp, int usage)
{
	int i;

	i = 0;
	if (usage == 0)
	{
		while (temp[i])
		{
			if (temp[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	if (usage == 1)
	{
		while (temp[i])
		{
			if (temp[i] == '\n')
				return (i);
			i++;
		}
		return (0);
	}
	return (0);
}

static char	*get_line(char *temp, int linesize)
{
	char	*otp;
	int		i;

	i = 0;
	otp = ft_strnew(linesize);
	while (i < linesize)
	{
		otp[i] = temp[i];
		i++;
	}
	if (otp[i - 1] == '\n')
		otp[i - 1] = 0;
	otp[i] = '\0';
	return (otp);
}

static char	*temp_after_line(char *temp, char **line)
{
	int		linesize;
	char	*after_line;
	int		i;

	linesize = line_tools(temp, 1);
	*line = get_line(temp, linesize);
	i = 0;
	after_line = ft_strnew(ft_strlen((temp + linesize + 1)));
	while ((temp + linesize + 1)[i])
	{
		after_line[i] = (temp + linesize + 1)[i];
		i++;
	}
	free(temp);
	return (after_line);
}

static int	bitread_parser(int bitread, char *temp, char *buffer, char **line)
{
	if (bitread == -1)
		return (-1);
	if (bitread == 0)
	{
		if (ft_strlen(temp))
		{
			*line = get_line(temp, ft_strlen(temp));
			ft_bzero(temp, ft_strlen(temp));
			return (1);
		}
		free(buffer);
		return (0);
	}
	return (-1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*temp;
	char		*buffer;
	int			bitread;

	if (line == NULL)
		return (-1);
	if (temp == NULL)
		temp = ft_strnew(BUFF_SIZE);
	if (line_tools(temp, 0))
	{
		temp = temp_after_line(temp, line);
		return (1);
	}
	buffer = ft_strnew(BUFF_SIZE);
	bitread = read(fd, buffer, BUFF_SIZE);
	if (bitread <= 0)
		return (bitread_parser(bitread, temp, buffer, line));
	buffer[bitread] = '\0';
	temp = realloc(temp, bitread + ft_strlen(temp) + 1);
	ft_strcat(temp, buffer);
	free(buffer);
	return (get_next_line(fd, line));
}
