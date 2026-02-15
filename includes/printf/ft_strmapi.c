/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:44:52 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/06 20:36:06 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	if (s == NULL)
		return (NULL);
	result = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*

char	to_upper_with_index(unsigned int i, char c)
{
	(void)i; // On n'utilise pas l'index ici, mais on pourrait !
	if (c >= 'a' && c <= 'z')
		return (c - 32); // transformation en majuscule
	return (c);
}

int	main(void)
{
	char	*str;
	char	*mapped;

	str = "hello world!";
	mapped = ft_strmapi(str, to_upper_with_index);
	if (!mapped)
	{
		printf("Erreur d'allocation.\n");
		return (1);
	}
	printf("Original : %s\n", str);
	printf("Modifié  : %s\n", mapped);
	free(mapped);
	return (0);
}
	*/
