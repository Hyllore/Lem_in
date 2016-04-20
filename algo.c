/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:57:43 by droly             #+#    #+#             */
/*   Updated: 2016/04/20 18:51:23 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*malloc_childs(t_tree *tree, t_hex *lst, int i, int i2)
{
	ft_putchar('%');
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
	printf("\n|compteur : %i|\n", i);
	if ((tree->childs = (t_tree **)malloc(sizeof(t_tree *) * (i + 1))) == NULL)
		error("ERROR : Malloc NULL.");
	while (i2 != i + 1)
	{
		ft_putchar('e');
		tree->childs[i2] = (t_tree *)malloc(sizeof(t_tree));
		i2++;
	}
	ft_putnbr(i2);
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
	ft_putchar('$');
	return (tree);
}

int		check_parents(t_hex *lst, t_tree *tree, char *str)
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

t_tree	*make_childs(t_hex *lst, t_tree *tree, int i, int i2)
{
	ft_putchar('<');
	while (lst->links->next != NULL)
	{
		if (ft_strcmp(lst->links->room1, tree->data) == 0)
			if (check_parents(lst, tree, lst->links->room2) == 1)
			{
				ft_putchar('c');
				if ((tree->childs[i]->data =
					(char *)malloc(ft_strlen(lst->links->room2) + 1)) == NULL)
					error("ERROR : Malloc NULL.");
				tree->childs[i]->data = ft_strcpy(tree->childs[i]->data,
						lst->links->room2);
				tree->childs[i]->floor = tree->floor + 1;
				tree->childs[i]->parent = tree;
				i++;
			}
		if (ft_strcmp(lst->links->room2, tree->data) == 0)
			if (check_parents(lst, tree, lst->links->room1))
			{
				ft_putchar('c');
				if ((tree->childs[i]->data =
					(char *)malloc(ft_strlen(lst->links->room1) + 1)) == NULL)
					error("ERROR : Malloc NULL.");
				tree->childs[i]->data = ft_strcpy(tree->childs[i]->data,
						lst->links->room1);
				tree->childs[i]->floor = tree->floor + 1;
				tree->childs[i]->parent = tree;
				i++;
			}
		lst->links = lst->links->next;
	}
	tree->childs[i] = NULL;
	lst->links = lst->tmpl;
	ft_putchar('>');
	return (tree);
}

unsigned long long g_floor_max = 9223372036854775807;

void	make_tree(t_hex *lst, t_tree *tree, unsigned long long floor)
{
	int i;

	i = 0;
	ft_putchar('=');
//	if (tree->childs == NULL)
//	{
	tree = malloc_childs(tree, lst, 0, 0);
	tree = make_childs(lst, tree, 0, 0);
//	}
	ft_putchar('&');
//	if (tree->childs != NULL)
//		printf("\narbre etage : %d, arbre data : %s\n child[0] : ", tree->floor, tree->data);
//	ft_putchar('%');
//	printf("\nfloor : %lld, floor_max %lld\n", floor, g_floor_max);
	ft_putchar('o');
	if (tree->childs == NULL)
	{
		ft_putstr("NULL");
		exit(0);
	}
	ft_putchar('t');
	if (tree->childs[0] == NULL)
		ft_putstr("NULL");
	ft_putchar('p');
	while (tree->childs[i] != NULL)
	{
		ft_putchar('y');
		i++;
	}
	ft_putchar('h');
	i = 0;
	while (tree->childs != NULL && tree->childs[i] != NULL && floor <= g_floor_max)
	{
		ft_putchar('q');
//		printf("childs[%i] = '%s'\n", i, tree->childs[i]->data);
		if (ft_strcmp(tree->childs[i]->data, lst->end) == 0)
		{
			ft_putchar('u');
			g_floor_max = floor;
			return ;
		}
		i++;
		ft_putchar('W');
	}
//	printf("i = %i\n", i);
	i = 0;
//	if (floor >= 2)
//		printf("\narbre etage : %d, arbre data : %s parent1 : %s\n", tree->floor, tree->data, tree->parent->data);
//	else
	ft_putchar('*');
	while (tree->childs[i] != NULL && floor <= g_floor_max)
		make_tree(lst, tree->childs[i++], floor + 1);
	lst->floor_max = g_floor_max;
	ft_putchar('@');
}
