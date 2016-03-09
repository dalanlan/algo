
/*
LintCode: string to integer ii
http://www.lintcode.com/zh-cn/problem/string-to-integer-ii/
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
            int atoi(string str) {

    	int len = str.length();
    	if(len == 0) {
    		//illegal
    		return 0;
    	}

    	// cut out the leading and tailing white space 
    	int start = 0;
    	while(start < len && str[start] != '+' && str[start] != '-' && (str[start] > '9' || str[start] < '0')) {
    		start++;
    	}
    	int end = len-1;
    	while(end >=0 && (str[end] > '9' || str[end] < '0')){
    		end--;
    	}
    	if(start > end) {
    		return 0;
    	}

    	

    	int sign = 1;
    	int index = start;
    	if(str[index] == '+') {
    		index++;
    	}
    	else if(str[index] == '-') {
    		sign = -1;
    		index++;
    	}
    	long res = 0;
    	for(;index <= end; index++) {
    		if(str[index] > '9' || str[index] < '0') {
    			break;
    		}
    		if(str[index] == '.') {
    		    break;
    		}
    		res = res*10+str[index]-'0';
    		if(res > INT_MAX) {
    			break;
    		}
    	}
    	if(index< len && str[index] == '.') {
        	index++;
        	if(index<len) {
        	    if(str[index] > '9' || str[index] < '0') {
        	        return 0;
        	    }
        	    if(str[index] >= '5') {
        	        res++;
        	    }
        	    
        	}
    	}
    	
    	if(res*sign >= INT_MAX) {
    		return INT_MAX;
    	}
    	if(res*sign <= INT_MIN) {
    		return INT_MIN;
    	}
    	return (int)res*sign;
    }
};