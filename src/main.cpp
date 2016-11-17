#include <iostream>
#include "../include/FIFO.h"
#include "../include/OTM.h"
#include "../include/LRU.h"

int main(void){
	int entry_date;
	FIFO *fifo;
	OTM  *otm;
	LRU  *lru;
	bool first_entry = true;
	
	while(std::cin >> entry_date){
		if(first_entry){
			fifo = new FIFO();
			otm  = new OTM();
			lru  = new LRU();

			fifo->setFrameSize(entry_date);
			otm->setFrameSize(entry_date);
			lru->setFrameSize(entry_date);

			first_entry = false;		
		} else {
			fifo->init(entry_date);
			otm->init(entry_date);
			lru->init(entry_date);
		}
	}

	otm->lookingToFuture();
	
	if(lru->getBuffer().size() == lru->getFrameSize())
		lru->setPage(lru->getPage() + 1);

	std::cout << "FIFO " << fifo->getPage() << endl;
	std::cout << "OTM " << otm->getPage() << endl;
	std::cout << "LRU " << lru->getPage() << endl;


}