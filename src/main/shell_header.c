/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:25:58 by mrony             #+#    #+#             */
/*   Updated: 2023/09/23 14:25:59 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

static char	*ft_chose_color(int j)
{
	char	*tab[6];

	tab[0] = _RED;
	tab[1] = _ORANGE;
	tab[2] = _GOLD;
	tab[3] = _FOREST_GREEN;
	tab[4] = _BLUE;
	tab[5] = _PURPLE;
	return (tab[j]);
}

static void	ft_print_header(int width)
{
	int		i;
	int		j;
	int		half_title;

	half_title = ft_strlen(HEAD_LINE) / 2;
	j = 0;
	write(1, "\n", 1);
	while (j < 6)
	{
		i = -1;
		while (++i < (width / 2 - half_title))
			printf("%s ", ft_chose_color(j));
		printf("%s%s%s", _BOLD, ft_chose_color(j), HEAD_LINE);
		while (++i <= (width - (int)strlen(HEAD_LINE)))
			printf(" ");
		printf("\n");
		j++;
		usleep(150000);
	}
	printf("%s\n", _END);
}

static void	ft_clear(t_minishit *hell)
{
	int		fd;
	char	*cmd[2];
	char	*path;

	path = "/usr/bin/clear";
	cmd[0] = "clear";
	cmd[1] = NULL;
	fd = fork();
	if (fd == 0)
		execve(path, cmd, hell->my_env);
	wait(NULL);
}

void	ft_header(t_minishit *hell)
{
	struct winsize	s_win;

	ft_clear(hell);
	ioctl(1, TIOCGWINSZ, &s_win);
	ft_print_header(s_win.ws_col);
}
