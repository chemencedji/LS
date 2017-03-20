/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:51:01 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/19 12:52:31 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

int				ft_block_size(tl_list **all)
{
	int			i;
	struct stat	sd;
	tl_list		*ptr;
	char		*str;

	i = 0;
	ptr = *all;
	while (ptr)
	{
		str = ft_strjoin_ls(ptr->path, ptr->name);
		if (*((char*)ptr->name) == '.' && a == 0)
			ptr = ptr->next;
		else
		{
			lstat(str, &sd);
			i += sd.st_blocks;
			ptr = ptr->next;
		}
	}
	return (i);
}

struct stat		get_stat(const char *filename)
{
	struct stat buf;

	lstat(filename, &buf);
	return (buf);
}

int				ft_is_dir(char *path)
{
	struct stat path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

int				ft_is_link(char *path)
{
	struct stat path_stat;

	lstat(path, &path_stat);
	return (S_ISLNK(path_stat.st_mode));
}

int				ft_link_dir(tl_list *a)
{
	ssize_t		r;
	struct stat buf;
	char		*link;

	if (*((char*)a->name) == '/')
		buf = get_stat(a->name);
	else
		buf = get_stat(ft_strjoin_ls(a->path, a->name));
	link = malloc(buf.st_size + 1);
	if (*((char*)a->name) == '/')
		r = readlink(a->name, link, buf.st_size + 1);
	else
		r = readlink(ft_strjoin_ls(a->path, a->name), link, buf.st_size + 1);
	link[r] = '\0';
	return (ft_is_dir(link));
}
