
/*
Leetcode: peeking iterator
https://leetcode.com/problems/peeking-iterator/
*/

// copy constructor 
// like cheating, sort of 
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
    }

    int peek()
    {
        return Iterator(*this).next();
    }

    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }


   // solution 2:
  // use a int to cache the value 
  // of next iterator

  // Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


// nex is like a cache
class PeekingIterator : public Iterator {
private:
    int nex;
    int has_next=false;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if(Iterator::hasNext()) {
	        has_next = true;
	        nex = Iterator::next();
	    }
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    return nex;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int tmp = nex;
	    has_next = Iterator::hasNext();
	    if(has_next) {
	        nex = Iterator::next();
	    }
	    return tmp;
	}

	bool hasNext() const {
	    return has_next;
	}
};