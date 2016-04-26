/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:57:43 by droly             #+#    #+#             */
/*   Updated: 2016/04/26 15:09:02 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_tree		*malloc_childs(t_tree *tree, t_hex *lst, int i, int i2)
{
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
	while (lst->links->next != NULL)
	{
		if (ft_strcmp(lst->links->room1, tree->data) == 0 ||
				ft_strcmp(lst->links->room2, tree->data) == 0)
			i++;
		lst->links = lst->links->next;
	}
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
	if ((tree->childs = (t_tree **)malloc(sizeof(t_tree *) * (i + 1))) == NULL)
		error("ERROR : Malloc NULL.");
	while (i2 != i + 1)
	{
		tree->childs[i2] = (t_tree *)malloc(sizeof(t_tree));
		i2++;
	}
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
	return (tree);
}

static int			check_parents(t_tree *tree, char *str)
{
	while (tree->parent != NULL)
	{
		if (ft_strcmp(tree->data, str) == 0)
			return (0);
		tree = tree->parent;
	}
	if (ft_strcmp(tree->data, str) == 0)
		return (0);
	return (1);
}

static t_tree		*add_make_childs(t_tree *tree, t_hex *lst, int i)
{
	if ((tree->childs[i]->data =
				(char *)malloc(ft_strlen(lst->links->room1) + 1)) == NULL)
		error("ERROR : Malloc NULL.");
	tree->childs[i]->data = ft_strcpy(tree->childs[i]->data, lst->links->room1);
	tree->childs[i]->floor = tree->floor + 1;
	tree->childs[i]->parent = tree;
	tree->childs[i]->childs = NULL;
	return (tree);
}

static t_tree		*make_childs(t_hex *lst, t_tree *tree, int i)
{
	while (lst->links->next != NULL)
	{
		if (ft_strcmp(lst->links->room1, tree->data) == 0 &&
				check_parents(tree, lst->links->room2) == 1)
		{
			if ((tree->childs[i]->data =
				(char *)malloc(ft_strlen(lst->links->room2) + 1)) == NULL)
				error("ERROR : Malloc NULL.");
			tree->childs[i]->data = ft_strcpy(tree->childs[i]->data,
					lst->links->room2);
			tree->childs[i]->floor = tree->floor + 1;
			tree->childs[i]->parent = tree;
			tree->childs[i]->childs = NULL;
			i++;
		}
		if (ft_strcmp(lst->links->room2, tree->data) == 0 &&
				check_parents(tree, lst->links->room1))
			tree = add_make_childs(tree, lst, i++);
		lst->links = lst->links->next;
	}
	tree->childs[i] = NULL;
	lst->links = lst->tmpl;
	return (tree);
}

unsigned long long	g_floor_max = 9223372036854775807;

void				make_tree(t_hex *lst, t_tree *tree,
		unsigned long long floor)
{
	int				i;

	i = 0;
	if (tree->childs == NULL)
	{
		tree = malloc_childs(tree, lst, 0, 0);
		tree = make_childs(lst, tree, 0);
	}
	while (tree->childs != NULL && tree->childs[i] != NULL &&
			floor < g_floor_max)
	{
		if (ft_strcmp(tree->childs[i]->data, lst->end) == 0)
		{
			g_floor_max = floor;
			return ;
		}
		i++;
	}
	i = 0;
	while (tree->childs != NULL && tree->childs[i] != NULL &&
			floor < g_floor_max)
		make_tree(lst, tree->childs[i++], floor + 1);
	lst->floor_max = g_floor_max;
}
