#ifndef BUILTIN_H
# define BUILTIN_H
# include "../minishell.h"

int	ft_cd(char *str, t_info *info);
int	ft_echo(char **str, int offset);
int	ft_env(char **env);
int	ft_exit(char **str);
int	ft_export(char **str, t_info *info);
void	ft_export_print(char **env, int size);
int	ft_pwd(void);
int	ft_unset(char **str, char **env);

#endif
