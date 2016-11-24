#include <iostream>
#include <fstream>
#include "../include/FIFO.h"
#include "../include/OTM.h"
#include "../include/LRU.h"

int main(void){
	int fileData; //Responsável pelo dado lido no input.txt
	bool firstTime = true; //Diz se é a primeira linha lida no input.txt

	//Inicializadores das classes
	FIFO *fifo = new FIFO();
	OTM  *otm = new OTM();
	LRU  *lru = new LRU();

	//Arquivo a ser lido
	std::ifstream file("input.txt");

	//Leitura do arquivo
	while(file >> fileData){ 
		//leitura numero por numero
		if (firstTime){ //primeiro número que diz o tamanho da página
			fifo->setFrame(fileData);
			otm->setFrame(fileData);
			lru->setFrame(fileData);

			firstTime = false; //Não é mais a primeira leitura
		} else { //Inicialização de cada algoritmo
			fifo->start(fileData);
			otm->start(fileData);
			lru->start(fileData);
		}
	}

	otm->future();
	
	/** Caso o tamanho do buffer seja igual à quantidade de páginas
		É incrementado uma página no LRU **/
	if(lru->getBuffer().size() == lru->getFrame())
		lru->setPage(lru->getPage() + 1);

	//Impressão da quantidade de páginas
	std::cout << "FIFO " << fifo->getPage() << endl;
	std::cout << "OTM " << otm->getPage() << endl;
	std::cout << "LRU " << lru->getPage() << endl;

	return 0;
}