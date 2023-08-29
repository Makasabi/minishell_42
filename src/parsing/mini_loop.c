/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wan <wan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:20:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/08/29 23:33:27 by wan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expand.h"
#include "exec.h"

void	clean_hell(t_minishit *hell)
{
	if (hell->token)
		ft_clear_token(hell->token);
	if (hell->node)
		ft_clear_node(hell->node);
	if (hell->path)
		ft_free(hell->path);
}

void	clear_hell(t_minishit *hell)
{
	hell->pipes = 0;
	hell->path = NULL;
	hell->node = NULL;
	hell->token = NULL;
}

void	display_prompt(int hell)
{	
	(void)hell;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	mini_loop(t_minishit *hell)
{
	// int i;
	
	signal(SIGINT, display_prompt);
	signal(SIGQUIT, SIG_IGN);
	if (lexer(hell) == FALSE)
		return (FALSE);
	expander(hell, hell->token);
	if (parser(hell) == FALSE)
		return (FALSE);
	// while (hell->node)
	// {
	// 	i = 0;
	// 	while (hell->node->argv[i++])
	// 		printf("argv %s\n", hell->node->argv[i]);
	// 	hell->node = hell->node->up;
	// }
	while (hell->node && hell->node->up)
		hell->node = hell->node->up;
	if (hell->node)
		ft_exec(hell, &hell->node);
	clean_hell(hell);
	clear_hell(hell);
	return (TRUE);
}

/*

	// while (hell->node)
	// {
	// 	printf("type is %d index is %d\n", hell->node->type, hell->node->index);
	// 	hell->node = hell->node->next;
	// }
	check if built_in

*/



// int	check_dollar(char *str, int i)
// {
// 	if (ft_strlen(str) < 2)
// 		return (1);
// 	if (str[i] == '$' && str[i + 1] == '?')
// 		return (0);
// 	if (str[i] == '$' && ft_isalnum(str[i + 1]))
// 		return (0);
// 	return (1);
// }

// int	get_start(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i + 1] && check_dollar(str, i))
// 	{
// 		str++;
// 		i++;
// 	}
// 	return (i);
// }

// int	get_end(char *str)
// {
// 	int	n;

// 	n = 0;
// 	if (*str && *str == '?')
// 		return (1);
// 	while (*str && ft_isalnum(*str))
// 	{
// 		str++;
// 		n++;
// 	}
// 	return (n);
// }
