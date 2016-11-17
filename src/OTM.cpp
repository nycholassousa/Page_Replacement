#include "../include/OTM.h"
#include <stdio.h>

void OTM::init(int value){
	_heap.push_back(value);
}

void OTM::lookingToFuture(){
	int aux = 0;
	int i = 0;
	for(i = 0; _buffer.size() < getFrameSize(); i++){
		
		if(i == 0){
			incrementPaging(false);
		}

		_buffer.push_back(_heap[i]);
		incrementPaging();
	}
	for(i; i < _heap.size(); i++){
		if(inMemory(_heap[i]) == false){
			aux = higherDistance(i);
			//printf("Changed: %d", );
			_buffer[aux] = _heap[i];
			incrementPaging();
			//printf("%d\n", buffer[i]);
		}
	}

}

int OTM::higherDistance(int test){
	int i = 0, i2 =0 ;
	std::vector<int> distance;
	int aux = test;
	int higher_position = 0; 
	distance.clear();
	for(i = 0; i < _buffer.size(); i++){
		for(i2 = aux; i2 < _heap.size(); i2++){
			if(_buffer[i] == _heap[i2]){
				distance.push_back(i2);
			}
		}
		i2 = 0;
	}
	
	return 0;
}

int OTM::findPosition(int value){
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