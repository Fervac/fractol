/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:18:31 by abechet           #+#    #+#             */
/*   Updated: 2018/12/21 11:50:37 by abechet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_line(t_list *current, char **line)
{
	char	*tmp;
	char	*var;

	if ((var = ft_strchr(current->content, '\n')))
	{
		tmp = current->content;
		*line = ft_strsub(tmp, 0, var - tmp);
		current->content = ft_strdup(var + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(current->content);
		ft_strclr(current->content);
	}
}

static int		read_buf(const int fd, t_list *tmp)
{
	char		buf[BUFF_SIZE + 1];
	ssize_t		ret;

	ret = 1;
	if (tmp->content == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp->content = ft_strdup(buf);
	}
	while (!ft_strchr(tmp->content, '\n') && ret >= 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (!(tmp->content = ft_strjoinfree(tmp->content, buf)))
			return (-1);
		if (ret == 0)
			return (0);
	}
	return (1);
}

static t_list	*lstnew(int fd, char *holder)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!(tmp))
		return (NULL);
	if (holder == NULL)
	{
		tmp->content_size = fd;
		tmp->content = NULL;
	}
	tmp->next = NULL;
	return (tmp);
}

static t_list	*check_list(const int fd, t_list **list)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *list;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = lstnew(fd, NULL);
	new->next = *list;
	*list = new;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*current;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, 0, 0))
		return (-1);
	current = check_list(fd, &list);
	if ((ret = read_buf(fd, current)) == -1)
		return (-1);
	fill_line(current, line);
	if (ft_strlen(current->content) == 0 && ret == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
