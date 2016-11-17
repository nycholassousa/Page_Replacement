#ifndef OTM_h_
#define OTM_h_

#include "PageReplacement.h"

class OTM: public PageReplacement{
	private:
		std::vector<int> _heap;
		int _verify;
		
	public:
		void init(int value);
		void lookingToFuture();

		int higherDistance(int distance) const;
		int findPosition(int value) const;
		
		int higherThan(std::vector<int> values);		
};

#endif