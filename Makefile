# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 19:33:42 by bechoi            #+#    #+#              #
#    Updated: 2022/08/11 14:16:55 by bechoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=minishell
SRC=./main.c \
    ./ft_init/ft_init_env.c \
    ./ft_init/ft_init_re.c \
    ./ft_check_error.c \
    ./ft_export/ft_export.c \
    ./ft_parse/ft_parse.c \
    ./ft_parse/ft_search_env.c \
    ./ft_parse/ft_substitute.c \
    ./t_queue/t_q_str.c \
    ./t_queue/t_q_re.c

LIBFT=./libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT): 
	make -C libft

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
