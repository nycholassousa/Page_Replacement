#include <iostream>
#include <fstream>
#include "../include/FIFO.h"
#include "../include/OTM.h"
#include "../include/LRU.h"

int main(void){
	int fileEntryData;
	bool firstEntryData = true;

	FIFO *fifo;
	OTM  *otm;
	LRU  *lru;

	std::ifstream file("input.txt");

	while(file >> fileEntryData){
		if (firstEntryData){
			fifo = new FIFO();
			otm = new OTM();
			lru = new LRU();

			fifo->setFrame(fileEntryData);
			otm->setFrame(fileEntryData);
			lru->setFrame(fileEntryData);

			firstEntryData = false;
		} else {
			fifo->start(fileEntryData);
			otm->start(fileEntryData);
			lru->start(fileEntryData);
		}
	}

	otm->lookingToFuture();
	
	if(lru->getBuffer().size() == lru->getFrame())
		lru->setPage(lru->getPage() + 1);

	std::cout << "FIFO " << fifo->getPage() << endl;
	std::cout << "OTM " << otm->getPage() << endl;
	std::cout << "LRU " << lru->getPage() << endl;

	return 0;
}