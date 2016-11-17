#ifndef PageReplacement_h_
#define PageReplacement_h_

#include <vector>

class PageReplacement{
	protected:
		std::vector<int> _buffer;
		int _frame_size;
		int _head;
		int _paging;

	public:

		virtual void init(int value) {};

		std::vector<int> getBuffer() const;
		int getFrameSize() const;
		int getPaging() const;
		int getHead() const;

		void setFrameSize(int value);
		void setHead(int value);
		
		bool inMemory(int value) const;

		void incrementPaging();
		void incrementPaging(bool test);
		void incrementHead();
		void incrementHeadNPage();

};
#endif