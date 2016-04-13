/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:57:43 by droly             #+#    #+#             */
/*   Updated: 2016/04/13 18:34:06 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*malloc_childs(t_tree *tree, t_hex *lst, int i, int i2)
{
	while (lst->links->next != NULL)
	{
		if (ft_strcmp(lst->links->room1, lst->tree->data) == 0 ||
				ft_strcmp(lst->links->room2, lst->tree->data) == 0)
			i++;
		lst->links = lst->links->next;
	}
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
	if ((lst->tree->childs = (t_tree **)malloc(sizeof(t_tree *) * (i + 1))) == NULL)
		error("ERROR : Malloc NULL.");
	while (i2 != i + 1)
	{
		lst->tree->childs[i2] = (t_tree *)malloc(sizeof(t_tree));
		i2++;
	}
	return (lst->tree);
}

int		check_parents(t_hex *lst, t_tree *tree, char *str)
{
	while (lst->tree->parent != NULL)
	{
		if (ft_strcmp(lst->tree->data, str) == 0)
			return (0);
		lst->tree = lst->tree->parent;
	}
	return (1);
}

t_tree	*make_childs(t_hex *lst, t_tree *tree, int i, int i2)
{
	ft_putchar('{');
	ft_putstr(lst->tree->data);
	ft_putchar('}');
	while (lst->links->next != NULL)
	{
		if (ft_strcmp(lst->links->room1, lst->tree->data) == 0)
		{
			ft_putchar('r');
			if (check_parents(lst, lst->tree, lst->links->room2) == 1)
			{
				ft_putchar('x');
				if ((lst->tree->childs[i]->data =
					(char *)malloc(ft_strlen(lst->links->room2) + 1)) == NULL)
					error("ERROR : Malloc NULL.");
				lst->tree->childs[i]->data = ft_strcpy(lst->tree->childs[i]->data,
						lst->links->room2);
				lst->tree->childs[i]->floor = tree->floor + 1;
				ft_putendl(lst->tree->childs[i]->data);
				i++;
			}
		}
		ft_putchar('e');
			if (ft_strcmp(lst->links->room2, lst->tree->data) == 0)
		{
			ft_putchar('u');
			if (check_parents(lst, lst->tree, lst->links->room1))
			{
				if ((lst->tree->childs[i]->data =
					(char *)malloc(ft_strlen(lst->links->room1) + 1)) == NULL)
					error("ERROR : Malloc NULL.");
				lst->tree->childs[i]->data = ft_strcpy(lst->tree->childs[i]->data,
						lst->links->room1);
				lst->tree->childs[i]->floor = lst->tree->floor + 1;
				i++;
			}
		}
		lst->links = lst->links->next;
	}
	lst->tree->childs[i] = NULL;
	return (lst->tree);
}

t_tree	*make_tree(t_hex *lst, t_tree *tree, int i)
{
//	int i;
//	int i2;

//	i2 = 0;
	lst->stop = 0;
	i = 0;
	if (ft_strcmp(lst->tree->data, lst->end) != 0 && lst->stop != 1)
	{
		lst->tree = malloc_childs(lst->tree, lst, 0, 0);
		lst->tree = make_childs(lst, lst->tree, 0, 0);
		while (lst->tree->childs[i] != NULL)
		{
			ft_putendl(lst->tree->data);
			ft_putchar(':');
			ft_putendl(lst->tree->childs[i]->data);
			lst->tree = make_tree(lst, lst->tree, i++);
//			i++;
		}
	}
	if (ft_strcmp(lst->tree->data, lst->end) == 0)
	{
		lst->stop = 1;
		return (lst->tree);
	}
//	if ((tree->childs[0]->data = (char *)malloc(ft_strlen(lst->start) + 1)) == NULL)
//		error("ERROR : Malloc NULL.");
//	if ((tree->childs[1]->data = (char *)malloc(ft_strlen(lst->end) + 1)) == NULL)
//		error("ERROR : Malloc NULL.");
//	ft_strcpy(tree->childs[0]->data, lst->start);
//	ft_strcpy(tree->childs[1]->data, lst->end);
//	tree->childs[2] = NULL;
//	i = 0;
//	while (tree->childs[i] != NULL)
//	{
//		ft_putchar('u');
//		ft_putendl(tree->childs[i]->data);
//		i++;
//	}
	return (tree);
}
