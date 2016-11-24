#include "../include/PageReplacement.h"

//O buffer terá o tamanho da primeira linha do input.txt
std::vector<int> PageReplacement::getBuffer() const{
	return _buffer;
}

//Tamanho do quadro
int PageReplacement::getFrame() const{
	return _frame;
}

//Manipula o tamanho do quadro
void PageReplacement::setFrame(int frame){
	_frame = frame;
}

//Páginas, diz quantas páginas estão faltando até o momento
int PageReplacement::getPage() const{
	return _page;
}

//Modifica a quantidade de páginas em falta
void PageReplacement::setPage(int page){
	_page = page;
}

//Cabeçalho, responsável por controlar o tamanho da página no buffer
int PageReplacement::getHead() const{
	return _head;
}

//Manipula o cabeçalho do buffer
void PageReplacement::setHead(int head){
	_head = head;
}

//Verifica se o valor está contido no buffer
bool PageReplacement::searchNumber(int number) const{
		for(int i = 0; i < _buffer.size(); i++){
			if(_buffer[i] == number){
				return true;
			}
		}
		return false;
}