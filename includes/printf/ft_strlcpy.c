/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:11:07 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/03 18:44:43 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	while (src[i] && siz > 0 && i < siz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < siz)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
