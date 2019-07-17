SHELL := /bin/bash
CC = g++
#CXXFLAGS = -g -std=c++11 -Wall -ansi
CXXFLAGS = -std=c++11
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: equip test
equip: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall %.o -o equip
%.o: %.cpp global.h
	$(CC) $(CXXFLAGS) -c $<
help: 
	@echo ./equip calculate
	@echo ./equip input "equip_type" "set_type" atk atk_pctg hp hp_pctg def def_pctg crit_chance crit_dmg dual_atk_chance effectiveness effect_resist speed;
test:
	./equip calculate
clean: 
	rm -rf $(OBJS)