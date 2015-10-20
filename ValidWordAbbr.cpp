    multimap<string,string> myMap;
    string makeAbbr(string str) {
        int length = str.length();
        if(length <=2)
            return str;

        
        string res = str[0]+to_string(length-2)+str[length-1];
        return res;
        
    }
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i=0;i<dictionary.size();i++) {
            myMap.insert(make_pair(makeAbbr(dictionary[i]), dictionary[i]));
        }
    }

    bool isUnique(string word) {
        string mapRes = makeAbbr(word);
        int count = myMap.count(mapRes);
        if ( count == 0 || (count == 1 && myMap.find(mapRes)->second == word))
            return true;
        return false;  
        
    }