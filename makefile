SHELL := /bin/bash
CXX := g++
CXXFLAGS := -g -std=c++11 -O3 -Wall
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main
main: $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
$(OBJS): $(SRCS)
	@$(CXX) $(CXXFLAGS) -c $^
help: 
	@echo ./main calculate
	@echo ./main input "equip_type" "set_type" atk atk_pctg hp hp_pctg def def_pctg crit_chance crit_dmg dual_atk_chance effectiveness effect_resist speed;
run:
	# ./main input
	./main calculate
clean: 
	-rm -rf *.o $(EXEC)