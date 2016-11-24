#ifndef OTM_h_
#define OTM_h_

#include "PageReplacement.h"

class OTM: public PageReplacement{
	private:
		std::vector<int> _otmBuffer;
		
	public:
		void start(int value);
		void future();
};

#endif