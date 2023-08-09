/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:19:22 by mrony             #+#    #+#             */
/*   Updated: 2023/08/09 12:06:18 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"

void	ft_test_cd(t_minishit *hell);
void	ft_test_export(t_minishit *hell);
void	ft_test_env(t_minishit *hell);
void	ft_test_pwd(t_minishit *hell);
void	ft_test_unset(t_minishit *hell);
void	ft_test_echo(t_minishit *hell);

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
	// ft_test_export(hell);
	// ft_putchar_fd('\n', 1);

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
	// ft_exit(hell);
}

void	ft_test_echo(t_minishit *hell)
{
	char *argv[4];
	argv[0]	= "echo";
	argv[1] = "-n";
	argv[2] = "This should be printed without newline.";
	argv[3] = NULL;
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : echo <<<\n" _END, 1);
	ft_putstr_fd(_FOREST_GREEN "--> echo -n test: " _END, 1);
	ft_echo(hell, argv);
	argv[1] = "-nnnnnnnnnnfnnnnnn";
	argv[2] = "On the other hand, this should have a newline.";
	ft_putstr_fd(_FOREST_GREEN "--> echo test: " _END, 1);
	ft_echo(hell, argv);
	ft_putchar_fd('\n', 1);
}

void	ft_test_unset(t_minishit *hell)
{
	char *argv[4];
	argv[0]	= "unset";
	argv[1] = "NE*W_VAR";
	argv[2] = "NEW_VAR_2";
	argv[3] = NULL;
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : unset <<<\n" _END, 1);
	ft_putstr_fd(_FOREST_GREEN "--> Unset variable: " _END, 1);
	ft_putstr_fd(_EMMERALD "-NEW_VAR & NEW_VAR_2\n" _END, 1);
	ft_unset(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Unsetting invalid variable name: " _END, 1);
	ft_putstr_fd(_EMMERALD "lNEW_VAR\n" _END, 1);
	argv[1] = "lNEW_VAR";
	argv[2] = NULL;
	ft_unset(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Unset variable: " _END, 1);
	ft_putstr_fd(_EMMERALD "NEW_VAR_3\n" _END, 1);
	argv[1] = "NEW_VAR_3";
	ft_unset(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Unset non-existent variable: " _END, 1);
	ft_putstr_fd(_EMMERALD "NEW_VAR_4\n" _END, 1);
	argv[1] = "NEW_VAR_4";
	ft_unset(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Printing environment\n" _END, 1);
	ft_env(hell, NULL);
	ft_putchar_fd('\n', 1);
	argv[1] = NULL;
	ft_putstr_fd(_FOREST_GREEN "--> Exporting environment\n" _END, 1);
	ft_export(hell, argv);
}

void	ft_test_pwd(t_minishit *hell)
{
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : pwd <<<\n" _END, 1);
	ft_putstr_fd(_FOREST_GREEN "--> Print current working directory\n" _END, 1);
	ft_pwd(hell, NULL);
}

void	ft_test_env(t_minishit *hell)
{
	char *argv[3];

	argv[0] = "env";
	argv[1] = "blah";
	argv[2] = NULL;
	
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : env <<<\n" _END, 1);
	ft_putstr_fd(_FOREST_GREEN "--> Print void env\n" _END, 1);
	ft_env(NULL, NULL);
	ft_putstr_fd(_FOREST_GREEN "--> Print env with args\n" _END, 1);
	ft_putstr_fd(_CORAL "--> Should not do anything as args and option are not managed heremake\n" _END, 1);

	ft_env(NULL, argv);
	argv[1] = NULL;
	ft_putstr_fd(_FOREST_GREEN "--> Print all set env variable\n" _END, 1);
	ft_putstr_fd(_CORAL "--> Variable 'NEW_VAR_3' should not be displayed as it is declared but not set.\n" _END, 1);
	ft_env(hell, argv);
}

void	ft_test_cd(t_minishit *hell)
{
	char *argv[3];
	char buff[PATH_MAX];

	argv[0] = "cd";
	argv[1] = "-";
	argv[2] = NULL;

	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : cd <<< \n" _END, 1);
	ft_putstr_fd(_FOREST_GREEN "--> printing environment BEFORE changing directory\n" _END, 1);
	ft_print_env(hell->my_env);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Current directory\n" _END, 1);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_EMMERALD "--> Changing directory\n" _END, 1);
	/* -------------> CD function here */
	ft_cd(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> New directory\n" _END, 1);
	getcwd(buff, sizeof(buff));
	printf("%s\n", buff);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> printing environment AFTER changing directory\n" _END, 1);
	ft_print_env(hell->my_env);
}

void	ft_test_export(t_minishit *hell)
{
	char *argv[3];

	argv[0] = "export";
	argv[1] = "NEW0_VAR=this_is_a_new_var";
	argv[2] = NULL;
	ft_putstr_fd(_REV _FOREST_GREEN ">>> TEST : export <<<\n" _END, 1);
	ft_putstr_fd(_FOREST_GREEN "--> Exporting: " _END, 1);
	ft_putstr_fd(_EMMERALD "NEW0_VAR=this_is_a_new_var\n" _END, 1);
	ft_export(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Exporting: " _END, 1);
	ft_putstr_fd(_EMMERALD "NEW_VAR=blah\n" _END, 1);
	argv[1] = "NEW_VAR=blah";
	ft_export(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Exporting: " _END, 1);
	ft_putstr_fd(_EMMERALD "NEW_VAR_2+=Thatsonefuckinglongvariablevalue-thismeansYoullhavetobeabletocheckitsvalueblah\n" _END, 1);
	argv[1] = "NEW_VAR_2+=Thatsonefuckinglongvariablevalue-thismeansYoullhavetobeabletocheckitsvalueblah";
	ft_export(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Exporting: " _END, 1);
	ft_putstr_fd(_EMMERALD "NEW_VAR_3\n" _END, 1);
	argv[1] = "NEW_VAR_3";
	ft_export(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Appending: " _END, 1);
	ft_putstr_fd(_EMMERALD "NEW_VAR+=_let'scheckifthisworkscorrectlythroughout\n" _END, 1);
	argv[1] = "NEW_VAR+=_let'scheckifthisworkscorrectlythroughout";
	ft_export(hell, argv);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(_FOREST_GREEN "--> Executing export cmd with no arg:\n" _END, 1);
	argv[1] = NULL;
	ft_export(hell, argv);
}
