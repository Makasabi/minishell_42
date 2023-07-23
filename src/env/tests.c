/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:11:50 by mrony             #+#    #+#             */
/*   Updated: 2023/07/23 15:31:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void ft_env_test(char **my_env)
{
	ft_putstr_fd(_REV _FOREST_GREEN "TEST : print_env\n" _END, 2);
	ft_print_env(my_env);

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_find_var\n" _END, 2);
	ft_find_var(my_env, NULL);
	printf("%s\n", ft_find_var(my_env, "PWD"));
	ft_find_var(my_env, "MARIE");

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_var_value\n" _END, 2);
	ft_var_value(my_env, NULL);
	printf("%s\n", ft_var_value(my_env, "PWD"));
	ft_var_value(my_env, "MARIE");

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_add_var\n" _END, 2);

}

void ft_print_env(char **my_env)
{
	int	i;

	i = 0;
	if(!my_env)
		return ;
	while(my_env[i])
	{
		printf("%s\n", my_env[i]);
		i++;
	}
}