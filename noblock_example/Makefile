# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2023/09/22 12:17:29 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME_SV		= noblk
# NAME_CL		= client

# Enumeration of files
SRC_SV		= noblk_main.c noblk_ioctl.c noblk_init.c noblk_poll.c \
			  noblk_sequential.c noblk_accept.c noblk_comm.c \
			  noblk_compress.c noblk_clean.c
# SRC_CL		= 
SRC_COMMON	= noblk_socket.c noblk_setopt.c noblk_bind.c noblk_listen.c \
			  noblk_exit.c

# Check the platform
OS			= $(shell uname)

# Defination of macro constants

# Enumeration of directories
SRCDIR		= ./src
INCDIR		= ./include
OBJDIR		= ./obj

# Macros to replace and/or integrate
SRCS_SV		= $(addprefix $(SRCDIR)/, $(SRC_SV)) \
			  $(addprefix $(SRCDIR)/, $(SRC_COMMON))
SRCS_CL		= $(addprefix $(SRCDIR)/, $(SRC_CL)) \
			  $(addprefix $(SRCDIR)/, $(SRC_COMMON))
OBJS_SV		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_SV:.c=.o)))
OBJS_CL		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_CL:.c=.o)))
DEPS_SV		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_SV:.c=.d)))
DEPS_CL		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_CL:.c=.d)))
LIBS		= 

# Aliases of commands
CC			= cc
RM			= rm

# Command options (flags)
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
DEBUGFLAGS	= -g -ggdb -fsanitize=address \
			  -fstack-usage -fno-omit-frame-pointer
INCLUDES	= -I$(INCDIR)
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
$(NAME_SV): $(OBJS_SV)
	$(CC) -D MODE=1 $(CFLAGS) $(OBJS_SV) $(LIBS) -o $(NAME_SV)
# $(NAME_CL): $(OBJS_CL)
#	 $(CXX) -D MODE=0 $(CFLAGS) $(OBJS_CL) $(LIBS) -o $(NAME_CL)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS_SV) #$(DEPS_CL)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
