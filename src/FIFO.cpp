#include "../include/FIFO.h"

void FIFO::start(int value){
	
	//se o tamanho do buffer seja diferente do tamanho da página
	//função responsável pela criação do buffer com o tamanho da página
	if(_buffer.size() != getFrame()){
		if(searchNumber(value) == false){
			_buffer.push_back(value); //valor da linha lido
			setHead(getHead() + 1); //vai para a próxima posição
			setPage(getPage() + 1); //adiciona uma página em falta
		}
	}

	//Nunca passar o valor da primeira linha do input.txt
	if(getHead() >= getFrame())
		setHead(0);
	
	if(searchNumber(value) == false){
		//Posição recebe o valor da linha do input.txt
		_buffer[_head] = value;
		//Vai para a próxima posição
		setHead(getHead() + 1);
		//Incrementa na paginação
		setPage(getPage() + 1);
	}

}