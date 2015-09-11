// Binary search
// Recursive
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
int binarySearch(int left, int right)
{
    if(right-left>1)
    {
        long pivot = left+((right-left)>>1); //fix overflow issue
        cout<<pivot<<endl;
        if(isBadVersion(pivot))
            return binarySearch(left,pivot);
            
        else
            return binarySearch(pivot,right);
    }
    else if(isBadVersion(left))
        return left;
    else if(isBadVersion(right))
        return right;
        
    
}
//binary search
int firstBadVersion(int n) {
   return binarySearch(1,n);
}


// Solution 2
// iteration 
int firstBadVersion(int n)
{
	int left = 1, right = n;

	while(right - left > 1) 
	{
		int pivot = left + ((right - left)>>1); 
		if(isBadVersion(pivot)) 
			right = pivot; 
		else
			left = pivot; 
	}
	if(isBadVersion(left))
		return left;
	else if	(isBadVersion)
		return right;
}