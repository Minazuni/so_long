/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ko-mahon <ko-mahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:37:14 by ko-mahon          #+#    #+#             */
/*   Updated: 2025/04/10 10:18:42 by ko-mahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}

// int main() {
//     int *arr;
//     size_t i, n = 5;

//     arr = (int *)ft_calloc(n, sizeof(int));
//     if (!arr) {
//         printf("Allocation échouée\n");
//         return (1);
//     }

//     printf("Tableau après allocation :\n");
//     for (i = 0; i < n; i++)
//         printf("arr[%zu] = %d\n", i, arr[i]); // Doit afficher que des 0

//     free(arr);
//     return (0);
// }