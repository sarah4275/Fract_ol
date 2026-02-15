/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:03:17 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/06 21:45:13 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		len;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((long)nmemb * (long)size > (long)INT_MAX)
		return (NULL);
	len = nmemb * size;
	ptr = (void *)malloc(len);
	if (!ptr)
		return (NULL);
	if (ptr != NULL)
		ft_bzero(ptr, len);
	else
		return (NULL);
	return (ptr);
}

/*
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_NUMBER 10

int	main(void) {

	int i;
	int * pointer = (int *) calloc( INT_NUMBER, sizeof(int) );

	assert( pointer != NULL );


	for ( i=0; i<INT_NUMBER-1; i++ ) {
		pointer[i] = i;
	}

	for (i=0; i<INT_NUMBER; i++ ) {
		printf( "%d ", pointer[i] );
	}
	printf( "\n" );

	free( pointer );

	return (0);
}*/
