#include "../minishell.h"
#include "../libft/libft.h"


static char	*ft_word(char *str)
{
	char	*head;
	int	i;
	char	*ret;

	i = 0;
	++str;
	if (*str == 0)
		return (ft_strdup(""));
	if (*str == BRACE_O)
		str++;
	head = str;
	while (*str != 0 && ft_isalpha(*str))
	{
		str++;
		i++;
	}
	ret = ft_substr(head, 0, i);
	ft_check_error();
	return (ret);
}

char	*ft_substitue(char *str, t_info *info)
{
	char	*left;
	char	*mid;
	char	*right;
	char	*temp;

	temp = ft_strchr(str, DOLLAR);
	while (temp)
	{
		left = ft_substr(str, 0, temp - str - 1);
		mid = ft_search(ft_word(temp), info);
		temp = ft_strchr(str, DOLLAR);
	}
}
