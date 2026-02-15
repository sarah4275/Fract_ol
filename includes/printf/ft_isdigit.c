/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:58:19 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/06 21:19:07 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int number)
{
	if (number >= '0' && number <= '9')
		return (2048);
	else
		return (0);
}
/*
int main ()
{
	printf("%d", ft_isdigit('2'));
	return (0);
}*/
