/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:56:16 by tgibier           #+#    #+#             */
/*   Updated: 2023/07/16 15:51:55 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
# include <unistd.h>



# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif


typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;


t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_magic(t_list **save, char *temp, int nb)
{
	t_list	*new;
	t_list	*last_node;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc (sizeof(char) * (nb + 1));
	if (!new->content)
		return ;
	i = 0;
	while (temp[i] && i < nb)
	{
		new->content[i] = temp[i];
		i++;
	}
	new->content[i] = '\0';
	if (*save == NULL)
	{
		*save = new;
		return ;
	}
	last_node = ft_lstlast(*save);
	last_node->next = new;
}

int	ft_next_nl(t_list *save)
{
	int	i;
	int	len;

	len = 0;
	while (save)
	{
		i = 0;
		while (save->content[i])
		{
			if (save->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		save = save->next;
	}
	return (len);
}

int	ft_new_line(t_list *save)
{
	int		i;
	t_list	*last;

	if (!save)
		return (0);
	last = ft_lstlast(save);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_clear(t_list *save)
{
	t_list	*temp;
	t_list	*next;

	temp = save;
	while (temp)
	{
		free(temp->content);
		next = temp->next;
		free(temp);
		temp = next;
	}
}

t_list	*ft_clean_save(t_list *save)
{
	t_list	*clean;
	t_list	*last;
	int		i;
	int		j;

	last = ft_lstlast(save);
	i = ft_next_nl(last);
	clean = malloc (sizeof(t_list));
	if (!clean)
		return (NULL);
	clean->next = NULL;
	clean->content = malloc (sizeof(char) * ((BUFFER_SIZE - i) + 1));
	if (!clean->content)
		return (NULL);
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	ft_clear(save);
	return (clean);
}

char	*ft_get_line(t_list *save, char *line)
{
	int	i;
	int	j;
	int	size;

	size = ft_next_nl(save);
	line = malloc (sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (save)
	{
		i = 0;
		while (save->content[i])
		{
			if (save->content[i] == '\n')
			{
				line[j++] = save->content[i];
				break ;
			}
			line[j++] = save->content[i++];
		}
		save = save->next;
	}
	line[j] = '\0';
	return (line);
}

void	ft_read(int fd, t_list **save)
{
	int		nb;
	char	*temp;

	nb = 1;
	while (nb != 0 && !ft_new_line(*save))
	{
		temp = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return ;
		nb = (int)read(fd, temp, BUFFER_SIZE);
		if (nb == -1 || ((*save) == NULL && nb == 0))
		{
			free(temp);
			break ;
		}
		temp[nb] = '\0';
		ft_magic(save, temp, nb);
		free(temp);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*save = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &save);
	if (!save)
		return (NULL);
	line = ft_get_line(save, line);
	save = ft_clean_save(save);
	if (line[0] == '\0')
	{
		ft_clear(save);
		free(line);
		return (NULL);
	}
	return (line);
}


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
	char *str;
	
	check_envp(envp);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (str)
			printf("STRING IS %s\n", str);
		else
			return (0);
	}
	return (0);
}
