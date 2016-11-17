#include "../include/FIFO.h"

void FIFO::init(int value){
	
	if(_buffer.size() != getFrameSize()){
		if(inMemory(value) == false){
			_buffer.push_back(value);
			incrementHeadNPage();
		}
	}

	if(getHead() >= getFrameSize())
		setHead(0);
	
	if(inMemory(value) == false){
		_buffer[_head] = value;
		incrementHeadNPage();
	}

}


