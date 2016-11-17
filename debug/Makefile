CC = g++
INCLUDE_PATH = ../include/
SRC_PATH = ../src/
EXE = os-pagereplace

PageReplacement.o: $(INCLUDE_PATH)PageReplacement.h $(SRC_PATH)PageReplacement.cpp
	$(CC) $(SRC_PATH)PageReplacement.cpp -c

FIFO.o: $(INCLUDE_PATH)FIFO.h $(SRC_PATH)FIFO.cpp
	$(CC) $(SRC_PATH)FIFO.cpp -c

LRU.o: $(INCLUDE_PATH)LRU.h $(SRC_PATH)LRU.cpp
	$(CC) $(SRC_PATH)LRU.cpp -c

OTM.o: $(INCLUDE_PATH)OTM.h $(SRC_PATH)OTM.cpp
	$(CC) $(SRC_PATH)OTM.cpp -c

all: FIFO.o LRU.o OTM.o PageReplacement.o
	$(CC) *.o $(SRC_PATH)main.cpp -o $(EXE)

.PHONY: clean

clean:
	rm -rf *.o $(EXE)