# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2023/09/07 16:32:01 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME_SV		= server
NAME_CL		= client

# Enumeration of files
SRC_SV		= sv_main.cpp
SRC_CL		= cl_main.cpp
SRC_COMMON	= 

# Check the platform
OS				= $(shell uname)

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
OBJS_SV		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_SV:.cpp=.o)))
OBJS_CL		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_CL:.cpp=.o)))
DEPS_SV		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_SV:.cpp=.d)))
DEPS_CL		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS_CL:.cpp=.d)))
LIBS		= 

# Aliases of commands
CXX			= c++
RM			= rm

# Command options (flags)
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
DEBUGFLAGS	= -g -ggdb -fsanitize=address \
			  -fstack-usage -fno-omit-frame-pointer
INCLUDES	= -I$(INCDIR)
RMFLAGS		= -rf

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re

# Mandatory targets
all: $(LIBS) $(NAME_CL) $(NAME_SV)
clean:
	$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME_SV) $(NAME_CL)
re: fclean $(OBJDIR) all

# Recipes
$(NAME_SV): $(OBJS_SV)
	$(CXX) $(CFLAGS) $(OBJS_SV) $(LIBS) -o $(NAME_SV)
$(NAME_CL): $(OBJS_CL)
	$(CXX) $(CFLAGS) $(OBJS_CL) $(LIBS) -o $(NAME_CL)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS_SV) $(DEPS_CL)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
