
/*
LintCode: sort color II
http://www.lintcode.com/en/problem/sort-colors-ii/
*/

// solution 1: two-pass
// count and set

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        vector<int> count = vector<int> (k, 0);
        // colors 1:colors[0]
        // colors k:colors[k-1]
        for(int i=0; i<colors.size(); i++) {
            count[colors[i]-1]++;
        }
        
        int pos = 0;
        for(int i=0; i<count.size(); i++) {
            int num = count[i];
            int end = pos;
            while(end - pos< num) {
                colors[end] = i+1;
                end++;
            }
            pos = end;
        }
        return;
    }
};

// solution 2: sort
// O(nlogn)

// solution 3: using the idea of sort color
// each we dig up two colors, max & min

void sortColors2(vector<int> & colors, int k) {
        int count = 0;
        int start = 0, end = colors.size()-1;
        
        while(count < k) {
            int MAX = INT_MIN;
            int MIN = INT_MAX;
            
            for(int i=start; i<=end; i++) {
                MAX = max(MAX, colors[i]);
                MIN = min(MIN, colors[i]);
            }
            int left = start;
            int right = end;
            int cur = left;
            
            while(cur <= right) {
                if(colors[cur] == MIN) {
                    swap(colors[cur++], colors[left++]);
                }
                else if(colors[cur] == MAX) {
                    swap(colors[cur], colors[right--]);
                }
                else {
                    cur++;
                }
            }
            count += 2;
            start = left;
            end = right;
        }
        
    }