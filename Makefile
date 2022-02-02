# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tonted <tonted@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 15:51:05 by tblanco           #+#    #+#              #
#    Updated: 2022/02/01 17:48:12 by tonted           ###   ########.fr        #
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

diff		: all
	./push_swap 75 58 79 40 15 18 39 50 94 13 48 70 14 51 59 91 41 64 86 47 35 93 68 81 71 97 42 80 24 44 20 12 28 57 90 31 10 96 7 4 60 87 61 33 11 54 45 66 69 46 25 23 76 49 85 92 37 2 98 77 16 99 3 1 19 83 8 38 65 95 9 43 36 52 21 0 74 67 89 5 84 88 62 22 32 29 56 34 78 27 82 55 53 6 17 72 73 26 30 63 | wc -l
	./push_swap 44 73 83 63 62 20 22 87 30 99 33 45 39 4 47 89 27 59 66 35 19 49 75 65 78 37 72 48 21 60 74 17 61 52 32 67 40 42 1 2 36 23 5 80 50 95 88 29 81 34 9 98 13 6 92 56 8 97 41 11 53 71 25 26 68 12 90 24 93 54 38 55 86 58 77 10 82 96 79 46 76 57 84 14 43 85 15 18 7 31 28 69 16 0 91 94 3 70 51 64 | wc -l

viz		: all
	python3 pyviz.py 75 58 79 40 15 18 39 50 94 13 48 70 14 51 59 91 41 64 86 47 35 93 68 81 71 97 42 80 24 44 20 12 28 57 90 31 10 96 7 4 60 87 61 33 11 54 45 66 69 46 25 23 76 49 85 92 37 2 98 77 16 99 3 1 19 83 8 38 65 95 9 43 36 52 21 0 74 67 89 5 84 88 62 22 32 29 56 34 78 27 82 55 53 6 17 72 73 26 30 63
viz2	: all
	python3 pyviz.py 44 73 83 63 62 20 22 87 30 99 33 45 39 4 47 89 27 59 66 35 19 49 75 65 78 37 72 48 21 60 74 17 61 52 32 67 40 42 1 2 36 23 5 80 50 95 88 29 81 34 9 98 13 6 92 56 8 97 41 11 53 71 25 26 68 12 90 24 93 54 38 55 86 58 77 10 82 96 79 46 76 57 84 14 43 85 15 18 7 31 28 69 16 0 91 94 3 70 51 64
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
viz200		: all
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