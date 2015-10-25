// Shortest Word Ditance III

int shortestWordDistance(vector<string>& words, string word1, string word2) {
	int res = INT_MAX, midRes;
	if (word1 == word2)
	{
		vector<int> index;
		for(int i = 0; i < words.size();i++) {
			if(words[i] == word1)
				index.push_back(i);
		}

		
		for(int i = 0; i < index.size() - 1;i++){
			midRes = index[i+1] - index[i];
			if (midRes < res)
				res = midRes;
		} 
	}
	else{

	vector<int> word1Index;
	vector<int> word2Index;

	for(int i = 0; i < words.size(); i++) {
		if(words[i] == word1)
			word1Index.push_back(i);
		if(words[i] == word2)
			word2Index.push_back(i);
	}

	for(int i = 0; i < word1Index.size(); i++) 
		for(int j = 0; j < word2Index.size(); j++) {
			midRes = abs(word1Index[i] - word2Index[j]);
			if( midRes < res)
				res = midRes;
		}
	

	}
	return res;
}