/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:56:16 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/15 18:08:59 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_issep(char str, char c)
{
	return (str == c);
}

static int	ft_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], c))
			i++;
		if (str[i] && !ft_issep(str[i], c))
		{
			count++;
			while (str[i] && !ft_issep(str[i], c))
				i++;
		}
	}
	return (count);
}

static char	*ft_makestr(char *s, char c)
{
	char	*str;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (s[nb] && !ft_issep(s[nb], c))
		nb++;
	str = malloc (sizeof(char) * (nb + 1));
	if (!str)
		return (NULL);
	while (i < nb)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	int		j;
	int		count;

	count = ft_count(s, c);
	j = -1;
	split = malloc (sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	while (++j < count)
	{
		while (*s && ft_issep(*s, c))
			s++;
		split[j] = ft_makestr(s, c);
		if (!split[j])
		{
			ft_free(split);
			return (NULL);
		}
		while (*s && !ft_issep(*s, c))
			s++;
	}
	split[j] = NULL;
	return (split);
}

char	**extract_path(char *str, char **path)
{
	char	*temp;
	int		i;

	temp = malloc(sizeof(char) * ft_strlen(str) - 4);
	if (!temp)
		return (0);
	i = -1;
	while (str[++i + 5])
		temp[i] = str[i + 5];
	temp[i] = '\0';
	path = ft_split(temp, ':');
	if (!path)
		return (0);
	free(temp);
	return (path);
}

void	check_envp(char **envp)
{
	int		i;
	char	**path;

	i = -1;
	while (envp[++i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
			path = extract_path(envp[i], path);
	}
	i = -1;
	while (path[++i])
		printf("%s\n", path[i]);
	ft_free(path);
}


int	main(int argc, char **argv, char **envp)
{
	check_envp(envp);
	return (0);
}
