/*

133 Longest word
http://www.lintcode.com/zh-cn/problem/longest-words/


Given a dictionary, please find the longest
word.
Two-pass solution is kinda trivial, could you 
find one-pass?
*/


/**
 * @param dictionary: a vector of strings
 * @return: a vector of strings
 */

vector<string> longestWords(vector<string> &dictionary) {
    unordered_map<int, vector<string> > res;

    int max=0;
    int len;
    for(int i=0;i<dictionary.size(); i++) {
    	len = dictionary[i].size();
    	res[len].push_back(dictionary[i]);
    	if(max < len) {
    		max = len;
    	}
    }
    return res[max];
     
}
