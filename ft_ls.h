/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:35:01 by ichemenc          #+#    #+#             */
/*   Updated: 2017/03/20 20:48:31 by ichemenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LS_INV "/bin/ls: illegal option -- "
# define US "\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n"
# define SIXMONTH ((365 / 2) * 86400)

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <time.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>

typedef struct		s_ls
{
	char			*name;
	char			*path;
	int				type;
	time_t			tv_sec;
	long			tv_nsec;
	struct s_ls		*sub;
	struct s_ls		*next;
	struct s_ls		*prev;
}					t_ls;

extern int	g_l;
extern int	g_r_up;
extern int	g_a;
extern int	g_r;
extern int	g_t;
extern int	g_z;
extern int	g_x;
extern int	g_u;
extern int	g_y;
extern int	g_argc_num;
extern int	g_errno;
extern int	g_er_ck;
extern int	g_is_link;
extern int	g_cont;
extern int	g_suka;
extern int	g_size1;
extern int	g_size2;
extern int	g_size3;
extern int	g_size4;

int			ft_check(char *argv);
void		ft_set_char();
int			ft_usage(char c);
void		ft_execute(char *str);
void		ft_execute_argv(t_ls **list);
t_ls		*ft_just_ls(char *str);
t_ls		*ft_just_argv(t_ls **list);
t_ls		*ft_cr_argv(char *str, char *path);
t_ls		*ft_cr_alist(char *name, char *str);
t_ls		*ft_cr_argvlist(char *name, char *str);
t_ls		*return_tlist(t_ls **p, t_ls **b, t_ls **r);
char		*ft_linkname(t_ls **elem);
void		ft_sort_for_ck_ar(t_ls **elem, t_ls **list);
void		ft_argv_list_main(char **argv);
void		ft_check_argv(t_ls **list);
void		ft_set_time(t_ls **ptr);
t_ls		*list_create(t_ls **begin_list, char *n, char *str);
t_ls		*list_create_t(t_ls **begin_list, char *n, char *str);
void		ft_add_elem(t_ls **ptr_r, t_ls **ret_r);
void		ft_add_elem_t(t_ls	**ptr_t, t_ls **ret_t);
void		ft_add_help(t_ls **ptr_r, t_ls **ret_r);
void		ft_emthy_ls(t_ls **list);
void		ft_emthy_ls_with_r(t_ls **list);
char		*ft_strjoin_ls(char const *s1, char const *s2);
void		ft_argv_list_main(char **argv);
t_ls		*list_argv(t_ls **begin_list, char *str);
struct stat	get_stat(const char *filename);
void		ft_size_ls(t_ls **list);
void		ft_list_recur(t_ls **rec);
int			ft_block_size(t_ls **all);
t_ls		*ft_just_argv(t_ls **list);
int			ft_is_dir(char *path);
int			ft_is_link(char *path);
int			ft_link_dir(t_ls *str);
void		ft_emthy_argv_with_r(t_ls **list);
void		ft_emthy_argv(t_ls **list);
void		ft_print_l(char *filepath);
void		ft_print_pw_name(char *str);
void		ft_printtime(time_t mtime);
void		ft_print_st_size(int nbr);
void		ft_print_gr_name(char *str);
void		ft_printlink(int nbr);
void		ft_argv_else(t_ls **elem, int x);
void		ft_name(t_ls **elem);
void		ft_go_sub_print(t_ls	**elem);
int			ndigits(int n);
int			ft_argv_scrol(t_ls **list);
int			ft_argv_scrol_r(t_ls **list);
void		ft_first_part(t_ls **elem);
void		ft_open_dir_error(t_ls **elem);
void		ft_print_sub(t_ls **elem);
void		ft_print_sub_r(t_ls **elem);
void		ft_list_scrol(t_ls **list);
void		printrwx(int rd, int wr, int ex, int flag);
t_ls		*list_create_ar(t_ls **begin_list, char *n, char *str);
t_ls		*list_create_ar_t(t_ls **begin_list, char *n, char *str);
t_ls		*ft_just_ls_ar(char *str);
int			ft_lslen(t_ls **list);
int			ft_access(char *str);

#endif
