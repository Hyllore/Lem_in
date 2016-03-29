/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:04:24 by droly             #+#    #+#             */
/*   Updated: 2016/03/29 16:56:54 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct		s_hex
{
	int				hex;
	char			*start;
	char			*end;
}					t_hex;

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

#endif
