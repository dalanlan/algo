/*
LintCode 445: Cosine Similarity 
*/



class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        long ab = 0;
        long as = 0;
        long bs = 0;
        
        for(int i=0; i<A.size(); i++) {
            ab += A[i]*B[i];
            as += A[i]*A[i];
            bs += B[i]*B[i];
        }
        if(as == 0 || bs == 0) {
            return 2.0000;
        }
        else {
            return (double)(ab/(sqrt(as)*sqrt(bs)));
        }
    }
};
