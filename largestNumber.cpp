
/*
LintCode: largest number
*/
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
 static bool compare(int a, int b) {
        //return to_string(a) > to_string(b);
        string aStr = to_string(a);
        string bStr = to_string(b);
        
        return (aStr+bStr)>(bStr+aStr);
}

    string largestNumber(vector<int> &num) {
        // write your code here
        // dict sort 
        //cout<<compare(5, 13)<<endl;
        sort(num.begin(), num.end(), compare);
     
        string res;
        for(int i=0; i<num.size(); i++) {
            res += to_string(num[i]);
        }
        int i=res.length()-1;
        while(res[i] == '0' && i>=0) {
            i--;
        }
        if(i==-1){
            return "0";
        }
        //res = res.substr()
        return res;
    }
};