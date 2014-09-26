.PHONY:clean
CC=g++
CFLAGS=-Wall -g
BIN=test_string.exe
OBJS=main.o String.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)