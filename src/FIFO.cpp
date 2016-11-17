#include "../include/FIFO.h"

void FIFO::start(int value){
	
	if(_buffer.size() != getFrame()){
		if(searchNumber(value) == false){
			_buffer.push_back(value);
			setHead(getHead() + 1);
			setPage(getPage() + 1);
		}
	}

	if(getHead() >= getFrame())
		setHead(0);
	
	if(searchNumber(value) == false){
		_buffer[_head] = value;
		setHead(getHead() + 1);
		setPage(getPage() + 1);
	}

}