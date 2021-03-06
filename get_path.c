/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:24:14 by droly             #+#    #+#             */
/*   Updated: 2016/04/27 10:03:51 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_all(t_hex *lst, t_tree *tree)
{
	free(lst->path);
	free(lst->start);
	while (lst->links->next != NULL)
	{
		lst->tmpl = lst->links;
		free(lst->links->room1);
		free(lst->links->room2);
		lst->links = lst->links->next;
		free(lst->tmpl);
	}
	while (lst->rooms->next != NULL)
	{
		lst->tmpr = lst->rooms;
		lst->rooms = lst->rooms->next;
		free(lst->tmpr);
	}
	free(lst);
	free(tree->childs);
	free(tree->data);
	free(tree->parent);
	free(tree);
}

t_hex			*error_links(t_hex *lst)
{
	lst->links->next->next = NULL;
	lst->links = lst->tmpl;
	if (lst->links->next)
		if (lst->links->next->next)
			while (lst->links->next->next->next != NULL)
				lst->links = lst->links->next;
	lst->links->next->next = NULL;
	return (lst);
}

void			count_path(t_hex *lst, t_tree *tree, unsigned long long floor)
{
	int			i;

	i = 0;
	while (tree->childs != NULL && tree->childs[i] != NULL &&
			floor <= lst->floor_max)
	{
		if (ft_strcmp(tree->childs[i]->data, lst->end) == 0)
		{
			lst->i++;
			return ;
		}
		i++;
	}
	i = 0;
	while (tree->childs != NULL && tree->childs[i] != NULL &&
			floor <= lst->floor_max)
		count_path(lst, tree->childs[i++], floor + 1);
}

static void		stock_path(t_hex *lst, t_tree *tree)
{
	static int	i = 0;
	int			i2;

	i2 = 0;
	if ((lst->path[i] = (char**)malloc(sizeof(char*) * (lst->floor_max + 2)))
			== NULL)
		error("ERROR : Malloc NULL.");
	lst->path[i][lst->floor_max + 1] = NULL;
	i2 = lst->floor_max;
	while (tree != NULL)
	{
		if ((lst->path[i][i2] = (char*)malloc(sizeof(char) *
						(ft_strlen(tree->data) + 1))) == NULL)
			error("ERROR : Malloc NULL.");
		ft_strcpy(lst->path[i][i2], tree->data);
		lst->path[i][i2][ft_strlen(tree->data)] = '\0';
		i2--;
		tree = tree->parent;
	}
	i++;
}

void			get_path(t_hex *lst, t_tree *tree, unsigned long long floor)
{
	int			i;

	i = 0;
	while (tree->childs != NULL && tree->childs[i] != NULL &&
			floor <= lst->floor_max)
	{
		if (ft_strcmp(tree->childs[i]->data, lst->end) == 0)
		{
			stock_path(lst, tree->childs[i]);
			return ;
		}
		i++;
	}
	i = 0;
	while (tree->childs != NULL && tree->childs[i] != NULL &&
			floor <= lst->floor_max)
		get_path(lst, tree->childs[i++], floor + 1);
}
