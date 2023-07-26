/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:19:22 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 17:03:11 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

void	ft_test_cd(t_minishit *hell);
void	ft_test_export(t_minishit *hell);
void	ft_test_env(t_minishit *hell);
void	ft_test_pwd(t_minishit *hell);
void	ft_test_unset(t_minishit *hell);

void ft_builtin_test(t_minishit *hell)
{
	/***********/
	/* test cd */
	/***********/
	ft_test_cd(hell);
	ft_putchar_fd('\n', 1);

	/***************/
	/* test export */
	/***************/
	ft_test_export(hell);
	ft_putchar_fd('\n', 1);

	/************/
	/* test env */
	/************/
	ft_test_env(hell);
	ft_putchar_fd('\n', 1);

	/************/
	/* test pwd */
	/************/
	ft_test_pwd(hell);
	ft_putchar_fd('\n', 1);

	/**************/
	/* test unset */
	/**************/
	ft_test_unset(hell);
	ft_putchar_fd('\n', 1);

	/* test echo */
	/* test exit */
}

void	ft_test_unset(t_minishit *hell)
{
	t_builtin	args;

	args.fd_in = 0;
	args.fd_out = 1;
	args.fd_err = 2;
	args.cmd = "unset";
	args.opt = NULL;

	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : unset <<<\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "--> Unset variable: " _END, 2);
	ft_putstr_fd(_EMMERALD "NEW_VAR\n" _END, 2);
	args.arg = "NEW_VAR";
	ft_unset(hell, &args);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Unsetting non-set variable: " _END, 2);
	ft_putstr_fd(_EMMERALD "MARIE\n" _END, 2);
	args.arg = "MARIE";
	ft_unset(hell, &args);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Unset variable: " _END, 2);
	ft_putstr_fd(_EMMERALD "NEW_VAR_2\n" _END, 2);
	args.arg = "NEW_VAR_2";
	ft_unset(hell, &args);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Printing environment\n" _END, 2);
	ft_env(hell, &args);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Exporting environment\n" _END, 2);
	ft_export(hell, NULL);
}

void	ft_test_pwd(t_minishit *hell)
{
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : pwd <<<\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "--> Print current working directory\n" _END, 2);
	ft_pwd(hell, NULL);
}

void	ft_test_env(t_minishit *hell)
{
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : env <<<\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "--> Print all set env variable.\n" _END, 2);
	ft_putstr_fd(_CORAL "--> Variable 'NEW_VAR_2' should not be displayed as it is declared but not set.\n" _END, 2);
	ft_env(hell, NULL);
}

void	ft_test_cd(t_minishit *hell)
{
	t_builtin	args;

	args.fd_in = 0;
	args.fd_out = 1;
	args.fd_err = 2;
	args.cmd = "cd";
	args.opt = NULL;
	args.arg = "../../../";

	char buff[PATH_MAX];

	(void)args;
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : cd <<< \n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "--> printing environment BEFORE changing directory\n" _END, 2);
	ft_print_env(hell->my_env);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Current directory\n" _END, 2);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_EMMERALD "--> Changing directory\n" _END, 2);
	ft_putchar_fd('\n', 1);
	ft_cd(hell, &args);
	ft_putstr_fd(_FOREST_GREEN "--> New directory\n" _END, 2);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> printing environment AFTER changing directory\n" _END, 2);
	ft_print_env(hell->my_env);
}

void	ft_test_export(t_minishit *hell)
{
	t_builtin	args;

	args.fd_in = 0;
	args.fd_out = 1;
	args.fd_err = 2;
	args.cmd = "export";
	args.opt = NULL;
	args.arg = "NEW_VAR=this_is_a_new_var";

	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : export <<<\n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "--> Exporting:" _END, 2);
	ft_putstr_fd(_EMMERALD " NEW-VAR=this_is_a_new_var\n" _END, 2);
	ft_export(hell, &args);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Exporting:" _END, 2);
	ft_putstr_fd(_EMMERALD " NEW-VAR_2\n" _END, 2);
	args.arg = "NEW_VAR_2";
	ft_export(hell, &args);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Executing export cmd with no arg\n" _END, 2);
	ft_export(hell, NULL);
}
