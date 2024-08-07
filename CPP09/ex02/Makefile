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
CXX				= c++
RM 				= rm -rf

#-----------------------------------  FLAGS  -----------------------------------
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
NPD				= --no-print-directory

#--------------------------------- FILES  ---------------------------------------
NAME 			= PmergeMe
INCLUDE			= includes
OBJDIR			= obj

_FILES 			= $(NAME)

OBJ				= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJDIR)/, $(OBJ))
_HEADERS		= $(NAME).hpp
HDR				= $(addprefix $(INCLUDE)/, $(_HEADERS))

#---------------------------------  RULES  --------------------------------------

all: $(NAME)

$(NAME): $(OBJDIR) $(TARGET) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp  $(TARGET) -I $(INCLUDE) -o $(NAME)
	echo "[$(CYAN)Compiling$(RESET)] $(CXX) $(CXXFLAGS) main.cpp $(RESET)"
	echo "[$(GREEN)Success$(RESET)] $(NAME) created!$(BOLD)$(RESET)"

$(OBJDIR)/%.o : %.cpp $(HDR)
	echo "[$(CYAN)Compiling$(RESET)] $(CXX) $(CXXFLAGS) $<$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDE)

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