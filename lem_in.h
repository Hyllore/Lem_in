/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:04:24 by droly             #+#    #+#             */
/*   Updated: 2016/04/26 15:17:19 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define IND lst->i3
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct						s_rooms
{
	char							*room;
	struct s_rooms					*next;
}									t_rooms;

typedef struct						s_links
{
	char							*room1;
	char							*room2;
	struct s_links					*next;
}									t_links;

typedef struct						s_tree
{
	char							*data;
	int								floor;
	struct s_tree					*parent;
	struct s_tree					**childs;
}									t_tree;

typedef struct						s_path
{
	int								index;
	int								index2;
	int								checkend;
	char							*room;
}									t_path;

typedef struct						s_hex
{
	int								i2;
	int								i3;
	int								check;
	char							***path;
	unsigned long long				floor_max;
	int								i;
	int								ants;
	char							*start;
	char							*end;
	t_rooms							*rooms;
	t_links							*links;
	t_rooms							*tmpr;
	t_links							*tmpl;
}									t_hex;

t_hex								*initiaizelinks(char *tab, t_hex *lst);
void								addchecklinks(t_hex *lst, int i);
void								checklinks(t_hex *lst, int i);
t_hex								*analizestartend(t_hex *lst);
t_hex								*initializelst(char *tab, t_hex *lst);
t_hex								*initialize(t_hex *lst, char *tab, int i);
char								*checkdiese(char *tab);
char								*takename(char *startend, char *tab, int i,
		int i2);
void								checkcoord(char *tab, int i, int i2);
void								addcheckcoord(char *tab, int i, int i2);
void								error(char *str);
void								make_tree(t_hex *lst, t_tree *tree,
		unsigned long long floor);
t_hex								*error_links(t_hex *lst);
void								count_path(t_hex *lst, t_tree *tree,
		unsigned long long floor);
void								get_path(t_hex *lst, t_tree *tree,
		unsigned long long floor);
void								apply_path(t_hex *lst, t_path *ants);

#endif
