/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:04:24 by droly             #+#    #+#             */
/*   Updated: 2016/03/28 17:08:06 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct	s_hex
{
	int			hex;
	char		*start;
	char		*end;
	char		**rooms;
	char		**links;
}				t_hex;


#endif
