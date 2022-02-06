# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tonted <tonted@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 15:51:05 by tblanco           #+#    #+#              #
#    Updated: 2022/02/05 21:51:05 by tonted           ###   ########.fr        #
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

# Create the list of directories
DIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)\///g' | sed -n '1!p')
SRCDIRS	= $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(DIRS), $(addprefix $(OBJDIR)/, $(dir)))

# Create a list of *.c sources in DIRS
SRCS = $(wildcard src/*.c)
SRCS += $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
SRCS := $(filter-out src/checker/checker.c src/checker/op_utils.c, $(SRCS))
SRCSCHECK = $(wildcard src/*.c)
SRCSCHECK += $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
SRCSCHECK := $(filter-out src/push_swap.c src/operations/op_utils.c, $(SRCSCHECK))

# Define objects for all sources
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
OBJSCHECK = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCSCHECK))

# Name the compiler & flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -iquote$(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(HIDE)$(CC) $(CFLAGS) -c  $< -o $@

all			: buildrepo $(NAME)

$(NAME)		: $(OBJS)
	$(HIDE)$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	@printf $(GREEN)"[$@] program created\n"$(RESET)
	
clean		:
	$(HIDE)rm -rf $(OBJDIR) $(OBJSCHECK)
	$(HIDE)$(MAKE) clean -C $(LIBFTDIR)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean		: clean
	$(HIDE)rm -f $(NAME) checker
	$(HIDE)$(MAKE) fclean -C $(LIBFTDIR)

re			: fclean all

checker		: buildrepo $(OBJSCHECK)
	$(HIDE)$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(OBJSCHECK) -L./libft -lft -o checker

buildrepo	:
	$(HIDE)$(call make-repo)

print	:
	@echo $(DIRS)
	@echo $(SRCS)
	@echo $(SRCSCHECK)

test	: docker

viz		: all
	python3 pyviz.py 60 45 13 4 31 41 10 32 21 49 78 79 70 16 5 2 38 35 51 19 69 17 48 14 55 81 26 84 20 56 11 15 83 64 66 47 1 80 7 43 82 22 54 96 27 23 67 6 87 61 57 85 8 40 89 9 86 3 68 52 74 76 37 58 72 59 24 53 25 28 12 44 93 34 63 36 50 42 99 92 62 98 0 91 75 18 71 88 73 39 46 95 90 29 33 65 77 94 97 30
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
viz101		: all
	python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
viz200		: all
	python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
viz500		: all
	python3 pyviz.py `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`

# VALGRIND = -
VALGRIND = -valgrind --leak-check=full
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

# push_swap files
# src/_put_utils.c src/free_utils.c src/get_numbers.c src/manage_input.c src/push_swap.c src/tab_utils.c src/algorithm/algo_big.c src/algorithm/algo_small.c src/algorithm/algo_utils.c src/algorithm/opti_utils.c src/algorithm/sort_b.c src/algorithm/sort_to_a.c src/operations/op_utils.c src/operations/push.c src/operations/rev_rotate.c src/operations/rotate.c src/operations/swap.c

# checker files
# src/_put_utils.c src/free_utils.c src/get_numbers.c src/manage_input.c src/tab_utils.c src/checker/checker.c src/checker/op_utils.c src/algorithm/algo_big.c src/algorithm/algo_small.c src/algorithm/algo_utils.c src/algorithm/opti_utils.c src/algorithm/sort_b.c src/algorithm/sort_to_a.c src/operations/push.c src/operations/rev_rotate.c src/operations/rotate.c src/operations/swap.c