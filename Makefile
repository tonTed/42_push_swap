# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tonted <tonted@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 15:51:05 by tblanco           #+#    #+#              #
#    Updated: 2022/01/31 21:56:08 by tonted           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Configuration of paths
SRCDIR := src
OBJDIR := obj
INCDIR := include
LIBFTDIR := libft

# Name of the final executable
NAME = push_swap

# Decide whether the commands will be shwon or not
VERBOSE = TRUE

ENTRYPOINT = src/push_swap.c

# Unit Test management
UTEST = .test/_test_main.c
USRCS = $(wildcard .test/*.c)

# Create the list of directories
DIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)\///g' | sed -n '1!p')
SRCDIRS	= $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(DIRS), $(addprefix $(OBJDIR)/, $(dir)))

# Create a list of *.c sources in DIRS
SRCS = $(wildcard src/*.c)
SRCS += $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
SRCS := $(filter-out $(ENTRYPOINT), $(SRCS))

# Define objects for all sources
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Name the compiler & flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -iquote$(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(HIDE)$(CC) $(CFLAGS) -c  $< -o $@

all			: buildrepo $(NAME)

$(NAME)		: $(OBJS)
	$(HIDE)$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(ENTRYPOINT) $(OBJS) -L./libft -lft -o $(NAME)
	@printf $(GREEN)"[$@] program created\n"$(RESET)
	
clean		:
	$(HIDE)rm -rf $(OBJDIR)
	$(HIDE)$(MAKE) clean -C $(LIBFTDIR)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean		: clean
	$(HIDE)rm -f $(NAME)
	$(HIDE)$(MAKE) fclean -C $(LIBFTDIR)

re			: fclean all

buildrepo	:
	$(HIDE)$(call make-repo)

print	:
	@echo $(DIRS)
	@echo $(SRCS)

utest	: buildrepo $(OBJS)
	$(HIDE)$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) $(USRCS) -L./libft -lft -o utest
	@printf $(BLUE)"[$@] unit_test \n"$(RESET)
	./utest && rm -rf utest

test	: docker

viz		: all
	python3 pyviz.py 28 0 37 15 3 13 5 2 55 32 19 36 8 46 1 16 43 18 27 57 33 51 26 44 41 9 35 38 54 21 17 6 7 49 24 31 40 12 34 50 25 53 23 42 29 4 20 58 48 11 59 45 30 52 14 47 10 39 22 56
viz3		: all
	python3 pyviz.py `ruby -e "puts (0..2).to_a.shuffle.join(' ')"`
viz5		: all
	python3 pyviz.py `ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
viz50		: all
	python3 pyviz.py `ruby -e "puts (0..49).to_a.shuffle.join(' ')"`
viz60		: all
	python3 pyviz.py `ruby -e "puts (0..59).to_a.shuffle.join(' ')"`
viz100		: all
	python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
viz500		: all
	python3 pyviz.py `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`

# VALGRIND = -
VALGRIND = -valgrind --leak-check=full -q
_test	:  re
# @printf $(BLUE)"\n>>>> "$(RESET)
# $(VALGRIND) ./push_swap
# @printf $(BLUE)"\n>>>> "$(RESET)
# $(VALGRIND) ./push_swap "0"
# @printf $(BLUE)"\n>>>> "$(RESET)
# $(VALGRIND) ./push_swap a
# @printf $(BLUE)"\n>>>> "$(RESET)
# $(VALGRIND) ./push_swap "-1 0 5 69"
# @printf $(BLUE)"\n>>>> "$(RESET)
# $(VALGRIND) ./push_swap 5 -003 -2147483649
# @printf $(BLUE)"\n>>>> "$(RESET)
# $(VALGRIND) ./push_swap "-1 g 5 69"
# @printf $(BLUE)"\n>>>> "$(RESET)
# $(VALGRIND) ./push_swap 5 7 3 90 3
	@printf $(BLUE)"\n>>>> "$(RESET)
	$(VALGRIND) ./push_swap 5 7 90 3

	@printf $(GREEN)"\nEND OF TEST\n"$(RESET)

docker		:
	docker build ../ -t 42/valgrind
	docker run --rm -it --name valgrind -v /Users/tonted/42:/42projects 42/valgrind

.PHONY		: clean fclean all re $(OBJDIR) buildrepo print

# Create 
define make-repo
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)for dir in $(DIRS); \
   	do \
	mkdir -p $(OBJDIR)/$$dir; \
   	done
endef

# Color
BLACK := "\e[0;30m"
RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE =  
else
    HIDE = @
endif