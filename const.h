#ifndef CONST_H
# define CONST_H

// strings
# define PARSE_ERROR "parse error\n"
# define PROM "minishell $ "
# define HEREDOC "/tmp/.minishell_heredoc"

// redirections
# define INPUT "<"
# define D_INPUT "<<"
# define OUTPUT ">"
# define D_OUTPUT ">>"

// pipe
# define PIPE "|"

// builtin
# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"

// characters
enum	e_chars {
	Quote = 39,
	D_Quote = 34,
	Input = 60,
	Output = 62,
	Pipe = 124,
	Equal = 61,
	Space = 32,
	Dollar = 36,
	Brace_O = 123,
	Brace_C = 125,
};

#endif
