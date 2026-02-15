/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:55:46 by sameddah          #+#    #+#             */
/*   Updated: 2025/11/15 15:02:28 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		(c -= 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( (*dest++ = ft_toupper( *src++ )) );
    return result;
}
int main() {

    char * input = "Diego De La Vega";
    char result[17];

    printf( "Result: %s\n", strtoupper( result, input ) );

    return EXIT_SUCCESS;
}*/
