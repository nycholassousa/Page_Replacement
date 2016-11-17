#include "../include/OTM.h"
#include <stdio.h>

void OTM::start(int value){
	_heap.push_back(value);
}

void OTM::lookingToFuture(){
	int lastPosition;
	int aux;
	for (int i = 0; _buffer.size() < getFrame(); i++){
		
		if(i == 0){
			setPage(getPage() - 1);
		}

		_buffer.push_back(_heap[i]);
		setPage(getPage() + 1);
		lastPosition = i;
	}
	for(int i = lastPosition; i < _heap.size(); i++){
		if(searchNumber(_heap[i]) == false){
			aux = higherDistance(i);
			_buffer[aux] = _heap[i];
			setPage(getPage() + 1);
		}
	}

}

int OTM::higherDistance(int value) const{
	std::vector<int> distance;
	int j = 0;
	int aux = value; 

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