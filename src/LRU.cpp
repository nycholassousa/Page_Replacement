#include "../include/LRU.h"


void LRU::init(int value){
	int oldest = 0;
	if(_buffer.size() < getFrameSize()){
		if(inMemory(value) == false){
			_buffer.push_back(value);
			_age.push_back(getHead());
			incrementHead();
			incrementPaging();
		}
	}

	else {
		if(getHead() >= getFrameSize())
			setHead(0);

		if(inMemory(value) == false){
			incrementPaging();
			int old = getHead()+1;
			
			if(old >= getFrameSize())
				old = 0;

			_buffer[old] = value;
		}

		incrementHead();
	}
}