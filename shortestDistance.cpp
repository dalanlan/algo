// Shortest Word Distance

int shortestDistance(vector<string>& words, string word1, string word2) {
	if(words.size() == 0 || word1.length() == 0 || word2.length() == 0)
		return INT_MAX; 
	vector<int> word1Index;
	vector<int> word2Index;

	for(int i = 0; i < words.size(); i++) {
		if(words[i] == word1)
			word1Index.push_back(i);
		if(words[i] == word2)
			word2Index.push_back(i);
	}

	int res = INT_MAX, midRes;
	for(int i = 0; i < word1Index.size(); i++) 
		for(int j = 0; j < word2Index.size(); j++) {
			midRes = abs(word1Index[i] - word2Index[j]);
			if( midRes < res)
				res = midRes;
		}
	return res;

}