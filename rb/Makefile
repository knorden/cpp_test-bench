##################################################################
## MAKEFILE: TEMPLATE                                           ##
##################################################################
TMPL		:= 
HDIR 		:= hdr
SDIR		:= src
ODIR		:= obj

EXET		:= a
OBJS		:= main.o unitTest.o utilities.o

OSRC		:= $(addprefix $(ODIR)/, $(OBJS))

CXX		:= g++
CXXFLAGS	:= -I$(HDIR) -g -Wall -std=c++2a \
			-Wextra -Wconversion -pedantic

##################################################################
## BUILD DIRECTIVE:                                             ##
##################################################################
all : $(EXET)

$(EXET) : $(OSRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

$(ODIR)/%.o : $(SDIR)/%.cpp | $(ODIR)
	$(CXX) -c $(CXXFLAGS) $^ -o $@

$(ODIR):
	@if [ ! -d "$(ODIR)" ]; then mkdir $(ODIR); fi

##################################################################
## CLEAN TASK:                                                  ##
##################################################################
.PHONY: clean
clean:
	rm -r $(EXET) $(ODIR)/*
