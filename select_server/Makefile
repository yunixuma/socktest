# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2024/10/28 14:32:46 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME_SV		= server
# Enumeration of files
SRC_SV		= main.c
# SRC_CL		= 
# SRC_COMMON	= noblk_socket.c noblk_setopt.c noblk_bind.c noblk_listen.c \
# 			  noblk_exit.c

# Check the platform
OS			= $(shell uname)

# Defination of macro constants

# Aliases of commands
CC			= cc
RM			= rm

# Command options (flags)
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
DEBUGFLAGS	= -g -ggdb -fsanitize=address \
			  -fstack-usage -fno-omit-frame-pointer
# INCLUDES	= -I$(INCDIR)
RMFLAGS		= -r

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re

# Mandatory targets
all: $(LIBS) $(NAME_CL) $(NAME_SV)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME_SV) $(NAME_CL)
re: fclean $(OBJDIR) all

# Recipes
$(NAME_SV):
	$(CC) -D MODE=1 $(CFLAGS) $(SRC_SV) $(LIBS) -o $(NAME_SV)
# $(NAME_CL): $(OBJS_CL)
#	 $(CXX) -D MODE=0 $(CFLAGS) $(SRC_CL) $(LIBS) -o $(NAME_CL)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
