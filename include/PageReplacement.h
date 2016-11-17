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
		int getBufferValue(int value) const;
		int getFrameSize() const;
		int getPaging() const;
		int getHead() const;

		void setBuffer(std::vector<int> out_buffer);
		void setFrameSize(int value);
		void setPaging(int value);
		void setHead(int value);
		
		bool inMemory(int value) const;
		int whatNumberInMemory(int value) const;

		void incrementPaging();
		void incrementPaging(bool test);
		void incrementHead();
		void incrementHeadNPage();

		void decrementHead();

};
#endif