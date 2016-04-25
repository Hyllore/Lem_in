/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:24:14 by droly             #+#    #+#             */
/*   Updated: 2016/04/25 18:51:43 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hex	*error_links(t_hex *lst)
{
	lst->links->next->next = NULL;
	lst->links = lst->tmpl;
	while (lst->links->next->next->next != NULL)
		lst->links = lst->links->next;
	lst->links->next->next = NULL;
	return (lst);
}

void	count_path(t_hex *lst, t_tree *tree, unsigned long long floor)
{
	int	i;

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

static void	stock_path(t_hex *lst, t_tree *tree)
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

void	get_path(t_hex *lst, t_tree *tree, unsigned long long floor)
{
	int	i;

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

/*void	analyze_path(t_hex *lst, t_path *ants)
{
	int i;
	int i2;
	int i3;
	int i4;

	i = 0;
	i2 = 0;
	lst->check = 0;
	while (lst->path[i] != NULL)
	{
		while (lst->path[i][i2] != NULL)
		{
			
		}
		i++;
	}
}*/

int		check_ants(t_path **ants, t_hex *lst)
{
	int i;

	i = 0;
//	ft_putnbr(lst->ants);
	while (i < lst->ants)
	{
//		ft_putstr((*ants)[i].room);
//		ft_putchar('u');
		if ((*ants)[i].checkend == 0 && ft_strcmp((*ants)[i].room, lst->end) == 0)
			(*ants)[i].checkend = 1;
		i++;
	}
//	ft_putchar('e');
	i--;
//	ft_putnbr((*ants)[i].checkend);
	if ((*ants)[i].checkend == 1)
		return (1);
	return (0);
}

int		check_room(t_path *ants, t_hex *lst, char *room)
{
	int i;

	i = 0;
//	ft_putchar('d');
	while (i < lst->ants)
	{
//		ft_putchar('l');
//		ft_putendl(ants[i].room);
//		ft_putendl(room);
		if (ants[i].checkend == 0 && ft_strcmp(ants[i].room, room) == 0 && ft_strcmp(ants[i].room, lst->end) != 0 )
		{
//			ft_putchar('g');
			return (1);
		}
		i++;
	}
//	ft_putchar('b');
	return (0);
}

void	apply_path(t_hex *lst)
{
	t_path *ants;
	int i;
	int i2;

	i2 = 0;
	i = 0;
	if ((ants = (t_path*)malloc(sizeof(t_path) * (lst->ants))) == NULL)
		error("ERROR : Malloc NULL.");
//	analyze_path(lst, ants);
	while (i < lst->ants)
	{
//		ft_putchar('e');
		ants[i].index = i2;
		ants[i].index2 = 1;
		ants[i].room = lst->start;
		ants[i].checkend = 0;
//		ft_putstr(ants[i].room);
		i++;
		i2++;
		if (lst->i == i2)
			i2 = 0;
	}
	i = 0;
//	ft_putchar('i');
	while (check_ants(&ants, lst) == 0)
	{
//		ft_putchar('u');
		ft_putchar('\n');
		while (check_ants(&ants, lst) == 0)
		{
			while (ants[i].checkend == 1 || check_room(ants, lst,
						lst->path[ants[i].index][ants[i].index2]) == 1)
			{
//				ft_putchar('r');
				i++;
				if (i == lst->ants && ants[i - 1].checkend == 1)
					return ;
				if (i == lst->ants)
				{
//					ft_putchar('e');
					ft_putchar('\n');
					i = 0;
				}
//				ft_putchar('t');
			}
			if (i == lst->ants)
			{
				ft_putchar('\n');
				i = 0;
			}
//			sleep(1);
//			ft_putchar('r');
			if (lst->path[ants[i].index][ants[i].index2])
				ft_printf("L%d-%s ", i + 1, lst->path[ants[i].index][ants[i].index2]);
//			ft_putchar('u');
			ants[i].room = lst->path[ants[i].index][ants[i].index2];
			ants[i].index2++;
			i2++;
			i++;
//			ft_putchar('t');
		}
		i2 = 0;
		if (i == lst->ants)
			i = 0;
	}
}
