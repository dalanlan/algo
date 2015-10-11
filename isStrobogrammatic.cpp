bool isStrobogrammatic(string num) {
    map<char,char> myMap;
    myMap['1']='1';
    myMap['6']='9';
    myMap['8']='8';
    myMap['9']='6';
    myMap['0']='0';
    map<char,char>::iterator it;
    
    
    for(int i=0;i<num.length();i++) {
        it = myMap.find(num[i]);
        if(it == myMap.end())
            return false;
        else if(it->second != num[num.length()-1-i])
            return false;
    }
    return true;
}