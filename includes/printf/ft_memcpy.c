/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:41:15 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/02 18:15:55 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d == (void *)0 && s == (void *)0)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*int main()
{

	int array [] = { 54, 85, 20, 63, 21 };
	int dest[100];
	size_t size = sizeof( int ) * 5;
	int length;

	ft_memcpy( dest, array, size );

	for( length=0; length<5; length++) {
		printf( "%d ", dest[ length ] );
	}
	printf( "the c fonction: \n" );


	memcpy( dest, array, size );


	for( length=0; length<5; length++) {
		printf( "%d ", dest[ length ] );
	}
	printf( "\n" );

	return (0);
}*/
