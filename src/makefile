mkfile_path = $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir = $(dir $(mkfile_path))
# 源文件
SRC = main.cpp SDL_RenderApp.cpp Tracer.cpp Sphere.cpp Hitable_list.cpp Camera.cpp Drand48.cpp Ray_compute.cpp
# 库的位置
INCLUDEDIR = $(mkfile_dir)/../include/
SDLDIR = $(INCLUDEDIR)/SDLlib
# 编译参数
CFLAGS = -I $(SDLDIR)/include -I $(INCLUDEDIR) -L $(SDLDIR)/lib -lmingw32 -lSDL2main -lSDL2 -O2 #-mwindows 
# 选择编译器
CC = g++

demo.exe: $(SRC)
	$(CC) -g $(SRC) $(CFLAGS) -o ../demo.exe