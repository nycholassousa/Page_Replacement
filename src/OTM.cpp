#include "../include/OTM.h"
#include <stdio.h>

void OTM::init(int value){
	_heap.push_back(value);
}

void OTM::lookingToFuture(){
	int aux = 0;
	int i = 0;
	for (i = 0; _buffer.size() < getFrameSize(); i++){
		
		if(i == 0){
			incrementPaging(false);
		}

		_buffer.push_back(_heap[i]);
		incrementPaging();
	}
	for(i; i < _heap.size(); i++){
		if(inMemory(_heap[i]) == false){
			aux = higherDistance(i);
			_buffer[aux] = _heap[i];
			incrementPaging();
		}
	}

}

int OTM::higherDistance(int test) const{
	int j = 0;
	std::vector<int> distance;
	int aux = test;
	int higher_position = 0; 
	distance.clear();
	for(int i = 0; i < _buffer.size(); i++){
		for(j = aux; j < _heap.size(); j++){
			if(_buffer[i] == _heap[j]){
				distance.push_back(j);
			}
		}
		j = 0;
	}
	
	return 0;
}

int OTM::findPosition(int value) const{
	for(int i = 0; i < _heap.size(); i++){
		if(_heap[i] == value)
			return i;
	}
}


int higherThan(std::vector<int> values){
	int higher = -1;
	int position;

	for(int i = 0; i < values.size(); i++){
		if(values[i] > higher){
			higher = values[i];
			position = i;
		}
	}
	
	return position;
}