/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:51:01 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 21:05:32 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

int					ft_block_size(t_ls **all)
{
	int				i;
	struct stat		sd;
	t_ls			*ptr;
	char			*str;

	i = 0;
	ptr = *all;
	while (ptr)
	{
		str = ft_strjoin_ls(ptr->path, ptr->name);
		if (*((char*)ptr->name) == '.' && g_a == 0)
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

struct stat			get_stat(const char *filename)
{
	struct stat		buf;

	lstat(filename, &buf);
	return (buf);
}

int					ft_is_dir(char *path)
{
	struct stat		path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

int					ft_is_link(char *path)
{
	struct stat		path_stat;

	lstat(path, &path_stat);
	return (S_ISLNK(path_stat.st_mode));
}

void				ft_set_time(t_ls **ptr)
{
	struct timespec	pt;
	t_ls			*elem;

	elem = *ptr;
	/*pt = get_stat(ft_strjoin_ls(elem->path, elem->name)).st_mtimespec;*/
	elem->tv_sec = pt.tv_sec;
	elem->tv_nsec = pt.tv_nsec;
}
