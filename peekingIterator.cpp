
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


class PeekingIterator : public Iterator {

private:
    int nex;
public:
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	    
	    if(Iterator::hasNext()) {
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
	    int res = nex;
	    nex = Iterator::hasNext()?Iterator::next():INT_MAX;
	    return res;
	}

	bool hasNext() const {
	    return nex != INT_MAX;
	}
};