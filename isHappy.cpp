//Happy Number

// LintCode 488 

#include <iostream>
#include <unordered_set>
using namespace std;

int countDigSquareSum(int n) {
        int sum = 0;
        while(n != 0) {
            int a = n%10;
            sum += a*a;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> cache;
        
        while(n > 1) {
            n = countDigSquareSum(n);
            if(n == 1) {
                return true;
            }
            else {
                if(cache.find(n) == cache.end()) {
                    cache.insert(n);
                }
                else {
                    return false;
                }
            }
    
        }
        return true;
    }

int main()
{
	cout<<isHappy(19)<<endl;
	return 0;
}