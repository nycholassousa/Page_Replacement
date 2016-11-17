#include "../include/LRU.h"


void LRU::init(int value){
	int oldest = 0;
	if(_buffer.size() < getFrame()){
		if(searchNumber(value) == false){
			_buffer.push_back(value);
			_age.push_back(getHead());
			setHead(getHead() + 1);
			setPage(getPage() + 1);
		}
	}

	else {
		if(getHead() >= getFrame())
			setHead(0);

		if(searchNumber(value) == false){
			setPage(getPage() + 1);
			int old = getHead() + 1;
			
			if(old >= getFrame())
				old = 0;

			_buffer[old] = value;
		}

		setHead(getHead() + 1);
	}
}