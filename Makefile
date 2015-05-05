#modifiable vars
CFLAGS = --std=c++11 -W -Wall -Wextra
SRCEXT = cpp
SRCD = src
OBJD = obj
BIND = bin
EXENAME = rubik
SHELL = /bin/bash

#be careful modifying anything past this point !
SRC = $(wildcard $(SRCD)/*.$(SRCEXT))
OBJ = $(SRC:$(SRCD)/%.cpp=$(OBJD)/%.o)
BIN = $(BIND)/$(EXENAME)

CC_RED = \e[31m
CC_GREEN = \e[32m
CC_YELLOW = \e[33m
CC_BLUE = \e[34m
CC_MAGENTA = \e[35m
CC_CYAN = \e[36m

CC_NORMAL = \e[0m

EMPH = $(patsubst %,$(CC_GREEN)%$(CC_NORMAL),"$1")
DIR = $(patsubst %,$(CC_CYAN)%$(CC_NORMAL),"$1")
WARN = $(patsubst %,$(CC_YELLOW)%$(CC_NORMAL),"$1")
ERR = $(patsubst %,$(CC_RED)%$(CC_NORMAL),"$1")

default: $(OBJ)
ifneq ($(wildcard $(SRCD) $(OBJD) $(BIND)), $(SRCD) $(OBJD) $(BIND))
	@echo -e "Directory not tied up ! Try to run $(call WARN,"make organize") to solve your problems."
else
	@echo -e "Building $(call EMPH,$(BIND)/$(EXENAME)) from $(call EMPH,"$^")"
	@g++ $(CFLAGS) -o $(BIN) $^
endif

$(OBJD)/%.o : $(SRCD)/%.$(SRCEXT)
	@echo -e "Building $(call EMPH,$@)"
	@g++ $(CFLAGS) -c -o $@ $^

organize: clean
ifneq ($(wildcard $(SRCD) $(OBJD) $(BIND)), $(SRCD) $(OBJD) $(BIND))
	@echo "Creating directories"
	@mkdir -p $(SRCD) $(OBJD) $(BIND)
endif
ifneq ($(wildcard *.$(SRCEXT) *.h *.hpp),)
	@echo -e "Moving sources to $(call DIR,$(SRCD))/"
	@mv $(wildcard *.h *.hpp *.$(SRCEXT)) $(SRCD)/
endif
	@echo -e "Everything is tied up !"

break: clean
ifneq ($(strip $(wildcard $(SRCD)/*)),)
	@echo "moving everything to project root"
	@mv $(SRCD)/* ./
endif
ifneq ($(wildcard $(SRCD)),)
	@echo "deleting directories"
	@rm -rf $(SRCD) $(OBJD) $(BIND)
else
	@echo "everything is already on root, nothing to do !"
endif
clean:
	@rm -rf $(OBJ) $(BIN)

strongclean: clean
	@rm -rf *.o
	@rm -rf \#*# *~ main a.out
	@rm -rf $(SRCD)/*~ $(SRCD)/\#*#

cleanbuild: clean default

debugbuild: cleanbuild debug

debug: 
	@echo -e "\n\n-------------------------------------------------------------------------\n\n"
	./$(BIN)

edit: 
	-@for file in $(SRC); do \
		($$EDITOR $$file $${file%cpp}hpp &);  \
	done

background:
	$$EDITOR &
