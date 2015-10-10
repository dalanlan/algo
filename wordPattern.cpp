// Using a trick from compareVersion
// split function :stringstream 
vector<string> split(string str, char delimeter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;
    
    while(getline(ss,tok,delimeter)) {
        internal.push_back(tok);
    }
   
    return internal;
}

bool wordPattern(string pattern, string str) {
    map<string,char> myMap;
    vector<string> res = split(str,' ');
    map<string,char>::iterator it;
    
    if(pattern.length() != res.size())
        return false;
        
    for(int i=0;i<pattern.length();i++) {
        it = myMap.find(res[i]);
        if(it == myMap.end()) {
            myMap[res[i]] = pattern[i];
        }
        else if(it->second != pattern[i]) {
            return false;
        }
    }
    
    map<char,string> myMap2;
    map<char,string>::iterator it2;
    
    for(int i=0;i<res.size();i++) {
        it2 = myMap2.find(pattern[i]);
        if(it2 == myMap2.end()) {
            myMap2[pattern[i]] = res[i];
        }
        else if(it2->second != res[i]) {
            return false;
        }
    }
    return true;
}