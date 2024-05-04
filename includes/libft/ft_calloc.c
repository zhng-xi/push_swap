/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:12:42 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/04 21:20:55 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return (p);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	int *array = (int *)ft_calloc(10, sizeof(int));

	if (array == NULL)
	{
    	printf("Failed to allocate memory.\n");
    	return 1;
	}
	// Print the value of the first element in the array.
  	printf("%d\n", array[0]);

	// Free the allocated memory.
 	free(array);
	return 0;
}

Line 23 to 27 --> allocate memory
Line 28 to 34 --> Check for overflow
*/
