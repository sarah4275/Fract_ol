/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:54:10 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/06 20:43:38 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	size;

	src_size = ft_size(src);
	dst_size = ft_size(dst);
	if (dst_size >= siz)
		return (siz + src_size);
	size = siz - dst_size - 1;
	if (size > src_size)
		size = src_size;
	ft_memcpy(dst + dst_size, src, size);
	dst[dst_size + size] = 0;
	return (dst_size + src_size);
}
/*
int	main(void){
	char	dest[3] = "go";
	char	src[6] = "Hello";
	printf("%ld", ft_strlcat (dest, src, 4));
}*/
