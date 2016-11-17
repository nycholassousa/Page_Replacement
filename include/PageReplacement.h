#ifndef PageReplacement_h_
#define PageReplacement_h_

#include <vector>

class PageReplacement{
	protected:
		std::vector<int> _buffer;
		int _frameSize;
		int _head;
		int _page;

	public:

		virtual void init(int value) {};

		std::vector<int> getBuffer() const;
		int getFrameSize() const;
		int getPage() const;
		int getHead() const;

		void setFrameSize(int frameSize);
		void setHead(int head);
		void setPage(int page);
		
		bool searchNumber(int number) const;

};
#endif