#include "env.h"

/* This function is used to secure the environments mallocs
It should be edited in the future when we integrate the parsing and execution*/
#define ENVAIN "Environment variable initialization"

void	ft_env_error(char **my_env, int stage)
{
	if (!my_env)
		ft_error_msg(SHELL, "Environment initialization", NULL, MALERR);
	if (stage == 1)
	{
		ft_free(my_env);
		ft_error_msg(SHELL, ENVAIN, NULL, ENVERR1);
	}
	if (stage == 2)
	{
		ft_free(my_env);
		ft_error_msg(SHELL, ENVAIN, NULL, ENVERR2);
	}
}
