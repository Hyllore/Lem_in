/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:32:49 by droly             #+#    #+#             */
/*   Updated: 2016/04/04 18:58:41 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_putendl_fd("\nERROR", 1);
	exit(0);
}

void	addcheckcoord(char *tab, int i, int i2)
{
	if (tab[0] == 'L')
		error();
	while (i2 != 0)
	{
		if (tab[i] == ' ')
			i2--;
		i++;
	}
	while (tab[i] != '\0')
	{
		if ((tab[i] < '0' || tab[i] > '9') && tab[i] != ' ')
			error();
		i++;
	}
}

void	checkcoord(char *tab, int i, int i2)
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
		error();
	i2--;
	i = 0;
	addcheckcoord(tab, i , i2);
}

char	*takename(char *startend ,char *tab, int i)
{
	int i2;

	i2 = 2;
	checkcoord(tab, 0, 0);
	while (tab[i] != '\0')
		i++;
	while (i2 != 0)
	{
		if (tab[i] >= '0' && tab[i] <= '9')
		{
			while (tab[i] >= '0' && tab[i] <= '9')
				i--;
			i2--;
		}
		if (i2 != 0)
			i--;
	}
	startend = malloc(sizeof(char) * (i + 1));
	startend = ft_strncpy(startend, tab, i);
	startend[i] = '\0';
	return (ft_strncpy(startend, tab, i));
}

char	*checkdiese(char *tab)
{
	while (tab[0] == '#')
	{
		ft_putendl(tab);
		get_next_line(0, &tab);
	}
	return (tab);
}

t_hex	*initializelst(char *tab, t_hex *lst, int i)
{
	if (lst->ants == 0)
	{
		lst->ants = ft_atoi(tab);
		return (lst);
	}
	if (lst->ants == 0)
		error();
	else if (ft_strcmp("##start", tab) == 0)
	{
		get_next_line(0, &tab);
		tab = checkdiese(tab);
		lst->start = takename(lst->start, tab, 0);
		ft_putendl(tab);
	}
	else if (ft_strcmp("##end", tab) == 0)
	{
		get_next_line(0, &tab);
		tab = checkdiese(tab);
		lst->end = takename(lst->end, tab, 0);
		ft_putendl(tab);
	}
	(tab[0] == '#' && tab[1] == '#' ? 0 : checkcoord(tab, 0, 0));
	return (lst);
}

t_hex	*initiaizelinks(char *tab, t_hex *lst)
{
	int i;
	int i2;

	i2 = 0;
	i = 0;
	lst->links->next = (t_links*)malloc(sizeof(t_links));
	while (tab[i] != '-')
		i++;
	lst->links->room1 = malloc(sizeof(char) * i);
	lst->links->room1 = ft_strncpy(lst->links->room1, tab, i);
	i = 0;
	while (tab[i] != '-')
		i++;
	lst->links->room2 = malloc(sizeof(char) * ft_strlen(&tab[i]));
	i2 = 0;
	i = 0;
	while (tab[i] != '-')
		i++;
	i++;
	lst->links->room2 = ft_strcpy(lst->links->room2, &tab[i]);
	i = 0;
	if (ft_strcmp(lst->links->room1, lst->links->room2) == 0)
		error();
	lst->links = lst->links->next;
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
			error();
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
			error();
		lst->links = lst->links->next;
	}
	addchecklinks(lst, 0);
	lst->links = lst->tmpl;
	lst->rooms = lst->tmpr;
}

t_hex	*initialize(t_hex *lst, char *tab)
{
	int i;

	i = 0;
	while (get_next_line(0, &tab) != 0)
	{
		i = 0;
		ft_putendl(tab);
		lst = initializelst(tab, lst, 0);
		if (ft_strchr(tab, '-') != NULL)
			lst = initiaizelinks(tab, lst);
		else if (ft_strchr(tab, ' ') != NULL && tab[0] != '#' && tab[0] != 'L')
		{
			lst->rooms->next = (t_rooms*)malloc(sizeof(t_rooms));
			lst->rooms->room = takename(lst->rooms->room, tab, 0);
			lst->rooms = lst->rooms->next;
		}
	}
	lst->rooms->next = NULL;
	lst->links->next = NULL;
	lst->rooms = lst->tmpr;
	lst->links = lst->tmpl;
	checklinks(lst, 0);
	return (lst);
}

int	main(void)
{
	int i;
	char *tab;
	t_hex	*lst;

	lst = (t_hex*)malloc(sizeof(t_hex));
	lst->links = (t_links*)malloc(sizeof(t_links));
	lst->rooms = (t_rooms*)malloc(sizeof(t_rooms));
	lst->tmpr = lst->rooms;
	lst->tmpl = lst->links;
	lst->ants = 0;
	tab = NULL;
	i = 0;
	lst = initialize(lst, tab);
	printf("\nfourmis : %d\nstart : %s\nend : %s", lst->ants, lst->start,
			lst->end);
	while (lst->rooms->next != NULL)
	{
		printf("\nroom : %s", lst->rooms->room);
		lst->rooms = lst->rooms->next;
	}
	while (lst->links->next != NULL)
	{
		printf("\nlinks : %s-%s", lst->links->room1, lst->links->room2);
		lst->links = lst->links->next;
	}
}
