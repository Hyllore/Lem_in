/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:32:49 by droly             #+#    #+#             */
/*   Updated: 2016/03/29 16:56:46 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_putendl_fd("ERROR", 2);
	exit(0);
}

int	main(int argc, char **argv)
{
	int i;
	int i2;
	char **tab;
	char *tab2;
	int fd;
	t_hex *lst;
	t_rooms	*rooms;
	t_links	*links;
	t_rooms	*tmpr;
	t_links	*tmpl;

	links = (t_links*)malloc(sizeof(t_links));
	rooms = (t_rooms*)malloc(sizeof(t_rooms));
	tmpr = rooms;
	tmpl = links;
	i2 = 0;
	lst = (t_hex*)malloc(sizeof(t_hex));
	lst->hex = 0;
	tab2 = NULL;
	tab = NULL;
	i = 0;
	while (get_next_line(0, &tab2) != 0)
	{
		i = 0;
		i2 = 0;
		ft_putendl(tab2);
		if (lst->hex == 0)
			lst->hex = ft_atoi(tab2);
		if (lst->hex == 0)
			error();
		else if (ft_strcmp("##start", tab2) == 0)
		{
			get_next_line(0, &tab2);
			while (tab2[i] != ' ')
				i++;
			lst->start = malloc(sizeof(char) * i);
			lst->start = ft_strncpy(lst->start, tab2, i);
			ft_putendl(tab2);
		}
		else if (ft_strcmp("##end", tab2) == 0)
		{
			get_next_line(0, &tab2);
			while (tab2[i] != ' ')
				i++;
			lst->end = malloc(sizeof(char) * i);
			lst->end = ft_strncpy(lst->end, tab2, i);
			ft_putendl(tab2);
		}
		else if (ft_strchr(tab2, '-') != NULL)
		{
			links->next = (t_links*)malloc(sizeof(t_links));
			while (tab2[i] != '-')
				i++;
			links->room1 = malloc(sizeof(char) * i);
			links->room1 = ft_strncpy(links->room1, tab2, i);
			i = 0;
//			printf("\n-:%s:u\n", links->room1);
			while (tab2[i] != '-')
				i++;
			links->room2 = malloc(sizeof(char) * ft_strlen(&tab2[i]));
			i2 = 0;
			i = 0;
			while (tab2[i] != '-')
				i++;
			i++;
			links->room2 = ft_strcpy(links->room2, &tab2[i]);
//			printf("\n:%s:\n", links->room2);
			i = 0;
			links = links->next;
		}
		else if (ft_strchr(tab2, ' ') != NULL && tab2[0] != '#')
		{
			rooms->next = (t_rooms*)malloc(sizeof(t_rooms));
			while (tab2[i] != ' ')
				i++;
			rooms->room = malloc(sizeof(char) * i);
			rooms->room = ft_strncpy(rooms->room, tab2, i);
			rooms = rooms->next;
			i2++;
		}
	}
	rooms->next = NULL;
	links->next = NULL;
	rooms = tmpr;
	links = tmpl;
	printf("\nfourmis : %d\nstart : %s\nend : %s", lst->hex, lst->start, lst->end);
	while (rooms->next != NULL)
	{
		printf("\nroom : %s", rooms->room);
		rooms = rooms->next;
	}
	while (links->next != NULL)
	{
		printf("\nlinks : %s-%s", links->room1, links->room2);
		links = links->next;
	}
//	ft_putstr(lst->links[0]);
}
