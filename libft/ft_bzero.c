/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:48:21 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/03/31 16:47:34 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "Hello, world!";

	printf("Avant ft_bzero : %s\n", str);
	ft_bzero(str, 5);                     // Mettre à 0 les 5 premiers octets
	printf("Après ft_bzero : %s\n", str); // La chaîne semblera coupée
	return (0);
}
*/
