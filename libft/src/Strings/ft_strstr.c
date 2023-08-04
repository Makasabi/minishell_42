/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:08:45 by mrony             #+#    #+#             */
/*   Updated: 2023/05/11 12:57:33 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0' && big[i + j + 1] == '\0')
				return ((char *) big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
