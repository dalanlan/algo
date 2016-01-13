
/*

LintCode 422: length of last word

Given a string, within which we could have 
characters and blank. 
Please return the length of last word, 0 if 
it's not exist.

*/

/**
 * @param s A string
 * @return the length of last word
 */
int lengthOfLastWord(string& s) {
    // Write your code here

    int i=s.length()-1;
    while(i >= 0 && s[i] == ' ') {
    	i--;
    }
    if(i < 0) {
    	return 0;
    }
    int j = i;
    while(j-1 >= 0 && s[j-1] != ' ') {
    	j--;
    }
    return i-j+1;
}