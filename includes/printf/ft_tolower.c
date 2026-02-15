/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:02:52 by sameddah          #+#    #+#             */
/*   Updated: 2025/11/15 15:08:15 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		(c += 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strtollower( char * dest, const char * src ) {
    char * result = dest;
    while( (*dest++ = ft_tolower( *src++ )) );
    return result;
}
int main() {

    char * input = "DiEGO DE LA VEGa";
    char result[17];

    printf( "Result: %s\n", strtollower( result, input ) );

    return EXIT_SUCCESS;
}*/
