CC=g++
CXXFLAGS=-g -Wall
APP=pa3
SRC=src
BIN=bin

vpath %.h $(SRC)
vpath %.cpp $(SRC)

OBJS=Money.o Account.o

$(APP): $(OBJS) main.cpp
	$(CC) $(CXXFLAGS) -o $(BIN)/$@ $^ 

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm *.o

run:
	$(BIN)/./$(APP)
