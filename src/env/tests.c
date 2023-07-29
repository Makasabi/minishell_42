/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:11:50 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 16:24:54 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void ft_env_test(char ***my_env)
{
	ft_putstr_fd(_REV _FOREST_GREEN "TEST : print_env\n" _END, 2);
	ft_print_env((*my_env));

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_find_var\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "Looking for var 'NULL'\n" _END, 2);
	ft_find_var((*my_env), NULL);
	ft_putstr_fd(_FOREST_GREEN "Looking for var 'PWD'\n" _END, 2);
	printf("%s\n", ft_find_var((*my_env), "PWD"));
	ft_putstr_fd(_FOREST_GREEN "Looking for var 'MARIE'\n" _END, 2);
	ft_find_var((*my_env), "MARIE");

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_var_value\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "Looking for var 'NULL'\n" _END, 2);
	ft_var_value((*my_env), NULL);
	ft_putstr_fd(_FOREST_GREEN "Looking for var 'PWD'\n" _END, 2);
	printf("%s\n", ft_var_value((*my_env), "PWD"));
	ft_putstr_fd(_FOREST_GREEN "Looking for var 'MARIE'\n" _END, 2);
	ft_var_value((*my_env), "MARIE");

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_add_var\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "Adding var 'MARIE'\n" _END, 2);
	ft_add_var(my_env, "MARIE=Marie,Charlote,Sabine,Rony");
	ft_print_env((*my_env));

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_del_var\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "Removing var 'MARIE'\n" _END, 2);
	ft_del_var(my_env, ft_var_line((*my_env), "MARIE"));
	ft_print_env((*my_env));

	ft_putstr_fd(_REV _FOREST_GREEN "TEST : ft_replace_var\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "Replacing value of SHLVL=2 to =3\n" _END, 2);
	ft_replace_var(my_env, "SHLVL=3");
	ft_print_env((*my_env));
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