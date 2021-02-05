mkfile_path = $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir = $(dir $(mkfile_path))
# 源文件
SRC = main.cpp
# 库的位置
INCLUDEDIR = $(mkfile_dir)/../include/
SDLDIR = $(INCLUDEDIR)/SDLlib
# 编译参数
CFLAGS = -I $(SDLDIR)/include -I $(INCLUDEDIR) -L $(SDLDIR)/lib -lmingw32 -lSDL2main -lSDL2 -O2 #-mwindows
# 选择编译器
CC = g++

demo.exe: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o ../demo.exe