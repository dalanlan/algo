
/*
Leetcode: number to words
https://leetcode.com/problems/integer-to-english-words/
*/

class Solution {
public:
    
    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }    
        int i = 0;
        
        string words("");
        while(num > 0) {
            if(num % 1000 !=0) {
                words = helper(num % 1000) + thousands[i] + " " + words;
            }
            num /= 1000;
            i++;
        }
        
        int len = words.length();
        while(len>=0 && words[len-1] == ' ') {
            len--;
        }

        words = words.substr(0, len);
        return words;
    }
    
    string helper(int num) {
        if(num == 0) {
            return "";
        }
        else if(num < 20) {
            return lessThan20[num] + " ";
        }
        else if (num < 100) {
            return tens[num/10] +" " + helper(num % 10);
        }
        else {
            return lessThan20[num/100] +" Hundred " + helper(num%100);
        }
    }
private:
    vector<string> lessThan20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
};