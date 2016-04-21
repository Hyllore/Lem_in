/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:24:14 by droly             #+#    #+#             */
/*   Updated: 2016/04/21 18:45:43 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hex	*error_links(t_hex *lst)
{
	lst->links->next->next = NULL;
	lst->links = lst->tmpl;
	while (lst->links->next->next->next != NULL)
		lst->links = lst->links->next;
	lst->links->next->next = NULL;
	return (lst);
}
