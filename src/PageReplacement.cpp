#include "../include/PageReplacement.h"

std::vector<int> PageReplacement::getBuffer() const{
	return _buffer;
}

int PageReplacement::getFrameSize() const{
	return _frameSize;
}

void PageReplacement::setFrameSize(int frameSize){
	_frameSize = frameSize;
}

int PageReplacement::getPage() const{
	return _page;
}

void PageReplacement::setPage(int page){
	_page = page;
}

int PageReplacement::getHead() const{
	return _head;
}

void PageReplacement::setHead(int head){
	_head = head;
}

bool PageReplacement::searchNumber(int number) const{
		bool found = false; 
		for(int i = 0; i < _buffer.size(); i++){
			if(_buffer[i] == number){
				found = true;
				return found;
			}
		}
		return found;
}