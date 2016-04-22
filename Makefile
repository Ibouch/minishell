# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#              #
#    Updated: 2016/04/19 20:31:33 by ibouchla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INC_PATH = -I includes

SRC_PATH = srcs

SRC_NAME =	builtin_help.c \
			builtin_cd.c \
			builtin_setenv.c \
			builtin_getenv.c \
			builtin_unsetenv.c \
			builtin_exit.c \
			main.c \
			storage_env.c \
			auto_shlvl.c \
			run_shell.c \
			env_addback.c \
			storage_all_cmds.c \
			determine_builtins.c \
			determine_prefixe.c \
			search_env_element.c \
			remove_var_env.c \
			storage_elem.c \
			print_setenv_usage.c \
			update_var_environment.c \
			create_update_cmd.c \
			list_to_tab.c \
			print_environment.c \
			exec_bin.c \
			get_value.c \
			print_unknown_cmd.c \
			get_home_directory.c \
			check_old_dir.c \
			isolate_name.c \
			storage_new_env.c

CC_FLAGS = clang -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJET = $(SRC:.c=.o)

LD_PATH = -L libft

LD_LIB = -lft

RED = \033[1;31m

BLUE = \033[1;34m

GREEN = \033[0;32m

YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJET)
	@echo "$(BLUE)Compilation of object files in project directory is complete.\n"
	@echo "$(YELLOW)Recompilation of the library in progress.."
	@make -C libft/ re > /dev/null
	@echo "$(BLUE)Compilation of the library is complete.\n"
	@echo "$(YELLOW)Linkage of object files with the library is in progress.."
	@$(CC_FLAGS) $(OBJET) $(LD_PATH) $(LD_LIB) -o $(NAME)
	@echo "$(BLUE)Linkage is complete."
	@make -C libft/ fclean
	@echo "$(GREEN)Done."

%.o: %.c
	@$(CC_FLAGS) -c $< $(INC_PATH) -o $@
	@echo "\033[1;32mCompilation of object file from the project source file : $(GREEN)Success"
clean:
	@echo "\n$(RED)Deleting object files of the project"
	@$(RM) $(OBJET)

fclean: clean
	@echo "$(RED)Remove the executable\n"
	@$(RM) $(NAME)

re: fclean all
