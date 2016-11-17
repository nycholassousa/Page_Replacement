#include "../include/PageReplacement.h"

std::vector<int> PageReplacement::getBuffer() const{
	return _buffer;
}

int PageReplacement::getFrame() const{
	return _frame;
}

void PageReplacement::setFrame(int frame){
	_frame = frame;
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
		for(int i = 0; i < _buffer.size(); i++){
			if(_buffer[i] == number){
				return true;
			}
		}
		return false;
}