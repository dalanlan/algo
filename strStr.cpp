
/*
LintCode: strstr
http://www.lintcode.com/zh-cn/problem/strstr/
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    
    int strStr(const char *source, const char *target) {
        // write your code here
        
       if(source == NULL || target == NULL) {
           return -1;
       }
        int sLen = strlen(source);
        int tLen = strlen(target);
        
        if(sLen == 0 && tLen == 0) {
            return 0;
        }
        for(int i=0; i<sLen; i++) {
            int j=0;
            for(j=0; j<tLen; j++) {
                if(source[i+j] != target[j]) {
                    break;
                }
            }
            if(j==tLen) {
                return i;
            }
        }
        return -1;
    }
};
