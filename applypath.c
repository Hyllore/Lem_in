/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applypath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:40:20 by droly             #+#    #+#             */
/*   Updated: 2016/04/26 14:34:06 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ants(t_path **ants, t_hex *lst)
{
	int i;

	i = 0;
	while (i < lst->ants)
	{
		if ((*ants)[i].checkend == 0 && ft_strcmp((*ants)[i].room, lst->end)
				== 0)
			(*ants)[i].checkend = 1;
		i++;
	}
	i--;
	if ((*ants)[i].checkend == 1)
		return (1);
	return (0);
}

int		check_room(t_path *ants, t_hex *lst, char *room)
{
	int i;

	i = 0;
	while (i < lst->ants)
	{
		if (ants[i].checkend == 0 && ft_strcmp(ants[i].room, room) == 0 &&
				ft_strcmp(ants[i].room, lst->end) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

t_hex	*initialyze_ants(t_hex *lst, t_path **ants, int i, int i2)
{
	while (i < lst->ants)
	{
		(*ants)[i].index = i2;
		(*ants)[i].index2 = 1;
		(*ants)[i].room = lst->start;
		(*ants)[i].checkend = 0;
		i++;
		i2++;
		if (lst->i == i2)
			i2 = 0;
	}
	IND = 0;
	lst->i2 = 0;
	return (lst);
}

t_hex	*count(t_hex *lst)
{
	if (IND == lst->ants)
	{
		lst->i2 = 0;
		ft_putchar('\n');
		IND = 0;
	}
	return (lst);
}

void	apply_path(t_hex *lst, t_path *ants)
{
	if ((ants = (t_path*)malloc(sizeof(t_path) * (lst->ants))) == NULL)
		error("ERROR : Malloc NULL.");
	lst = initialyze_ants(lst, &ants, 0, 0);
	ft_putchar('\n');
	while (check_ants(&ants, lst) == 0)
	{
		while (ants[IND].checkend == 1 || check_room(ants, lst,
					lst->path[ants[IND].index][ants[IND].index2]) == 1)
		{
			IND++;
			lst = count(lst);
		}
		if (lst->path[ants[IND].index][ants[IND].index2])
		{
			if (lst->i2 != 0)
				ft_putchar(' ');
			ft_printf("L%d-%s", IND + 1,
					lst->path[ants[IND].index][ants[IND].index2]);
			lst->i2++;
		}
		ants[IND].room = lst->path[ants[IND].index][ants[IND].index2];
		ants[IND].index2++;
		IND++;
		lst = count(lst);
	}
}
