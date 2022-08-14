#include "ft_sig.h"

void	ft_save_init(struct termios *org_term)
{
	tcgetattr(STDIN_FILENO, org_term);
}

void	ft_set_term(struct termios *new_term)
{
	tcgetattr(STDIN_FILENO, new_term);
	new_term->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, new_term);
}

void	ft_reset_term(struct termios *org_term)
{
	tcsetattr(STDIN_FILENO, TCSANOW, org_term);
}

int	is_whitespace(char *line)
{
	while (*line)
	{
		if (*line != 32 && !(*line >= 0 & *line <= 13))
			return(0);
		line++;
	}
	return (1);
}

void	ft_sigint(int signal)
{
	printf("\n");
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	ft_set_signal()
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
}

int	main(void)
{
	char		*line;
	struct termios	org_term;
	struct termios	new_term;

	ft_save_init(&org_term);
	ft_set_term(&new_term);
	ft_set_signal();
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			exit(-1);
		if (*line != '\0')
			add_history(line);
		if (*line != '\0' && !is_whitespace(line))
		{
			printf("%s\n", line);
		}
		free(line);
	}
	ft_reset_term(&org_term);
	return (0);
}
