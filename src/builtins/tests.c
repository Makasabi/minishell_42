/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:19:22 by mrony             #+#    #+#             */
/*   Updated: 2023/07/31 18:39:16 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

void	ft_test_cd(t_minishit *hell);
void	ft_test_export(t_minishit *hell);
// void	ft_test_env(t_minishit *hell);
// void	ft_test_pwd(t_minishit *hell);
// void	ft_test_unset(t_minishit *hell);
// void	ft_test_echo(t_minishit *hell);

void ft_builtin_test(t_minishit *hell)
{
	/***********/
	/* test cd */
	/***********/
	//ft_test_cd(hell);
	//ft_putchar_fd('\n', 1);

	// /***************/
	// /* test export */
	// /***************/
	ft_test_export(hell);
	ft_putchar_fd('\n', 1);

	// /************/
	// /* test env */
	// /************/
	// ft_test_env(hell);
	// ft_putchar_fd('\n', 1);

	// /************/
	// /* test pwd */
	// /************/
	// ft_test_pwd(hell);
	// ft_putchar_fd('\n', 1);

	// /**************/
	// /* test unset */
	// /**************/
	// ft_test_unset(hell);
	// ft_putchar_fd('\n', 1);

	// /*************/
	// /* test echo */
	// /*************/
	// ft_test_echo(hell);
	// ft_putchar_fd('\n', 1);

	/* test exit */
}

// void	ft_test_echo(t_minishit *hell)
// {
// 	t_builtin	args;

// 	args.fd_in = 0;
// 	args.fd_out = 1;
// 	args.fd_err = 2;
// 	args.cmd = "echo";
// 	args.opt = "-n";
// 	args.arg = "This should be printed without newline.";
// 	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : echo <<<\n" _END, 2);
// 	ft_putstr_fd(_FOREST_GREEN "--> echo -n test: " _END, 2);
// 	ft_echo(hell, &args);
// 	args.arg = "On the other hand, this should have a newline.";
// 	ft_putstr_fd(_FOREST_GREEN "--> echo test: " _END, 2);
// 	ft_echo(hell, &args);
// 	ft_putchar_fd('\n', 1);
// }

// void	ft_test_unset(t_minishit *hell)
// {
// 	char *argv[3];

// 	argv[0] = "unset";
// 	argv[1] = "NEW_VAR";
// 	argv[2] = NULL;
	
// 	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : unset <<<\n" _END, 2);
// 	ft_putstr_fd(_FOREST_GREEN "--> Unset variable: " _END, 2);
// 	ft_putstr_fd(_EMMERALD "NEW_VAR\n" _END, 2);
// 	ft_unset(hell, argv);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(_FOREST_GREEN "--> Unsetting non-set variable: " _END, 2);
// 	ft_putstr_fd(_EMMERALD "MARIE\n" _END, 2);
// 	argv[1] = "MARIE";
// 	ft_unset(hell, argv);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(_FOREST_GREEN "--> Unset variable: " _END, 2);
// 	ft_putstr_fd(_EMMERALD "NEW_VAR_2\n" _END, 2);
// 	argv[1] = "NEW_VAR_2";
// 	ft_unset(hell, argv);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(_FOREST_GREEN "--> Printing environment\n" _END, 2);
// 	ft_env(hell, argv);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(_FOREST_GREEN "--> Exporting environment\n" _END, 2);
// 	ft_export(hell, NULL);
// }

// void	ft_test_pwd(t_minishit *hell)
// {
// 	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : pwd <<<\n" _END, 2);
// 	ft_putstr_fd(_FOREST_GREEN "--> Print current working directory\n" _END, 2);
// 	ft_pwd(hell, NULL);
// }

// void	ft_test_env(t_minishit *hell)
// {
// 	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : env <<<\n" _END, 2);
// 	ft_putstr_fd(_FOREST_GREEN "--> Print all set env variable.\n" _END, 2);
// 	ft_putstr_fd(_CORAL "--> Variable 'NEW_VAR_2' should not be displayed as it is declared but not set.\n" _END, 2);
// 	ft_env(hell, NULL);
// }

void	ft_test_cd(t_minishit *hell)
{
	char *argv[3];
	char buff[PATH_MAX];

	argv[0] = "cd";
	argv[1] = "-";
	argv[2] = NULL;
	
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : cd <<< \n" _END, 2);
	ft_putstr_fd(_FOREST_GREEN "--> printing environment BEFORE changing directory\n" _END, 2);
	ft_print_env(hell->my_env);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Current directory\n" _END, 2);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_EMMERALD "--> Changing directory\n" _END, 2);
	/* -------------> CD function here */
	ft_cd(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> New directory\n" _END, 2);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> printing environment AFTER changing directory\n" _END, 2);
	ft_print_env(hell->my_env);
}

void	ft_test_export(t_minishit *hell)
{
	char *argv[5];

	argv[0] = "export";
	argv[1] = "NEW_VAR=this_is_a_new_var";
	argv[2] = "NEW_VAR_2=blah";
	argv[3] = "NEW_VAR+=blah";
	argv[4] = NULL;

	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : export <<<\n" _END, 2);
	//ft_putstr_fd(_FOREST_GREEN "--> Exporting: " _END, 2);
	//ft_putstr_fd(_EMMERALD "NEW_VAR=this_is_a_new_var\n" _END, 2);
	ft_export(hell, argv);
	ft_putchar_fd('\n', 1);
	// ft_putstr_fd(_FOREST_GREEN "--> Exporting: " _END, 2);
	// ft_putstr_fd(_EMMERALD "NEW_VAR_2\n" _END, 2);
	// argv[1] = "NEW_VAR_2";
	// ft_export(hell, argv);
	// ft_putchar_fd('\n', 1);
	// ft_putstr_fd(_FOREST_GREEN "--> Appending: " _END, 2);
	// ft_putstr_fd(_EMMERALD "NEW_VAR+=_blah_blah\n" _END, 2);
	// argv[1] = "NEW_VAR+=_blah_blah";
	// ft_export(hell, argv);
	// ft_putchar_fd('\n', 1);
	// ft_putstr_fd(_FOREST_GREEN "--> Executing export cmd with no arg\n" _END, 2);
	ft_export(hell, NULL);
}
