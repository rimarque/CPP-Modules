#-------------------------------------  COLORS  --------------------------------
RESET			= \033[0m
BLACK 			= \033[1;30m
RED 			= \033[1;31m
GREEN 			= \033[1;32m
YELLOW		 	= \033[1;33m
BLUE			= \033[1;34m
PURPLE 			= \033[1;35m
CYAN 			= \033[1;36m
WHITE 			= \033[1;37m
CLEAR           = \033[2J\033[H

#----------------------------------- COMMANDS ----------------------------------
CC				= c++
RM 				= rm -rf

#-----------------------------------  FLAGS  -----------------------------------
CFLAGS			= -Wall -Wextra -Werror -std=c++98
NPD				= --no-print-directory

#--------------------------------- FILES  ---------------------------------------
NAME 			= ex02
INCLUDE			= includes
OBJDIR			= obj

_FILES 			= Fixed

OBJ				= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJDIR)/, $(OBJ))
_HEADERS		= Fixed.hpp
HDR				= $(addprefix $(INCLUDE)/, $(_HEADERS))

#---------------------------------  RULES  --------------------------------------

all: $(NAME)

$(NAME): $(OBJDIR) $(TARGET) main.cpp
	$(CC) $(CFLAGS) main.cpp  $(TARGET) -I $(INCLUDE) -o $(NAME)
	echo "[$(GREEN)Success$(RESET)] ex00 created!$(BOLD)$(RESET)"

$(OBJDIR)/%.o : %.cpp $(HDR)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	echo "[$(RED)Deleting$(RESET)]  object files deleted$(BOLD)$(RESET)"

fclean: clean
	$(RM) $(NAME)
	echo "[$(RED)Deleting$(RESET)]  .a deleted$(BOLD)"

re: fclean all

.SILENT:

.PHONY: all clean fclean re