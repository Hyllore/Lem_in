/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:57:43 by droly             #+#    #+#             */
/*   Updated: 2016/04/18 17:53:44 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*malloc_childs(t_tree *tree, t_hex *lst, int i, int i2)
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
//	printf("\nmalloc compteur : %d\n", i);
	if ((tree->childs = (t_tree **)malloc(sizeof(t_tree *) * (i + 1))) == NULL)
		error("ERROR : Malloc NULL.");
	while (i2 != i + 1)
	{
		tree->childs[i2] = (t_tree *)malloc(sizeof(t_tree));
		i2++;
	}
	return (tree);
}

int		check_parents(t_hex *lst, t_tree *tree, char *str)
{
//	ft_putchar('t');
	while (tree->parent != NULL)
	{
//		ft_putstr(tree->data);
//		ft_putchar('$');
//		ft_putstr(str);
//		ft_putchar('$');
		if (ft_strcmp(tree->data, str) == 0)
			return (0);
		tree = tree->parent;
	}
//	ft_putstr(tree->data);
//	ft_putchar('$');
//	ft_putstr(str);
//	ft_putchar('$');
	if (ft_strcmp(tree->data, str) == 0)
		return (0);
	return (1);
}

t_tree	*make_childs(t_hex *lst, t_tree *tree, int i, int i2)
{
//	ft_putchar('{');
//	ft_putstr(tree->data);
//	ft_putchar('}');
	while (lst->links->next != NULL)
	{
//		sleep(1);
		if (ft_strcmp(lst->links->room1, tree->data) == 0)
		{
//			ft_putchar('r');
			if (check_parents(lst, tree, lst->links->room2) == 1)
			{
//				ft_putchar('x');
//				ft_putstr(lst->links->room2);
//				printf("\nroom2 : %s salle : %d\n", lst->links->room2, i);
				if ((tree->childs[i]->data =
					(char *)malloc(ft_strlen(lst->links->room2) + 1)) == NULL)
					error("ERROR : Malloc NULL.");
//				ft_putchar('u');
				tree->childs[i]->data = ft_strcpy(tree->childs[i]->data,
						lst->links->room2);
				tree->childs[i]->floor = tree->floor + 1;
				tree->childs[i]->parent = tree;
//				ft_putendl(tree->childs[i]->data);
				i++;
			}
		}
//		ft_putchar('e');
			if (ft_strcmp(lst->links->room2, tree->data) == 0)
		{
//			ft_putchar('u');
			if (check_parents(lst, tree, lst->links->room1))
			{
//				printf("\nroom1 : %s salle : %d\n", lst->links->room1, i);
				if ((tree->childs[i]->data =
					(char *)malloc(ft_strlen(lst->links->room1) + 1)) == NULL)
//					error("ERROR : Malloc NULL.");
				tree->childs[i]->data = ft_strcpy(tree->childs[i]->data,
						lst->links->room1);
				tree->childs[i]->floor = tree->floor + 1;
				tree->childs[i]->parent = tree;
				i++;
			}
		}
		lst->links = lst->links->next;
	}
	tree->childs[i] = NULL;
	return (tree);
}

/*t_hex	*make_tree(t_hex *lst, t_tree *tree)
{
	int i;
//	int i2;

//	i2 = 0;
	lst->stop = 0;
	i = 0;
	if (ft_strcmp(tree->data, lst->end) != 0 && lst->stop != 1)
	{
		tree = malloc_childs(tree, lst, 0, 0);
		tree = make_childs(lst, tree, 0, 0);
		while (tree->childs[i] != NULL)
		{
			sleep(1);
			ft_putendl(tree->data);
			ft_putchar(':');
			ft_putendl(tree->childs[i]->data);
			lst = make_tree(lst, tree->childs[i]);
			i++;
		}
	}
	ft_putchar('e');
	if (ft_strcmp(lst->tree->data, lst->end) == 0 || lst->stop == 1)
	{
//		while (tree->parent != NULL)
		tree = tree->parent;
		lst->tree = tree;
		lst->stop = 1;
		return (lst);
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
	return (lst);
}*/

void	make_tree(t_hex *lst, t_tree *tree, unsigned long long floor)
{
	int i;

	i = 0;
	if (floor >= 2)
		printf("\narbre etage : %d, arbre data : %s parent1 : %s\n", tree->floor, tree->data, tree->parent->data);
	else
		printf("\narbre etage : %d, arbre data : %s\n", tree->floor, tree->data);

	if (tree->childs == NULL)
	{
		tree = malloc_childs(tree, lst, 0, 0);
		tree = make_childs(lst, tree, 0, 0);
	}
	while (tree->childs != NULL && tree->childs[i] != NULL)
	{
		if (ft_strcmp(tree->data, lst->end) == 0)
		{
			ft_putchar('e');
			lst->floor_max = floor;
			return ;
		}
		i++;
	}
	i = 0;
	printf("\nfloor : %lld, floor_max %lld\n", floor, lst->floor_max);
	while (tree->childs[i] != NULL && floor < lst->floor_max)
		make_tree(lst, tree->childs[i++], floor++);
}
