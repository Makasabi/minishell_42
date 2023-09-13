/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:19 by mrony             #+#    #+#             */
/*   Updated: 2023/09/08 12:25:25 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	unsigned int	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	array = (unsigned char *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		array[i] = '\0';
		i++;
	}
	return ((void *)array);
}
