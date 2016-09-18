/*
Lintcode: reverse pairs
http://www.lintcode.com/zh-cn/problem/reverse-pairs/

在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。给你一个数组，求出这个数组中逆序对的总数。
概括：如果a[i] > a[j] 且 i < j， a[i] 和 a[j] 构成一个逆序对。

*/

// solution 1 : 
// dont not allocate space every time
// use a fixed array 
class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long mergeSort(vector<int>& A, vector<int>& tmp, int lo, int hi) {
        if(hi <= lo) {
            return 0;
        }
        int mid = (lo+hi)/2;
        long long sum = 0;
        sum += mergeSort(A, tmp, lo, mid);
        sum += mergeSort(A, tmp, mid+1, hi);
        sum += merge(A, tmp, lo, mid, hi);
        return sum;

    }

    long long merge(vector<int>& A, vector<int>& tmp, int lo, int mid, int hi) {
        int left = lo;
        int right = mid+1;

        int i=lo;
        long long sum = 0;

        while(left <= mid && right<=hi) {
            if(A[left] <= A[right]) {
                tmp[i++] = A[left++];
            }
            else {
                tmp[i++] = A[right++];
                sum += mid-left+1;
            }
        }
        while(left <= mid) {
            tmp[i++] = A[left++];
        }

        while(right <= hi) {
            tmp[i++] = A[right++];
        }

        for(int k=lo; k<=hi; k++) {
            A[k] = tmp[k];
        }
        return sum;
    }


    long long reversePairs(vector<int>& A) {
        vector<int> tmp(A.size(), 0);
        return mergeSort(A, tmp, 0, A.size()-1);
    }
};



    // solution 2: borrow the idea from
    // http://www.cnblogs.com/grandyang/p/5434414.html
    long long reversePairs(vector<int>& A) {
        vector<int> tmp;
        int cnt = 0;
        
        for(int i=A.size()-1; i>=0; i--) {
            int d = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), A[i]));
            cnt+=d;
            tmp.insert(tmp.begin()+d, A[i]);
        }
        return cnt;
    }


    // solution 1s:
    long long merge(vector<int>&A, vector<int>& tmp, int lo, int hi) {
        if(lo >= hi) {
            return 0;
        }
        int mid = ((lo+hi)>>1);
        long long left = merge(A, tmp, lo, mid);
        long long right = merge(A, tmp, mid+1, hi);
        
        long long mr = 0;
        int i=lo, j=mid+1;
        int k=lo;
        while(i<=mid && j<=hi) {
            if(A[i] <= A[j]) {
                tmp[k++] = A[i++];
            }
            else {
                mr += mid-i+1;
                tmp[k++] = A[j++];
            }
        }
        while(i<=mid) {
            tmp[k++] = A[i++];
        }
        while(j<=hi) {
            tmp[k++] = A[j++];
        }
        for(int p=lo; p<=hi; p++) {
            A[p] = tmp[p];
        }
        return left + right + mr;
        
    }
    long long reversePairs(vector<int>& A) { 
        vector<int> tmp(A.size(), 0);
        return merge(A, tmp, 0, A.size()-1);
    }