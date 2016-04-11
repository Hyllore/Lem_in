/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:57:43 by droly             #+#    #+#             */
/*   Updated: 2016/04/11 18:42:41 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*make_tree(t_hex *lst, t_tree *tree, t_tree *tmp)
{
	int i;
	int i2;

	i2 = 0;
	i = 0;
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
	return (tmp);
}
