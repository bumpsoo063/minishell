#include "ft_init_env.c"
#include "ft_export/ft_export.c"
#include "ft_unset/ft_unset.c"
#include "ft_env/ft_env.c"

int main(int argc, char **argv, char **env)
{
	char **ep;
	ep = ft_init_env(env);
	ft_env(ep);
	//ft_unset("MINISHELL", ep);
	ep = ft_export("MINISHELL=4", ep);
	ft_env(ep);
}
