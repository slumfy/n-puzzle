
######################
# EDITABLE VARIABLES #
######################
EXEC	=	ft_retro

CXX			=	clang++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

SRCDIR		=	srcs
SRCFILES	=	main.cpp\
				Colours.cpp\
				Enemy.cpp\
				Game.cpp\
				MainScreen.cpp\
				MsTimer.cpp\
				Obstacle.cpp\
				Projectile.cpp\
				Player.cpp\
				RandomGenerator.cpp\
				Road.cpp\
				Screen.cpp\
				StatusScreen.cpp

OBJDIR		=	objs
OBJFILES	=	$(SRCFILES:%.cpp=$(OBJDIR)/%.o)

IDIR	=	includes
IFLAGS	=	$(addprefix -I,$(IDIR))

LDDIR = $(HOME)/.brew/Cellar/ncurses/6.1/lib
LDFGLAGS	= -L$(LDDIR) -lncursesw

DEPDIR		=	deps
DEPFILES	=	$(SRCFILES: %.c=$(DEPDIR)/%.d)
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

###############
# DO NOT EDIT #
###############

.PHONY: all clean fclean re

all: $(EXEC)

$(EXEC): $(OBJFILES)
	@echo "Compiling ${GREEN}$@${NC} executable..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFGLAGS)

$(OBJFILES): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPDIR)/%.d
	@mkdir -p $(OBJDIR) ${DEPDIR}
	@echo "Compiling ${BLUE}$(@F)${NC}..."
	@$(CXX) $(CXXFLAGS) $(IFLAGS) $(DEPFLAGS) -o $@ -c $<

$(DEPDIR)/%.d:	;

# Make dep directory precious so that .d files don't get destroy in intermediate builds
.PRECIOUS: $(DEPDIR)/%.d

clean:
	@echo "Cleaning ${RED}build artifacts${NC}..."
	@rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	@echo "Cleaning ${RED}executable${NC}..."
	@rm -rf $(EXEC)

re: fclean all

-include $(DEPFILES)

#################
# Customization #
#################
# echo output colours
RED	= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
NC	= \033[0m
