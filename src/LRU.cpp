#include "../include/LRU.h"

void LRU::start(int value){
	if(_buffer.size() < getFrame()){ //Se o buffer for menor que o quadro
		if(searchNumber(value) == false){
			_buffer.push_back(value); //valor da linha lido
			//vai para a próxima posição
			setHead(getHead() + 1);
			//Adiciona uma página em falta 
			setPage(getPage() + 1);
		}
	}

	else {
		//O valor do cabeçalho deve ser sempre igual a primeira linha
		if(getHead() >= getFrame())
			setHead(0);

		/** Caso não ache o valor na página, 
			significa que ele não é muito usado **/
		if(searchNumber(value) == false){
			//Incrementa uma página em falta
			setPage(getPage() + 1);
			//Valor recebe qual será o próximo cabeçalho
			int old = getHead() + 1;
			//Caso o cabeçalho seja maior/igual ao tamanho do quadro
			if(old >= getFrame())
				//Cabeçalho irá resetar
				old = 0;
			//Buffer no cabeçalho da posição resetada recebe o valor do input
			_buffer[old] = value;
		}

		//Incremento no cabeçalho
		setHead(getHead() + 1);
	}
}