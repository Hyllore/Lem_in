/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:04:24 by droly             #+#    #+#             */
/*   Updated: 2016/04/14 18:24:12 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct		s_rooms
{
	char			*room;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_links
{
	char			*room1;
	char			*room2;
	struct s_links	*next;
}					t_links;

typedef struct		b_tree
{
	char			*data;
	int				floor;
	struct b_tree	*parent;
	struct b_tree	**childs;
}					t_tree;

typedef struct		s_hex
{
	int				stop;
	int				ants;
	char			*start;
	char			*end;
	t_rooms			*rooms;
	t_links			*links;
	t_rooms			*tmpr;
	t_links			*tmpl;
	t_tree			*tree;
}					t_hex;

t_hex				*initiaizelinks(char *tab, t_hex *lst);
void				addchecklinks(t_hex *lst, int i);
void				checklinks(t_hex *lst, int i);
t_hex				*analizestartend(t_hex *lst);
t_hex				*initializelst(char *tab, t_hex *lst, int i);
t_hex				*initialize(t_hex *lst, char *tab);
char				*checkdiese(char *tab);
char				*takename(char *startend, char *tab, int i, int i2);
void				checkcoord(char *tab, int i, int i2);
void				addcheckcoord(char *tab, int i, int i2);
void				error(char *str);
t_hex				*make_tree(t_hex *lst, t_tree *tree, int i);

#endif
