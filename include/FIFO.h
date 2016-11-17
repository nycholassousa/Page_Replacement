#ifndef FIFO_h_
#define FIFO_h_

#include "PageReplacement.h"

class FIFO: public PageReplacement{
	public:
		void init(int value);
};

#endif