
/*
LintCode 366: Fibonacci
*/

    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    
   
    int fibonacci(int n) {
        // write your code here
        vector<int> table (n+1, 0);
          
        table[0] = 0;
        table[1] = 1;
        for(int i=2; i<n+1; i++) {
            table[i] = table[i-1] + table[i-2];
        }
        return table[n-1];
        
    }