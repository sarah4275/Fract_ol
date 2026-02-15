/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:17:59 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/02 19:58:25 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (!s && !d)
		return (NULL);
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*int main() {

	// On crée une zone de mémoire de 10 entiers et contenant
	// que neuf valeurs. La dixième est non utilisée (0).
	int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

	// On affiche le contenu de la collection
	for( int i=0; i<10; i++ ) {
		printf( "%d ", data[i] );
	}
	puts( "" );  // Un retour à la ligne

	// On décale les éléménts dans la collection ...
	void * source = (void *) data;
	void * destination = (void *) ( data + 1 );
	size_t size = 10 * sizeof( int );
	ft_memmove( destination, source, size );

	// ... pour y insérer une nouvelle valeur en tête
	data[0] = 10;

	// On affiche le contenu de la collection
	for( int i=0; i<10; i++ ) {
		printf( "%d ", data[i] );
	}
	puts( "" );  // Un retour à la ligne

	return (EXIT_SUCCESS);
   }
int	main(void)
{
	char csrc[100] = "Geeksfor";
	ft_memcpy(csrc + 5, csrc, strlen(csrc) + 1);
	printf("%s", csrc);
	return (0);
}*/
