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

#----------------------------------- COMMANDS ----------------------------------
CXX				= c++
RM 				= rm -rf

#-----------------------------------  FLAGS  -----------------------------------
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98
NPD				= --no-print-directory

#--------------------------------- FILES  ---------------------------------------
NAME 			= megaphone

#---------------------------------  RULES  --------------------------------------

all: $(NAME)

$(NAME): megaphone.cpp
	$(CXX) $(CXXFLAGS) megaphone.cpp -o $(NAME)
	echo "[$(GREEN)Success$(RESET)] megaphone created$(BOLD)$(RESET)"

clean:
	$(RM)
	echo "[$(RED)Deleting$(RESET)]  object files deleted$(BOLD)$(RESET)"

fclean: clean
	$(RM) $(NAME)
	echo "[$(RED)Deleting$(RESET)]  .a deleted$(BOLD)"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
