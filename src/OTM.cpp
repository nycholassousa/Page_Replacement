#include "../include/OTM.h"
#include <iostream>

/** Insere todos os valores do input.txt num buffer auxiliar
	(com exceção da primeira linha) **/
void OTM::start(int value){
	_otmBuffer.push_back(value);
}

void OTM::future(){
	int lastPosition;

	/** roda enquanto o tamanho do buffer principal for menor
		que o tamanho do quadro **/
	for (int i = 0; _buffer.size() < getFrame(); i++){
		
		if(i == 0)
			setPage(getPage() - 1);

		//buffer coloca no final o primeiro do auxiliar
		_buffer.push_back(_otmBuffer[i]);
		//incremento de página
		setPage(getPage() + 1);
		lastPosition = i; //salva a último i (usado no proximo loop)
	}

	/** Roda depois da ultima posição do buffer principal
		Enquanto nao lê o buffer auxiliar completamente **/
	for(int i = lastPosition; i < _otmBuffer.size(); i++){
		if(searchNumber(_otmBuffer[i]) == false){
			_buffer[0] = _otmBuffer[i];
			setPage(getPage() + 1);
		}
	}

}