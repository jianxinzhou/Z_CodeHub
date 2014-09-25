.PHONY:clean
CC=g++
CFLAGS=-Wall -g
BIN=test.exe
OBJS=main.o StringUtil.o WordFrequency.o
STAND= -std=c++0x
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(STAND)
clean:
	rm -f *.o $(BIN)