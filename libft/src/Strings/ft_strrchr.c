/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:37:32 by mrony             #+#    #+#             */
/*   Updated: 2022/11/14 17:07:51 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int		slen;
	unsigned char		d;
	char				*str;

	str = (char *) s;
	d = (unsigned char) c;
	slen = ft_strlen(str);
	while (slen > 0 && str[slen] != d)
		slen--;
	if (slen == 0 && str[slen] != d)
		return (NULL);
	return (str + slen);
}
