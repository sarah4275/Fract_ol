/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:28:09 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/06 20:35:13 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	dup = malloc(size + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int	main(void) {

	const char * original = "The original string.";

	// On duplique la chaîne de caractères initiale.
	char * copy = ft_strdup( original );

	// On passe chaque lettre en majuscule.
	char * ptr = copy;
	while( *ptr != '\0' ) {
		*ptr = toupper( *ptr );
		ptr++;
	}

	// On affiche la chaîne finale
	printf( "%s\n", copy );

	// Sans oublier de libérer l'espace mémoire au final.
	free( copy );

	return (EXIT_SUCCESS);
}*/
