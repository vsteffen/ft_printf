# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/27 18:57:15 by vsteffen          #+#    #+#              #
#    Updated: 2016/10/27 18:57:37 by vsteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC =	/usr/bin/clang
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir
AR =	/usr/bin/ar
RANLIB = /usr/bin/ranlib

LIBS = $(ROOT)/lib/libft.a
			# -ltermcap

SRC = ft_printf.c \
			arg_list.c

OBJ = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror -g

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/include

showStartRule=\t\033[31m\033[4m\033[1m → Starting \"make $(MAKECMDGOALS)\" rule\033[0m
showEndRule=\t\033[31m\033[4m\033[1mEnd of \"make $(MAKECMDGOALS)\" rule\033[0m


.PHONY: all clean fclean re

all: $(OPATH) pre-check libft-make $(NAME)

pre-check:
	@-mkdir lib
	@git submodule init
	@git submodule update
	@echo "$(HPATH) for HEADER"

libclean: fclean
	@echo "$(showStartRule) for libraries"
	@$(MAKE) -C miniLibX clean
	@$(MAKE) -C libft fclean
	@echo "\033[32mPersonal libraries clean.\033[0m"
	@echo "$(showEndRule) for libraries"

libft-make:
	@echo "$(showStartRule) for libft"
	@$(MAKE) -C libft
	@cp libft/include/libft.h libft/include/color_style.h include
	@cp libft/libft.a lib
	@echo "Header and library compiled of libft copied to folder \"include\" and \"lib\" respectively"
	@echo "$(showEndRule) for libft"

libft-clean:
	@echo "$(showStartRule) for libft"
	@$(MAKE) -C libft clean
	@echo "$(showEndRule) for libft"

libft-fclean:
	@echo "$(showStartRule) for libft"
	@$(MAKE) -C libft fclean
	@echo "$(showEndRule) for libft"

libft-re:
	@echo "$(showStartRule) for libft"
	@$(MAKE) -C libft re
	@echo "$(showEndRule) for libft"

# prepFold:
# 	@$(MKDIR) lib

$(NAME): $(OBJ)
	@echo " \033[33m\033[4m\033[1m → Make rule \033[0m"
	@echo "Creating OBJ files if they do not exist or have changed"
	@echo "Building $@"
	@$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBS) -I $(HPATH)
	@echo "\033[32m ╔════════════════╗"
	@echo " ║  All is done ! ║"
	@echo " ╚════════════════╝\033[0m"

$(OPATH)/%.o: $(CPATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HPATH)

$(OPATH):
	@echo " \033[33m\033[4m\033[1m → Pre Make rule \033[0m"
	@echo "Creating "objs" directory."
	$(MKDIR) $@
	@echo "\033[32mOBJS directory created.\033[0m\n"

clean:
	@echo " \033[33m\033[4m\033[1m → Clean rule \033[0m"
	@echo "Deleting OBJS."
	$(RM) -Rf $(OPATH)
	@echo "\033[32mOBJS deleted.\033[0m\n"

fclean: clean
	@echo " \033[33m\033[4m\033[1m → Fclean rule \033[0m"
	@echo "Deleting $(NAME)."
	$(RM) -f $(NAME)
	@echo "\033[32m$(NAME) deleted.\033[0m\n"
	@echo "Deleting lib content."
	$(RM) -f $(LIBS)
	@echo "\033[32mLib content deleted.\033[0m\n"

re: fclean all
