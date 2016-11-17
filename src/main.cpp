#include <iostream>
#include <fstream>
#include "../include/FIFO.h"
#include "../include/OTM.h"
#include "../include/LRU.h"

int main(void){
	int number;
	FIFO *fifo;
	OTM  *otm;
	LRU  *lru;
	bool first_in = true;

	std::ifstream file("input.txt");

	while(file >> number){
		if (first_in){
			fifo = new FIFO();
			otm = new OTM();
			lru = new LRU();

			fifo->setFrame(number);
			otm->setFrame(number);
			lru->setFrame(number);

			first_in = false;
		} else {
			fifo->init(number);
			otm->init(number);
			lru->init(number);
		}
	}

	otm->lookingToFuture();
	
	if(lru->getBuffer().size() == lru->getFrame())
		lru->setPage(lru->getPage() + 1);

	std::cout << "FIFO " << fifo->getPage() << endl;
	std::cout << "OTM " << otm->getPage() << endl;
	std::cout << "LRU " << lru->getPage() << endl;
}