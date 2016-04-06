/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:01:56 by droly             #+#    #+#             */
/*   Updated: 2016/04/06 12:29:03 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	addcheckcoord(char *tab, int i, int i2)
{
	if (tab[0] == 'L')
		error("\nERROR : Rooms names can't begin with : 'L'.");
	while (i2 != 0)
	{
		if (tab[i] == ' ')
			i2--;
		i++;
	}
	while (tab[i] != '\0')
	{
		if ((tab[i] < '0' || tab[i] > '9') && tab[i] != ' ')
			error("\nERROR : Bad coordinates.");
		i++;
	}
}

t_hex	*analizestartend(t_hex *lst)
{
	if (lst->start == NULL)
		error("ERROR : there is no starting point.");
	if (lst->end == NULL)
		error("ERROR : there is no ending point.");
	return (lst);
}

void	addchecklinks(t_hex *lst, int i)
{
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
	while (lst->links->next != NULL)
	{
		i = 0;
		if (ft_strcmp(lst->links->room2, lst->start) == 0)
			i = 1;
		if (ft_strcmp(lst->links->room2, lst->end) == 0)
			i = 1;
		lst->rooms = lst->tmpr;
		while (lst->rooms->next != NULL)
		{
			if (ft_strcmp(lst->rooms->room, lst->links->room2) == 0)
				i = 1;
			lst->rooms = lst->rooms->next;
		}
		if (i == 0)
			error("\nERROR : There is a room I don't know in here.");
		lst->links = lst->links->next;
	}
}

void	checklinks(t_hex *lst, int i)
{
	while (lst->links->next != NULL)
	{
		i = 0;
		if (ft_strcmp(lst->links->room1, lst->start) == 0)
			i = 1;
		if (ft_strcmp(lst->links->room1, lst->end) == 0)
			i = 1;
		lst->rooms = lst->tmpr;
		while (lst->rooms->next != NULL)
		{
			if (ft_strcmp(lst->rooms->room, lst->links->room1) == 0)
				i = 1;
			lst->rooms = lst->rooms->next;
		}
		if (i == 0)
			error("\nERROR : There is a room I don't kwow in here.");
		lst->links = lst->links->next;
	}
	addchecklinks(lst, 0);
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
}
