TARGET = client1.out client2.out
SOURCE1 = ./main/process_client1.c ./prod_common_ipc_easylogger/prod_common_ipc_easylogger.c
SOURCE2 = ./main/process_client2.c ./prod_common_ipc_easylogger/prod_common_ipc_easylogger.c
OBJ1 = process_client1.o prod_common_ipc_easylogger.o
OBJ2 = process_client2.o prod_common_ipc_easylogger.o
INCLUDE = -I./prod_common_ipc_easylogger

all : $(TARGET)
	mv $(TARGET) ../out

client1.out : $(OBJ1)
	cc -o $@ $^

client2.out : $(OBJ2)
	cc -o $@ $^

process_client1.o: ./main/process_client1.c
	cc -o $@ -c $^ $(INCLUDE)

process_client2.o: ./main/process_client2.c
	cc -o $@ -c $^ $(INCLUDE)

prod_common_ipc_easylogger.o: ./prod_common_ipc_easylogger/prod_common_ipc_easylogger.c
	cc -o $@ -c $^ $(INCLUDE)

clean:
	rm -f ./*.o
	rm -f ../out/client1.out ../out/client2.out
