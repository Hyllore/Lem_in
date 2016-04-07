/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:32:49 by droly             #+#    #+#             */
/*   Updated: 2016/04/07 18:46:13 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		checkcoord(char *tab, int i, int i2)
{
	while (tab[i] != ' ' && tab[i] != '\0')
	{
		i++;
		if (tab[i] == '\0')
			return ;
	}
	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == ' ')
		{
			while (tab[i] == ' ')
				i++;
			i2++;
		}
		i++;
	}
	if (i2 <= 1)
		error("\nERROR : You forgot some coords you fool.");
	i2--;
	i = 0;
	addcheckcoord(tab, i, i2);
}

t_hex		*initialize(t_hex *lst, char *tab)
{
	int		i;

	i = 0;
	while (get_next_line(0, &tab) != 0)
	{
		i = 0;
		tab = checkdiese(tab);
		ft_putendl(tab);
		lst = initializelst(tab, lst, 0);
		if (ft_strchr(tab, '-') != NULL)
			lst = initiaizelinks(tab, lst);
		else if (ft_strchr(tab, ' ') != NULL && tab[0] != '#' && tab[0] != 'L')
		{
			lst->rooms->next = (t_rooms*)malloc(sizeof(t_rooms));
			lst->rooms->room = takename(lst->rooms->room, tab, 0, 2);
			lst->rooms = lst->rooms->next;
		}
		if (tab != NULL)
			ft_strdel(&tab);
	}
	lst->rooms->next = NULL;
	lst->links->next = NULL;
	lst->rooms = lst->tmpr;
	lst->links = lst->tmpl;
	analizestartend(lst);
	checklinks(lst, 0);
	return (lst);
}

int			main(void)
{
	int		i;
	char	*tab;
	t_hex	*lst;
	t_tree	*tree;

	tree = (t_tree*)malloc(sizeof(t_tree));
	lst = (t_hex*)malloc(sizeof(t_hex));
	lst->links = (t_links*)malloc(sizeof(t_links));
	lst->rooms = (t_rooms*)malloc(sizeof(t_rooms));
	lst->tmpr = lst->rooms;
	lst->tmpl = lst->links;
	lst->start = NULL;
	lst->end = NULL;
	lst->ants = 0;
	tab = NULL;
	i = 0;
	lst = initialize(lst, tab);
	tree->data = (char *)malloc(ft_strlen(lst->start));
	ft_strcpy(tree->data, lst->start);
//	tree->data = lst->start;
	printf("tree->data = '%s'\n", tree->data);
	tree->parent = NULL;
	tree->childs = NULL;
	tree = make_tree(lst, tree, tree);
//	printf("\nfourmis : %d\nstart : %s\nend : %s", lst->ants, lst->start,
//			lst->end);
//	while (lst->rooms->next != NULL)
//	{
//		printf("\nroom : %s", lst->rooms->room);
//		lst->rooms = lst->rooms->next;
//	}
//	while (lst->links->next != NULL)
//	{
//		printf("\nlinks : %s-%s", lst->links->room1, lst->links->room2);
//		lst->links = lst->links->next;
//	}
}
