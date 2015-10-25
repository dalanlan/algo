// Shortest Word Distance II

unordered_map<string,vector<int>> myMap;
map<string,vector<int>> iterator;
WordDistance(vector<string>& words) {
	for(int i=0;i<words.size();i++) {
		myMap[words[i]].push_back(i);
	}
}

int shortest(string word1, string word2) {
	vector<int> word1Index = myMap[word1];
	vector<int> word2Index = myMap[word2];

	int res = INT_MAX, midRes;

	for(int i = 0; i < word1Index.size(); i++) 
		for(int j = 0; j < word2Index.size(); j++)
		{
			midRes = abs(word1Index[i] - word2Index[j]);
			if(midRes < res)
				res = midRes;

		}
	return res;
}
