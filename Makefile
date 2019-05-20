# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 15:05:52 by akeiflin          #+#    #+#              #
#    Updated: 2019/05/20 15:05:53 by akeiflin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

# Sources
SRC				=	srcs/builtin.c srcs/control.c srcs/env_func.c \
					srcs/error.c srcs/ft_addpath.c srcs/ft_alias.c \
					srcs/ft_cd.c srcs/ft_echo.c srcs/ft_env.c \
					srcs/ft_setenv.c srcs/ft_take.c srcs/ft_unsetenv.c \
					srcs/minishell.c srcs/misc.c srcs/parse_cmd.c \
					srcs/read_cmd.c srcs/splitargs.c srcs/free.c \
					srcs/ft_builtin.c

LIBFT_FOLDER	=	libft
LIB_FOLDERS		=	-L$(LIBFT_FOLDER)
LIBS			=	-lft
# Compilation
CXX				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -O3
INCLUDES		=	-I includes -I $(LIBFT_FOLDER)/includes

# Linking
OBJ				=	$(SRC:.c=.o)

# Colors
GREEN			=	\033[32m
RESET			=	\033[0m

all: libft $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)[cc]$(RESET): done\n"
	@printf "$(GREEN)[ld]$(RESET): $(NAME)\n"
	@$(CXX) -o $(NAME) $(OBJ) $(LIB_FOLDERS) $(LIBS) $(LDFLAGS) $(INCLUDES)

.c.o: $(SRC)
	@printf "$(GREEN)[cc]$(RESET): $< -> $@\n"
	@printf "\e[1A"
	@gcc -c $< -o $@ $(INCLUDES) $(CFLAGS)
	@printf "\e[0K"

run: all
	@./$(NAME)

libft:
	@printf "$(GREEN)[mk]$(RESET): libft all\n";
	@make -C libft
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft all done\n";

libft-clean:
	@printf "$(GREEN)[mk]$(RESET): libft clean\n";
	@make -C $(LIBFT_FOLDER) clean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft clean done\n";

libft-fclean:
	@printf "$(GREEN)[mk]$(RESET): libft fclean\n";
	@make -C $(LIBFT_FOLDER) fclean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft fclean done\n";

libft-re:
	@printf "$(GREEN)[mk]$(RESET): libft re\n";
	@make -C $(LIBFT_FOLDER) re
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft re done\n";

clean: libft-clean
	@printf "$(GREEN)[rm]$(RESET): cleaned object files\n"
	@rm -rf $(OBJ)

fclean: clean libft-fclean
	@printf "$(GREEN)[rm]$(RESET): cleaned binary file\n"
	@rm -rf $(NAME)

re: fclean libft all

.PHONY: all libft libft-clean libft-fclean libft-re clean fclean re
