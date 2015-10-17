// Word pattern II

bool wordPattern(string &pattern, int i, string &str, int j, unordered_map<char,string>& myMap, unordered_set<string>& mySet){
	if(i == pattern.length() && j == str.length()) return true;
	if(i == pattern.length() || j == str.length()) return false;

	char patCur = pattern[i];
	if(myMap.find(patCur) != myMap.end()) {
		string strCur = myMap[patCur];

        int pos = strCur.length();
        if(strCur != str.substr(j,pos))
            return false;
            
		return wordPattern(pattern,i+1,str,j+pos,myMap,mySet);
	}

	for(int pos = j; pos < str.length(); pos++) {
		string strCur = str.substr(j, pos-j+1);
		if(mySet.find(strCur) != mySet.end())
			continue;
		myMap[patCur] = strCur;
		mySet.insert(strCur);

		if(wordPattern(pattern, i+1, str, pos+1, myMap, mySet))
			return true;
		myMap.erase(patCur);
		mySet.erase(strCur);
	}

	return false;
	 
}


bool wordPatternMatch(string pattern, string str) {
	unordered_map<char,string> myMap;
	unordered_set<string> mySet;

	return wordPattern(pattern,0,str,0,myMap,mySet);