/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:32:49 by droly             #+#    #+#             */
/*   Updated: 2016/03/28 17:08:04 by droly            ###   ########.fr       */
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

	i2 = 0;
	lst = (t_hex*)malloc(sizeof(t_hex));
	lst->hex = 0;
	tab2 = NULL;
	tab = NULL;
	i = 0;
	while (get_next_line(0, &tab2) != 0)
	{
		ft_putendl(tab2);
		if (lst->hex == 0)
			lst->hex = ft_atoi(tab2);
		if (lst->hex == 0)
			error();
		else if (ft_strcmp("##start", tab2) == 0)
		{
			ft_putchar('e');
			get_next_line(0, &tab2);
			lst->start = ft_itoa(ft_atoi(tab2));
			ft_putendl(tab2);
		}
		else if (ft_strcmp("##end", tab2) == 0)
		{
			ft_putchar('u');
			get_next_line(0, &tab2);
			lst->end = ft_itoa(ft_atoi(tab2));
			ft_putendl(tab2);
		}
		else if (ft_strchr(tab2, '-') != NULL)
		{
			ft_putchar('e');
			ft_putstr(tab2);
			lst->links[i] = tab2;
			ft_putstr("hey");
			i++;
		}
		else if (ft_strchr(tab2, ' ') != NULL)
		{
			ft_putchar('y');
			ft_putstr(tab2);
			lst->rooms[i2] = tab2;
			ft_putchar('t');
			i2++;
		}
	}
	ft_putstr(lst->links[0]);
}
