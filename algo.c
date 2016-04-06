/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:57:43 by droly             #+#    #+#             */
/*   Updated: 2016/04/06 18:04:22 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*make_tree(t_hex *lst, t_tree *tree, t_tree *tmp)
{
	int i;

	i = 0;
	while (lst->links->next != NULL)
	{
		if (lst->links->room1 == tree->data || lst->links->room2 == tree->data)
			i++;
		lst->links = lst->links->next;
	}
	tree->childs = malloc(sizeof(t_tree) * i);



	return (tree);
}
