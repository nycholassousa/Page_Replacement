#ifndef LRU_h_
#define LRU_h_

#include "PageReplacement.h"

using namespace std;
class LRU: public PageReplacement{
	private:
		std::vector<int> _lruBuffer;

	public:
		void start(int value);
};

#endif