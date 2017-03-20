
#include "libft/includes/libft.h"
#include "ft_ls.h"

void    ft_size_ls_s1(int nbr)
{
	int d;

	d = 1;
	while (nbr /= 10)
		d++;
    if(d > size1)
        size1 = d;
}

void    ft_size_ls_s2(char *str)
{
    int i;
    
    i = ft_strlen(str);
    if(i > size2)
        size2 = i;
}

void    ft_size_ls_s3(char *str)
{
    int i;
    
    i = ft_strlen(str);
    if(i > size3)
        size3 = i;
}

void    ft_size_ls_s4(int nbr)
{
	int d;

	d = 1;
	while (nbr /= 10)
		d++;
    if(d > size4)
        size4 = d;
}

void        ft_size_ls(tl_list **list)
{
    struct  stat pt;
    tl_list *ptr;
    
    ptr = *list;
    size1 = 0;
    size2 = 0;
    size3 = 0;
    size4 = 0;
    while(ptr)
    {
        if(*((char*)ptr->name) == '.' && a == 0)
            ptr = ptr->next;
        else
        {
        if(*((char*)ptr->name) == '/')
            pt = get_stat(ptr->name);
        else
            pt = get_stat(ft_strjoin_ls(ptr->path, ptr->name));
        ft_size_ls_s1(pt.st_nlink);
        ft_size_ls_s2((getpwuid(pt.st_uid))->pw_name);
        ft_size_ls_s3((getgrgid(pt.st_gid))->gr_name);
        ft_size_ls_s4(pt.st_size);
        ptr = ptr->next;
        }
    }
}

int     ft_lslen(tl_list **list)
{
    int i;
    tl_list *ptr;
    
    ptr = *list;
    i = 0;
    while(ptr)
    {
        if(ft_strcmp(ptr->name, ".") == 0 || ft_strcmp(ptr->name, "..") == 0)
            ptr = ptr->next;
        else
        {
        if(ptr->type == 0)
            i++;
        ptr = ptr->next;
        }
    }
    return(i);
}