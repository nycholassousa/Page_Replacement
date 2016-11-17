#include "../include/PageReplacement.h"

std::vector<int> PageReplacement::getBuffer() const{
	return _buffer;
}

int PageReplacement::getBufferValue(int value) const{
	return _buffer[value];
}

void PageReplacement::setBuffer(std::vector<int> buffer){
	_buffer = buffer;
}

int PageReplacement::getFrameSize() const{
	return _frame_size;
}

void PageReplacement::setFrameSize(int value){
	_frame_size = value;
}

int PageReplacement::getPaging() const{
	return _paging;
}

void PageReplacement::setPaging(int value){
	_paging = value;
}

int PageReplacement::getHead() const{
	return _head;
}

void PageReplacement::setHead(int value){
	_head = value;
}

bool PageReplacement::inMemory(int value) const{
		bool found = false; 
		for(int i = 0; i < _buffer.size(); i++){
			if(_buffer[i] == value){
				found = true;
				break;
			}
		}
		return found;
}

void PageReplacement::incrementPaging(){
	_paging++;
}

void PageReplacement::incrementHead(){
	_head++;
}

void PageReplacement::incrementHeadNPage(){
	_head++;
	_paging++;
}

void PageReplacement::decrementHead(){
	_head--;
} 

int PageReplacement::whatNumberInMemory(int value) const{
	for(int i = 0; i < _buffer.size(); i++){
		if(_buffer[i] == value)
			return value;
	}
}

void PageReplacement::incrementPaging(bool test){
	if(test)
		_paging++;
	else
		_paging--;
}