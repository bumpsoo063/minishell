#ifndef CONST_H
# define PARSE_ERROR "parse error\n"
# define PROM "minishell $ "
# define CONST_H
# define INPUT "<"
# define D_INPUT "<<"
# define OUTPUT ">"
# define D_OUTPUT ">>"
# define PIPE "|"

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
