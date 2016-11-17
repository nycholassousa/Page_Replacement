#include "../include/FIFO.h"

void FIFO::init(int value){
	
	if(_buffer.size() != getFrameSize()){
		if(searchNumber(value) == false){
			_buffer.push_back(value);
			setHead(getHead() + 1);
			setPage(getPage() + 1);
		}
	}

	if(getHead() >= getFrameSize())
		setHead(0);
	
	if(searchNumber(value) == false){
		_buffer[_head] = value;
			setHead(getHead() + 1);
			setPage(getPage() + 1);
	}

}


