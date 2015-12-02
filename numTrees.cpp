// Unique Binary Search Trees

// Catalan Number: https://en.wikipedia.org/wiki/Catalan_number

/*
 Explanation:
 https://www.quora.com/Given-n-how-many-structurally-unique-BSTs-binary-search-trees-that-store-values-1-to-n-are-there

 C(n) = C(0)*C(n-1) + C(1)*C(n-2) + ... + C(n-1)*C(0)
 hence C(n)=Sum(C(i-1)*(n-i)), i=0,...,n-1
 */
 


 int numTrees(int n) {
        int *num = new int[n+1];
        for(int i = 0; i< n+1; i++) {
            num[i] = 0;
        }
        num[0] = 1;
        
        for(int i=1; i<=n;i++) {
            for(int j=0; j <= n-1; j++) {
                num[i] += num[j]*num[i-1-j];
            }
        }
        return num[n];
    }