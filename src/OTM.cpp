#include "../include/OTM.h"
#include <stdio.h>

void OTM::start(int value){
	_otmBuffer.push_back(value);
}

void OTM::future(){
	int lastPosition;
	int aux;
	for (int i = 0; _buffer.size() < getFrame(); i++){
		
		if(i == 0){
			setPage(getPage() - 1);
		}

		_buffer.push_back(_otmBuffer[i]);
		setPage(getPage() + 1);
		lastPosition = i;
	}
	for(int i = lastPosition; i < _otmBuffer.size(); i++){
		if(searchNumber(_otmBuffer[i]) == false){
			aux = distance(i);
			_buffer[aux] = _otmBuffer[i];
			setPage(getPage() + 1);
		}
	}

}

int OTM::distance(int value) const{
	std::vector<int> distance;
	int j = 0;
	int aux = value; 

	distance.clear();

	for(int i = 0; i < _buffer.size(); i++){
		for(j = aux; j < _otmBuffer.size(); j++){
			if(_buffer[i] == _otmBuffer[j]){
				distance.push_back(j);
			}
		}
		j = 0;
	}
	
	return 0;
}