/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:39:10 by mihail            #+#    #+#             */
/*   Updated: 2017/01/24 22:36:34 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define USAGE "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]"
# define INITOFF {g_off1 = 1; g_off2 = 1; g_off3 = 1; g_off4 = 1;}
# define SIXMONTH ((365 / 2) * 86400)
# include "libft.h"
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef enum	e_bool
{
	false,
	true
}				t_bool;
typedef struct	s_lsopt
{
	t_bool l;
	t_bool r_up;
	t_bool a;
	t_bool r;
	t_bool t;
	t_bool g;
	t_bool l1;
	t_bool s_up;
	t_bool a_up;
	t_bool t_up;
}				t_lsopt;
extern t_lsopt	g_opt;
extern char		*g_dir;
extern int		g_off1;
extern int		g_off2;
extern int		g_off3;
extern int		g_off4;
extern t_bool	g_errflag;
struct stat		get_stat(const char *filename);
t_list			*dircontets(DIR *dirp);
t_list			*get_middle(t_list *head);
t_list			*merge(t_list *a, t_list *b, int (*f)(t_list *, t_list *));
void			check_option(char *str);
void			checkarg(t_list **entries);
void			lexicographical_sort(char **tab[], int i, int argc);
void			ft_ls(char *name);
void			print_filetype(mode_t mode);
void			print_filepermissions(mode_t mode);
void			printrwx(int rd, int wr, int ex, int flag);
void			print_stat(const char *filename);
void			ft_printtime(time_t mtime);
void			init_opt();
void			set_opt(char *s);
void			errexit(char *msg);
void			printname(const char *filename, const char *path);
void			sortlist(t_list **head, int (*f)(t_list *, t_list *));
void			display_file(t_list **stack, t_list *list);
void			ft_printdirs(t_list **arg, t_bool flag);
void			printnspaces(int n);
void			print_opendir_err(void);
void			print_arg_err(t_list *list);
void			print_file(t_list **entries, t_list *list);
void			ft_del_node(t_list **head, t_list **curr, t_list **prev);
void			check_ls_opts(int *i, int argc, char **argv);
void			printfiles(t_list *list);
char			*ft_pathjoin(char *dirpath, char *dir);
t_bool			is_dir(const char *filename);
t_bool			ft_printfiles(t_list **arg);
t_bool			is_dir_link(const char *filename);
int				ft_nrdirs(t_list *list);
int				is_valide_argv(t_list **list, int argc, char **argv);
int				is_valide_symbol(char c);
int				ft_offset(char *dir, t_list *entries);
int				lexsort(t_list *a, t_list *b);
int				func_sort(t_list *a, t_list *b);
int				timesort(t_list *a, t_list *b);
int				print_xattr(const char *filename);
int				sizesort(t_list *a, t_list *b);
int				ndigits(int n);
#endif
