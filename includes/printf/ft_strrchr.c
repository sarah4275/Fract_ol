/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:45:48 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/06 20:30:31 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s)
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (res);
}
/*
#define SIZE 40

int	main(void)
{
  char buffer1[SIZE] = "computer program";
	int	ch;

  char * ptr;
  ch = 'p';
  ptr = ft_strrchr( buffer1, ch );
  printf( "The first occurrence of %c in '%s' is '%s'\n",
			ch, buffer1, ptr );
}*/
