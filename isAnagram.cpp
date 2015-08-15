class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mymap;
        
        int pos = 0;
        while(pos <s.length())
        {
            if(mymap.find(s[pos]) == mymap.end())
            {
                mymap[s[pos]] = 1;
            }
            else
                mymap[s[pos]]++;
        
            pos++;
        }
        pos = 0;
        while(pos<t.length())
        {
            if(mymap.find(t[pos]) != mymap.end())
                mymap[t[pos]]--;
            else
                return false;
                
            pos++;
        }
        for(auto&x: mymap)
        {
            if(x.second != 0)
                return false;
        }
        return true;
        
        
    }
};