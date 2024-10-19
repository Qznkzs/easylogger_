CC = cc

INCLUDE = -I./easylogger/inc -I./easylogger/plugins/file
LIB=-lpthread

OBJ += $(patsubst %.c, %.o, $(wildcard *.c))
OBJ += $(patsubst %.c, %.o, $(wildcard ./main/*.c))
OBJ += $(patsubst %.c, %.o, $(wildcard ./easylogger/src/*.c))
OBJ += $(patsubst %.c, %.o, $(wildcard ./easylogger/plugins/file/*.c))
OBJ += $(patsubst %.c, %.o, $(wildcard ./easylogger/port/*.c))

CFLAGS = -O0 -g3 -Wall
target = server.out

all:$(OBJ)
	$(CC) $^ -o $(target) $(LIB)
	mv $(target) ../out
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
clean:
	rm -rf out/*
