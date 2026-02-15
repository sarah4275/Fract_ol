/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:07:32 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/02 19:24:55 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	char		*bptr;
	char		*lptr;

	if (!*little)
		return ((char *)big);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			i = len;
			bptr = (char *)big + 1;
			lptr = (char *)little + 1;
			while (i-- && *bptr && *lptr && *lptr == *bptr)
			{
				++lptr;
				++bptr;
			}
			if (*lptr == '\0')
				return ((char *)big);
		}
		++big;
	}
	return (NULL);
}

/*char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] && *little && big[i + j] == *little)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}

#include <stdio.h>


int	main(void)
{
	const char *big = "Hello world, this is a test";
	const char *little = "world";
	size_t len = 15;

	char *res = ft_strnstr(big, little, len);
	if (res != NULL)
		printf("Found '%s' in '%s' within first %zu chars at position: %ld\n",
			little, big, len, res - big);
	else
		printf("'%s' not found in first %zu chars of '%s'\n", little, len, big);

	return (0);
}*/
