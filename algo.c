/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:57:43 by droly             #+#    #+#             */
/*   Updated: 2016/04/08 18:09:53 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*make_tree(t_hex *lst, t_tree *tree, t_tree *tmp)
{
	int i;

	i = 0;
	while (lst->links->next != NULL)
	{
//		ft_putstr(tree->data);
		if (ft_strcmp(lst->links->room1, tree->data) == 0 ||
				ft_strcmp(lst->links->room2, tree->data) == 0)
		{
			ft_putchar('e');
			i++;
		}
		lst->links = lst->links->next;
	}
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
	printf("\ntree->data : '%s' / ants = %i / lst->start = '%s' / lst->end = '%s'\n", tree->data, lst->ants, lst->start, lst->end);
	if ((tree->childs = (t_tree **)malloc(sizeof(t_tree *) * i)) == NULL)
		error("ERROR : Malloc NULL.");
	ft_putchar('u');
	printf("\ni = %i\n", i);
	tree->childs[0] = NULL;
	tree->childs[1] = NULL;
	if (tree->childs[0])
		ft_putstr("EXISTE\n");
	if (!tree->childs[0])
		ft_putstr("N'EXISTE\n");
	if ((tree->childs[0]->data = (char *)malloc(ft_strlen(lst->start))) == NULL)
		error("ERROR : Malloc NULL.");
	if ((tree->childs[1]->data = (char *)malloc(ft_strlen(lst->end))) == NULL)
		error("ERROR : Malloc NULL.");
	ft_putchar('f');
	ft_strcpy(tree->childs[0]->data, lst->start);
	ft_strcpy(tree->childs[1]->data, lst->end);
//	ft_putchar('e');
	ft_putstr(tree->childs[0]->data);
	ft_putstr(tree->childs[1]->data);
	return (tmp);
}
