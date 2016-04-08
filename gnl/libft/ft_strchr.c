/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:59:27 by droly             #+#    #+#             */
/*   Updated: 2016/04/08 18:09:51 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	ft_putstr("->");
	ft_putstr((char*)s);
	ft_putstr("<-");
//	while (s[i] != '\0')
//	{
//		ft_putchar(s[i]);
//		i++;
//	}
//	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)&(s[i]));
	return (NULL);
}
