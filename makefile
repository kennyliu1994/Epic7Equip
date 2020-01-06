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
	@echo ./main calculate [角色] [套裝] [排序] [暴擊大於多少] [速度大於多少] [生命大於多少]
	@echo bash mark.sh 1 2 3 4 5 6
run:
	# 暗槍,賽茲,水奶,暗拉茲,露娜,木刺,偶像,蒂姬,木反,伊賽麗亞,暗刺,木狼,木扇,狗子,光槍,水扇,小水奶,暗狗,席德
	# 巴塞爾,泰溫,光鐮,暗兔,女僕,寶馬

	# 生命 防禦 攻擊 速度 暴擊 命中 破滅  吸血 反擊 抵抗 夾攻 憤怒 免疫

	# 生命 速度 攻擊暴傷 命中 抵抗

	# ./main calculate 巴塞爾 速度 速度 0 235 0
	# 384s
	# ./main calculate 暗刺 攻擊 攻擊暴傷 95 0 0
	# 310s
	# ./main calculate 光鐮 攻擊 攻擊暴傷 37 0 0
	# 259s
	# ./main calculate 暗兔 速度 攻擊暴傷 50 170 0
	# 243s
	# ./main calculate 暗狗 速度 攻擊暴傷 70 180 0
	# 183s
	# ./main calculate 女僕 速度 生命 0 200 0
	# 174s
	# ./main calculate 泰溫 速度 命中 0 200 0
	# 142s
	# ./main calculate 水扇 0 攻擊暴傷 70 0 13000
	# 188s
	# ./main calculate 露娜 吸血 攻擊暴傷 65 0 0
	# 108s
	# ./main calculate 小水奶 速度 抵抗 0 170 13000
	# 80s
	# ./main calculate 伊賽麗亞 速度 命中 0 170 13000
	# 63s
clean: 
	@-rm -rf *.o $(EXEC)