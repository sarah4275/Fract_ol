/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:25:02 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/03 18:58:27 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char ** argv)
{
  int  len;
  int  result;

  if ( argc != 3 )
  {
		printf( "Usage: %s string1 string2\n", argv[0] );
  }
  else
  {
		if (strlen( argv[1] ) < strlen( argv[2] ))
		len = strlen( argv[1] );
		else
		len = strlen( argv[2] );

		result = ft_memcmp( argv[1], argv[2], len );

		printf( "When the first %i characters are compared,\n", len );
		if ( result == 0 )
		printf( "\"%s\" is identical to \"%s\"\n", argv[1], argv[2] );
		else if ( result < 0 )
		printf( "\"%s\" is less than \"%s\"\n", argv[1], argv[2] );
		else
		printf( "\"%s\" is greater than \"%s\"\n", argv[1], argv[2] );
   }
}*/
