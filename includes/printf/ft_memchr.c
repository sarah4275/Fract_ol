/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:55:40 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/02 18:36:29 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		s;

	i = 0;
	p = (const unsigned char *)str;
	s = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == s)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void) {

	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	const unsigned int size = 10;

	// On recherche une valeur inhéxistante :
	void * found = ft_memchr( data, 57, size );
	printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );

	// On recherche une valeur existante :
	found = ft_memchr( data, 50, size );
	printf( "50 is %s\n", ( found != NULL ? "found" : "not found" ) );
	if ( found != NULL ) {
		printf( "La valeur à la position calculée est %d\n",
			*((char *) found) );
	}

}*/
