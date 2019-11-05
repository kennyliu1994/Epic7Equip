SHELL := /bin/bash
CXX := g++
CXXFLAGS := -g -std=c++11 -O3 -Wall
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXEC := $(SRCS:.cpp=)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
$(OBJS): $(SRCS)
	@$(CXX) $(CXXFLAGS) -c $^
help: 
	@echo ./main input [部位] [套裝] [攻擊] [攻擊%] [生命] [生命%] [防禦] [防禦%] [暴擊] [暴傷] [命中] [抵抗] [速度]
	@echo ./main database
	@echo ./main calculate [角色] [套裝] [排序] [暴擊大於多少] [速度大於多少]
run:
	./main calculate 蒂姬 速度 速度 0 240
clean: 
	@-rm -rf *.o $(EXEC)