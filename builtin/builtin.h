#ifndef BUILTIN_H
# define BUILTIN_H

char	*ft_cd(char *str);
void	ft_echo(char *str, int offset);
void	ft_env(char **env);
void	ft_exit(int status);
char	**ft_export(char *str, char **env);
int	ft_pwd(void);
int	ft_unset(char *str, char **env);

#endif
