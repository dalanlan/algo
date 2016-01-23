

/*
LintCode : Rotate string 
http://www.lintcode.com/zh-cn/problem/rotate-string/

*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
     void rotateString(string &str,int offset){
        if(str.length() == 0) {
            return;
        }
        offset %= str.length();
        if(offset == 0) {
            return;
        }
        reverse(str.begin(), str.begin()+str.length()-offset);
        reverse(str.begin()+str.length()-offset, str.end());
        reverse(str.begin(), str.end());
    }
};
  public class Solution {
      /**
       * @param str: an array of char
       * @param offset: an integer
       * @return: nothing
       */
      public void rotateString(char[] str, int offset) {
          // write your code here
          if (str==null || str.length==0) return;
         offset %= str.length;
         if (offset == 0) return;
         reverse(str, 0, str.length-1);
         reverse(str, 0, offset-1);
         reverse(str, offset, str.length-1);
     }
     
     public void reverse(char[] str, int l, int r) {
         
         while (l < r) {
             char temp = str[l];
             str[l] = str[r];
             str[r] = temp;
             l++;
             r--;
         }
     }
 }