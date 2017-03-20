/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 02:21:28 by mgolban           #+#    #+#             */
/*   Updated: 2017/01/25 12:29:19 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_opt(void)
{
	g_opt.r_up = 0;
	g_opt.l = 0;
	g_opt.a = 0;
	g_opt.t = 0;
	g_opt.r = 0;
	g_opt.l1 = 0;
	g_opt.s_up = 0;
	g_opt.a_up = 0;
	g_opt.t_up = 0;
}

void	set_opt(char *s)
{
	(*s == 'R') ? g_opt.r_up = 1 : 0;
	if (*s == 'l')
	{
		g_opt.l1 = 0;
		g_opt.l = 1;
	}
	(*s == 'a') ? g_opt.a = 1 : 0;
	(*s == 't') ? g_opt.t = 1 : 0;
	(*s == 'r') ? g_opt.r = 1 : 0;
	if (*s == 'g')
	{
		g_opt.l1 = 0;
		g_opt.g = 1;
	}
	(*s == '1') ? g_opt.l1 = 1 : 0;
	if (*s == 'S')
	{
		g_opt.t = 0;
		g_opt.s_up = 1;
	}
	(*s == 'A') ? g_opt.a_up = 1 : 0;
	(*s == 'T') ? g_opt.t_up = 1 : 0;
}

void	check_option(char *str)
{
	if (*str == '-' && *(str + 1) == '\0')
		return ;
	while (*str)
	{
		if (is_valide_symbol(*str) == 0)
		{
			ft_putstr_fd("/bin/ls: illegal option -- ", 2);
			ft_putchar_fd(*str, 2);
			ft_putendl_fd("\n" USAGE, 2);
			exit(EXIT_FAILURE);
		}
		str++;
	}
}

int		is_valide_symbol(char c)
{
	char *s;
	char *p;

	s = "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";
	if ((p = ft_strchr(s, c)))
	{
		set_opt(p);
		return (1);
	}
	return (0);
}
