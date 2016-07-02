
/*
Leetcode: fraction to recurring decimal
https://leetcode.com/problems/fraction-to-recurring-decimal/
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) {
            return "0";
        }
        long n = abs((long)numerator);
        long d = abs((long)denominator);
        string res("");
        if(numerator<0 ^ denominator<0) {
            res+="-";
        }
        res += to_string(n/d);
        
        long _remainder = n % d;
        if(_remainder == 0) {
            return res;
        }
        res+=".";
        unordered_map<long, int> map;
        
        for(;_remainder!=0; _remainder%=d) {
            if(map.count(_remainder) > 0) {
                res.insert(map[_remainder], 1, '(');
                res+=")";
                break;
            }
            map[_remainder]=res.size();
             _remainder *= 10;
            res+=to_string(_remainder/d);
            
           
            
        }
        return res;
       
    }
};


string fractionToDecimal(int numerator, int denominator) {
    long a = abs((long)numerator);
    long b = abs((long)denominator);

    string res("");
    if((numerator > 0) ^ (denominator > 0)) {
        res += "-";
    }

    res += to_string(a/b);
    long remain = a%b;
    if(remain == 0) {
        return res;
    }
    res += ".";
    unordered_map<long,int> map;
    
    for(;remain != 0; remain %= b) {
        if(map.count(remain)) {
            res.insert(res.begin() + map[remain], 1, '(');
            res += ")";
            break;
        }
        map[remain] = res.size();
        remain *= 10;
        res += to_string(remain/b;)
        
    }
    return res;
}


string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0) {
        return "0";
    }
    long a = abs((long)numerator);
    long b = abs((long)denominator);

    string res("");
    if((numerator > 0) ^ (denominator > 0)) {
        res += "-";
    }

    res += to_string(a/b);
    long remain = a%b;
    if(remain == 0) {
        return res;
    }
    res += ".";
    unordered_map<long,int> map;
    
    for(;remain != 0; remain %= b) {
        if(map.count(remain)) {
            res.insert(res.begin() + map[remain], 1, '(');
            res += ")";
            break;
        }
        map[remain] = res.size();
        remain *= 10;
        res += to_string(remain/b);
        
    }
    return res;
}