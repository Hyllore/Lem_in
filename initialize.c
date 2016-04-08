/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:58:30 by droly             #+#    #+#             */
/*   Updated: 2016/04/08 17:07:11 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*checkdiese(char *tab)
{
	while (tab[0] == '#' && tab[1] != '#')
	{
		ft_putendl(tab);
		if (tab != NULL)
			ft_strdel(&tab);
		if (get_next_line(0, &tab) != 1)
			error("ERROR.");
	}
	return (tab);
}

t_hex	*initiaizelinks(char *tab, t_hex *lst)
{
	int i;

	i = 0;
	if ((lst->links->next = (t_links*)malloc(sizeof(t_links))) == NULL)
		error("ERROR : Malloc NULL.");
	while (tab[i] != '-')
		i++;
	ft_putchar('$');
	ft_putnbr(i);
	ft_putchar('*');
	if ((lst->links->room1 = malloc(sizeof(char) * i + 1)) == NULL)
		error("ERROR : Malloc NULL.");
	lst->links->room1 = ft_strncpy(lst->links->room1, tab, i);
	i = 0;
	while (tab[i] != '-')
		i++;
	i++;
	ft_putchar(':');
	ft_putnbr(ft_strlen(&tab[i]));
	ft_putchar(':');
	if ((lst->links->room2 = malloc(sizeof(char) * ft_strlen(&tab[i]) + 1)) == NULL)
		error("ERROR : Malloc NULL.");
	ft_putchar('{');
	ft_putstr(&tab[i]);
	ft_putchar('}');
	lst->links->room2 = ft_strcpy(lst->links->room2, &tab[i]);
	i = 0;
	if (ft_strcmp(lst->links->room1, lst->links->room2) == 0)
		error("\nERROR : You just link a room with itself, no no no -_-.");
	lst->links = lst->links->next;
	return (analizestartend(lst));
}

t_hex	*initializelst(char *tab, t_hex *lst, int i)
{
	if (lst->ants == 0)
		lst->ants = ft_atoi(tab);
	if (lst->ants == 0)
		error("\nERROR : Do you think I can do something without ants ??");
	else if (ft_strcmp("##start", tab) == 0)
	{
//		if (tab != NULL)
//			ft_strdel(&tab);
		if (get_next_line(0, &tab) != 1)
			error("ERROR.");
		tab = checkdiese(tab);
		lst->start = takename(lst->start, tab, 0, 2);
		ft_putendl(tab);
	}
	else if (ft_strcmp("##end", tab) == 0)
	{
//		if (tab != NULL)
//			ft_strdel(&tab);
		if (get_next_line(0, &tab) != 1)
			error("ERROR.");
		tab = checkdiese(tab);
		lst->end = takename(lst->end, tab, 0, 2);
		ft_putendl(tab);
	}
	(tab[0] == '#' && tab[1] == '#' ? 0 : checkcoord(tab, 0, 0));
	return (lst);
}

int		addtakename(char *tab, int i, int i2, int i3)
{
	while (tab[i] >= '0' && tab[i] <= '9')
	{
		i3++;
		i--;
	}
	if (ft_strncmp(ft_itoa(ft_atoi(&tab[i])), &tab[i + 1], i3) != 0)
		error("\nERROR : it's not an int what I see in here.");
	i3 = 0;
	return (i);
}

char	*takename(char *startend, char *tab, int i, int i2)
{
	int i3;

	i3 = 0;
	checkcoord(tab, 0, 0);
	while (tab[i] != '\0')
		i++;
	while (i2 != 0)
	{
	printf("\n[%d-%d]\n", i, i2);
		if (tab[i] >= '0' && tab[i] <= '9')
			i = addtakename(tab, i, i2--, i3);
		if (i2 != 0)
			i--;
	printf("\n[%d-%d]\n", i, i2);
	}
	if ((startend = malloc(sizeof(char) * (i + 1))) == NULL)
		error("ERROR : Malloc NULL.");
//	ft_putstr(tab);
	startend = ft_strncpy(startend, tab, i);
	startend[i] = '\0';
	return (startend);
}
