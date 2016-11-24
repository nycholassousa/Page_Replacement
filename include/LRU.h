#ifndef LRU_h_
#define LRU_h_

#include "PageReplacement.h"

using namespace std;
class LRU: public PageReplacement{
	public:
		void start(int value);
};

#endif