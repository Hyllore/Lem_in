/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:32:49 by droly             #+#    #+#             */
/*   Updated: 2016/03/30 18:54:08 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_putendl_fd("ERROR", 2);
	exit(0);
}

void	checkcoord(char *tab)
{
	int i;

	i = 0;
	ft_putchar('u');
	ft_putstr(tab);
	while (tab[i] != ' ' && tab[i] != '\0')
		i++;
	while (tab[i] != '\0')
	{
		ft_putchar('e');
		if ((tab[i] < '0' || tab[i] > '9') && tab[i] != ' ')
			error();
		i++;
	}
}

t_hex	*initializelst(char *tab, t_hex *lst, int i)
{
	if (lst->ants == 0)
		lst->ants = ft_atoi(tab);
	if (lst->ants == 0)
		error();
	else if (ft_strcmp("##start", tab) == 0)
	{
		get_next_line(0, &tab);
		while (tab[i] != ' ')
			i++;
		lst->start = malloc(sizeof(char) * i);
		lst->start = ft_strncpy(lst->start, tab, i);
		ft_putendl(tab);
	}
	else if (ft_strcmp("##end", tab) == 0)
	{
		get_next_line(0, &tab);
		while (tab[i] != ' ')
			i++;
		lst->end = malloc(sizeof(char) * i);
		lst->end = ft_strncpy(lst->end, tab, i);
		ft_putendl(tab);
	}
	checkcoord(tab);
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
	lst->links = lst->links->next;
	return (lst);
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
		else if (ft_strchr(tab, ' ') != NULL && tab[0] != '#')
		{
			lst->rooms->next = (t_rooms*)malloc(sizeof(t_rooms));
			while (tab[i] != ' ')
				i++;
			lst->rooms->room = malloc(sizeof(char) * i);
			lst->rooms->room = ft_strncpy(lst->rooms->room, tab, i);
			lst->rooms = lst->rooms->next;
		}
	}
	lst->rooms->next = NULL;
	lst->links->next = NULL;
	lst->rooms = lst->tmpr;
	lst->links = lst->tmpl;
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
