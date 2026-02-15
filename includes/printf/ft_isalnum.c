/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:37:23 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/01 11:32:06 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (8);
	else
		if (c >= '0' && c <= '9')
			return (8);
	return (0);
}
/*
int main()
{
	printf("%d", ft_isalnum('2'));
	printf("%d", ft_isalnum('0'));
	printf("%d", ft_isalnum('9'));
	printf("%s", "**********");
	printf("%d", ft_isalnum('a'));
	printf("%d", ft_isalnum('z'));
	printf("%d", ft_isalnum('G'));
	printf("%d", ft_isalnum('Z'));
	printf("%s","**********" );
	printf("%d", ft_isalnum('&'));
	printf("%d", ft_isalnum('\n'));
	return (0);
}*/
