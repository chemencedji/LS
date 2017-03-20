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

typedef struct		sl_list
{
	char			*name;
	char			*path;
	int				type;
	time_t			tv_sec;
	long			tv_nsec;
	struct sl_list	*sub;
	struct sl_list	*next;
	struct sl_list	*prev;
}					tl_list;

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
void		ft_execute_argv(tl_list **list);
tl_list		*ft_just_ls(char *str);
tl_list		*ft_just_argv(tl_list **list);
tl_list		*ft_cr_argv(char *str, char *path);
tl_list		*ft_cr_alist(char *name, char *str);
tl_list		*ft_cr_argvlist(char *name, char *str);
tl_list		*return_tlist(tl_list **p, tl_list **b, tl_list **r);
char		*ft_linkname(tl_list **elem);
void		ft_sort_for_ck_ar(tl_list **elem, tl_list **list);
void		ft_argv_list_main(char **argv);
void		ft_check_argv(tl_list **list);
void		ft_set_time(tl_list **ptr);
tl_list		*list_create(tl_list **begin_list, char *n, char *str);
tl_list		*list_create_t(tl_list **begin_list, char *n, char *str);
void		ft_add_elem(tl_list **ptr_r, tl_list **ret_r);
void		ft_add_elem_t(tl_list	**ptr_t, tl_list **ret_t);
void		ft_add_help(tl_list **ptr_r, tl_list **ret_r);
void		ft_emthy_ls(tl_list **list);
void		ft_emthy_ls_with_r(tl_list **list);
char		*ft_strjoin_ls(char const *s1, char const *s2);
void		ft_argv_list_main(char **argv);
tl_list		*list_argv(tl_list **begin_list, char *str);
struct stat	get_stat(const char *filename);
void		ft_size_ls(tl_list **list);
void		ft_list_recur(tl_list **rec);
int			ft_block_size(tl_list **all);
tl_list		*ft_just_argv(tl_list **list);
int			ft_is_dir(char *path);
int			ft_is_link(char *path);
int			ft_link_dir(tl_list *str);
void		ft_emthy_argv_with_r(tl_list **list);
void		ft_emthy_argv(tl_list **list);
void		ft_print_l(char *filepath);
void		ft_print_pw_name(char *str);
void		ft_printtime(time_t mtime);
void		ft_print_st_size(int nbr);
void		ft_print_gr_name(char *str);
void		ft_printlink(int nbr);
void		ft_argv_else(tl_list **elem, int x);
void		ft_name(tl_list **elem);
void		ft_go_sub_print(tl_list	**elem);
int			ndigits(int n);
int			ft_argv_scrol(tl_list **list);
int			ft_argv_scrol_r(tl_list **list);
void		ft_first_part(tl_list **elem);
void		ft_open_dir_error(tl_list **elem);
void		ft_print_sub(tl_list **elem);
void		ft_print_sub_r(tl_list **elem);
void		ft_list_scrol(tl_list **list);
void		printrwx(int rd, int wr, int ex, int flag);
tl_list		*list_create_ar(tl_list **begin_list, char *n, char *str);
tl_list		*list_create_ar_t(tl_list **begin_list, char *n, char *str);
tl_list		*ft_just_ls_ar(char *str);
int			ft_lslen(tl_list **list);
int			ft_access(char *str);

#endif
