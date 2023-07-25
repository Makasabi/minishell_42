/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:19:22 by mrony             #+#    #+#             */
/*   Updated: 2023/07/25 23:38:53 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

void	ft_test_cd(char ***my_env)
{
	t_builtin	args;

	args.fd_in = 0;
	args.fd_out = 1;
	args.fd_err = 2;
	args.cmd = "cd";
	args.opt = NULL;
	args.arg = "~";

	char buff[PATH_MAX];

	(void)args;
	ft_print_env(*my_env);
	ft_putchar_fd('\n', 1);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
	ft_cd(my_env, &args);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
}

void ft_builtin_test(char ***my_env)
{
	ft_test_cd(my_env);
	ft_putchar_fd('\n', 1);
	ft_add_var(my_env, "MARIE");
	ft_env(my_env, NULL);
	ft_putchar_fd('\n', 1);
	ft_pwd(my_env, NULL);
	ft_putchar_fd('\n', 1);
	ft_export(my_env, NULL);
}