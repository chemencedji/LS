/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 01:56:22 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 20:18:49 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_stat(const char *filename)
{
	struct stat buf;

	buf = get_stat(filename);
	print_filetype(buf.st_mode);
	print_filepermissions(buf.st_mode);
	printnspaces(g_off1 - ndigits(buf.st_nlink) + 2);
	ft_putnbr(buf.st_nlink);
	write(1, " ", 1);
	if (!g_opt.g)
	{
		ft_putstr((getpwuid(buf.st_uid))->pw_name);
		printnspaces(g_off2 - ft_strlen((getpwuid(buf.st_uid))->pw_name) + 2);
	}
	ft_putstr((getgrgid(buf.st_gid))->gr_name);
	printnspaces(g_off4 - ndigits(buf.st_size) + g_off3 -
			ft_strlen((getgrgid(buf.st_gid))->gr_name) + 2);
	ft_putnbr(buf.st_size);
	ft_printtime(buf.st_mtime);
}

int		ft_offset(char *dir, t_list *entries)
{
	struct stat	buf;
	int			n;
	int			total;

	total = 0;
	INITOFF;
	while (entries)
	{
		buf = get_stat(ft_pathjoin(dir, (char *)entries->content));
		total += buf.st_blocks;
		n = ndigits(buf.st_nlink);
		if (n > g_off1)
			g_off1 = n;
		n = ft_strlen((getpwuid(buf.st_uid))->pw_name);
		if (n > g_off2)
			g_off2 = n;
		n = ft_strlen((getgrgid(buf.st_gid))->gr_name);
		if (n > g_off3)
			g_off3 = n;
		n = ndigits(buf.st_size);
		if (n > g_off4)
			g_off4 = n;
		entries = entries->next;
	}
	return (total);
}

void	ft_printtime(time_t mtime)
{
	char	*stime;
	char	*year;

	stime = ft_strchr(ctime(&mtime), ' ');
	if (g_opt.t_up)
	{
		*(ft_strrchr(stime, '\n')) = '\0';
		ft_putstr(stime);
		write(1, " ", 1);
		return ;
	}
	if (time(NULL) < mtime || (time(NULL) - mtime) > SIXMONTH)
	{
		year = ft_strrchr(stime, ' ');
		*(ft_strchr(stime, '\n')) = '\0';
		stime[8] = '\0';
		ft_putstr(stime);
		ft_putstr(year);
	}
	else
	{
		*(ft_strrchr(stime, ':')) = '\0';
		ft_putstr(stime);
	}
	write(1, " ", 1);
}

void	printname(const char *filename, const char *path)
{
	char		*linkname;
	struct stat	buf;
	ssize_t		r;

	buf = get_stat(path);
	if ((g_opt.l || g_opt.g) && !g_opt.l1 && (buf.st_mode & S_IFMT) == S_IFLNK)
	{
		if (!(linkname = malloc(buf.st_size + 1)))
			errexit("linkname");
		if ((r = readlink(path, linkname, buf.st_size + 1)) == -1)
			errexit("readlink");
		linkname[r] = '\0';
		ft_putstr(filename);
		ft_putstr(" -> ");
		ft_putendl(linkname);
		free(linkname);
	}
	else
		ft_putendl(filename);
}
