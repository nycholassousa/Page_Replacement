#include <iostream>
#include <fstream>
#include "../include/FIFO.h"
#include "../include/OTM.h"
#include "../include/LRU.h"

int main(void){
	int fileData;
	bool firstTime = true;

	FIFO *fifo = new FIFO();
	OTM  *otm = new OTM();
	LRU  *lru = new LRU();

	std::ifstream file("input.txt");

	while(file >> fileData){
		if (firstTime){
			fifo->setFrame(fileData);
			otm->setFrame(fileData);
			lru->setFrame(fileData);

			firstTime = false;
		} else {
			fifo->start(fileData);
			otm->start(fileData);
			lru->start(fileData);
		}
	}

	otm->future();
	
	if(lru->getBuffer().size() == lru->getFrame())
		lru->setPage(lru->getPage() + 1);

	std::cout << "FIFO " << fifo->getPage() << endl;
	std::cout << "OTM " << otm->getPage() << endl;
	std::cout << "LRU " << lru->getPage() << endl;

	return 0;
}