# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    newMakefile                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:52:05 by vsteffen          #+#    #+#              #
#    Updated: 2016/11/22 16:08:34 by vsteffen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# gcc main.c libftprintf.a -I includes -o ft_printf

CC =	/usr/bin/clang
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir
AR =	/usr/bin/ar
RANLIB = /usr/bin/ranlib

OBJ = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror -g

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/includes
PRINTF =	/ft_printf

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstpcontent.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstiter.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_clear.c \
		ft_color_style.c \
		get_next_line.c \
		ft_exit_prog.c \
		ft_rounded.c \
		ft_swap_str.c \
		ft_swap_char.c \
		ft_swap_int.c \
		ft_qsort_tab_int.c \
		ft_qsortr_tab_int.c \
		ft_qsort_tab_str.c \
		ft_qsortr_tab_str.c \
		ft_superstr.c \
		ft_itoa_base.c\
		ft_strjoinaf1.c \
		ft_strjoinaf2.c \
		ft_strjoinaf12.c \
		ft_abs.c \
		ft_sqrt.c \
		ft_iterative_factorial.c \
		ft_recursive_factorial.c \
		ft_range.c \
		ft_foreach.c \
		mallocp.c \
		$(PRINTF)/arg_list.c \
		$(PRINTF)/flag.c \
		$(PRINTF)/ft_printf.c \
		$(PRINTF)/length_conversion.c \
		$(PRINTF)/parser.c \
		$(PRINTF)/transform_base.c \
		$(PRINTF)/transform_d.c \
		$(PRINTF)/transform_f.c \
		$(PRINTF)/transform_gen.c \
		$(PRINTF)/transform_p.c \
		$(PRINTF)/transform_wide.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OPATH) $(OBJ)
	@echo "Creating OBJ files"
	@echo "Building $@"
	@$(AR) rc $@ $(OBJ)
	@$(RANLIB) $@
	@echo "\033[32m ╔════════════════╗"
	@echo " ║  All is done ! ║"
	@echo " ╚════════════════╝\033[0m"

$(OPATH)/%.o: $(CPATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HPATH)

$(OPATH):
	@echo " \033[33m\033[4m\033[1m → Make rule \033[0m"
	@echo "Creating OBJ directory"
	@$(MKDIR) $@ $@$(PRINTF)

clean:
	@echo " \033[33m\033[4m\033[1m → Clean rule \033[0m"
	@echo "Deleting OBJS"
	@$(RM) -Rf $(OPATH)

fclean: clean
	@echo " \033[33m\033[4m\033[1m → Fclean rule \033[0m"
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[32m ╔═══════════════╗"
	@echo " ║  All clear !  ║"
	@echo " ╚═══════════════╝\033[0m"


re: fclean all
