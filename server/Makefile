CC = cc

INCLUDE = -I./easylogger/inc -I./easylogger/plugins/file
LIB=-lpthread

OBJ += $(patsubst %.c, %.o, $(wildcard *.c))
OBJ += $(patsubst %.c, %.o, $(wildcard ./easylogger/src/*.c))
OBJ += $(patsubst %.c, %.o, $(wildcard ./easylogger/plugins/file/*.c))
OBJ += $(patsubst %.c, %.o, $(wildcard ./easylogger/port/*.c))

CFLAGS = -O0 -g3 -Wall
target = EasyLoggerLinuxDemo

all:$(OBJ)
	$(CC) out/*.o -o $(target) $(LIB)
	mv $(target) out
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	mv $@ out
clean:
	rm -rf out/*
