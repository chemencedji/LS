/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 02:14:54 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/24 02:18:18 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_filetype(mode_t mode)
{
	mode = mode & S_IFMT;
	if (mode == S_IFREG)
		write(1, "-", 1);
	else if (mode == S_IFDIR)
		write(1, "d", 1);
	else if (mode == S_IFLNK)
		write(1, "l", 1);
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

void	print_filepermissions(mode_t mode)
{
	printrwx(mode & S_IRUSR, mode & S_IWUSR, mode & S_IXUSR, mode & S_ISUID);
	printrwx(mode & S_IRGRP, mode & S_IWGRP, mode & S_IXGRP, mode & S_ISGID);
	printrwx(mode & S_IROTH, mode & S_IWOTH, mode & S_IXOTH, mode & S_ISVTX);
}

void	printrwx(int rd, int wr, int ex, int flag)
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

void	printnspaces(int n)
{
	if (n > 0)
	{
		while (n--)
			write(1, " ", 1);
	}
}

int		ndigits(int n)
{
	int d;

	d = 1;
	while (n /= 10)
		d++;
	return (d);
}
