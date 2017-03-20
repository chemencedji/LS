
#include "libft/includes/libft.h"
#include "ft_ls.h"

void		ft_total(tl_list **all)
{
	ft_putstr("total ");
	ft_putnbr(ft_block_size(all));
	ft_putstr("\n");
	ft_size_ls(all);
}

void		ft_go_sub_list(tl_list **elem)
{
	tl_list *ptr;
	DIR		*dir;
	
	ptr = *elem;
	if((dir = opendir(ptr->name)) == NULL && ptr->sub == NULL)
		ft_open_dir_error(&ptr);
	else if(ptr->sub != NULL)
	{
		ft_putstr("\n");
		if(r == 1)
			ft_emthy_ls_with_r(&ptr->sub);
		else
			ft_emthy_ls(&ptr->sub);
	}
}

void        ft_emthy_ls(tl_list **list)
{
	tl_list *all_list;
	tl_list *ptr;
	
	all_list = *list;
	ptr = *list;
	if(r_up == 1)
	{
		if (z == 1)
				ft_putstr(ft_strjoin(all_list->path,":\n"));
		z = 1;
	}
	if(l == 1)
		ft_total(list);
	ft_list_scrol(&all_list);
	while(ptr && r_up == 1)
	{
		if(ptr->type == 0)
		{
			if(*((char*)ptr->name) == '.' && a == 0)
				ptr = ptr->next;
			else if(!(ft_strcmp(ptr->name, ".") == 0 || ft_strcmp(ptr->name, "..") == 0))
			{
				ft_go_sub_list(&ptr);
				ptr= ptr->next;
			}
			else
				ptr= ptr->next;
		}
		else
			ptr = ptr->next;
	}
}

void        ft_emthy_ls_with_r(tl_list **list)
{
	tl_list *all_list;
	tl_list *ptr;

	all_list = *list;
	if(r_up == 1)
	{
		if(z == 1)
			ft_putstr(ft_strjoin(all_list->path,":\n"));
		z = 1;
	}
	if(l == 1)
		ft_total(list);
	while(all_list->next != NULL)
		all_list = all_list->next;
	ptr = all_list;
	ft_list_scrol(&all_list);
	while(ptr && r_up == 1)
	{
		if(ptr->type == 0)
		{
			if(*((char*)ptr->name) == '.' && a == 0)
				ptr = ptr->prev;
			else if(!(ft_strcmp(ptr->name, ".") == 0 || ft_strcmp(ptr->name, "..") == 0))
			{
				ft_go_sub_list(&ptr);
				ptr = ptr->prev;
			}
			else
				ptr= ptr->next;
		}
		else
			ptr = ptr->prev;
	}
}