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
	@echo ./main calculate [角色] [套裝] [暴擊>?] [速度>?]
	@echo ./main input [部位] [套裝] 515 0 601 22 0 0 0 0 13 5 0
run:
	./main calculate Lorina 攻擊 90 0
clean: 
	-rm -rf *.o $(EXEC)