/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:16:12 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 21:02:22 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ft_ls.h"

void		print_filetype(mode_t mode)
{
	mode = mode & S_IFMT;
	if (mode == S_IFREG)
		write(1, "-", 1);
	else if (mode == S_IFDIR)
		write(1, "d", 1);
	else if (mode == S_IFLNK)
	{
		write(1, "l", 1);
		g_is_link = 1;
	}
	else if (mode == S_IFBLK)
		write(1, "b", 1);
	else if (mode == S_IFCHR)
		write(1, "c", 1);
	else if (mode == S_IFIFO)
		write(1, "p", 1);
	else if (mode == S_IFSOCK)
		write(1, "s", 1);
	else
		write(1, "?", 1);
}

void		print_filepermissions(mode_t mode)
{
	printrwx(mode & S_IRUSR, mode & S_IWUSR, mode & S_IXUSR, mode & S_ISUID);
	printrwx(mode & S_IRGRP, mode & S_IWGRP, mode & S_IXGRP, mode & S_ISGID);
	printrwx(mode & S_IROTH, mode & S_IWOTH, mode & S_IXOTH, mode & S_ISVTX);
}

void		printrwx(int rd, int wr, int ex, int flag)
{
	if (rd)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (wr)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (ex && (flag == S_ISUID || flag == S_ISGID))
		write(1, "s", 1);
	else if (!ex && (flag == S_ISUID || flag == S_ISGID))
		write(1, "S", 1);
	else if (ex && flag == S_ISVTX)
		write(1, "t", 1);
	else if (!ex && flag == S_ISVTX)
		write(1, "T", 1);
	else if (ex)
		write(1, "x", 1);
	else
		write(1, "-", 1);
}

void		ft_print_l(char *filepath)
{
	struct stat file;

	file = get_stat(filepath);
	print_filetype(file.st_mode);
	print_filepermissions(file.st_mode);
	ft_putstr("  ");
	ft_printlink(file.st_nlink);
	ft_putstr(" ");
	ft_print_pw_name((getpwuid(file.st_uid))->pw_name);
	ft_putstr("  ");
	ft_print_gr_name((getgrgid(file.st_gid))->gr_name);
	ft_putstr("  ");
	ft_print_st_size(file.st_size);
	ft_printtime(file.st_mtime);
}

int			ft_access(char *filename)
{
	struct stat buffer;

	return (lstat(filename, &buffer) == 0);
}
