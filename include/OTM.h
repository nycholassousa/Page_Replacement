#ifndef OTM_h_
#define OTM_h_

#include "PageReplacement.h"

class OTM: public PageReplacement{
	private:
		std::vector<int> _heap;
		
	public:
		void start(int value);
		void lookingToFuture();

		int higherDistance(int value) const;
};

#endif