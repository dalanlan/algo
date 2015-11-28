// H-index

// wiki
  int hIndex(vector<int>& citations) {
	sort(citations.begin(), citations.end(), greater<int>());
	
	for(int i=0; i< citations.size(); i++) {
		if(i >= citations[i]) {
			return i;
		}
		
	}
	return citations.size();
}

// from description
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());

    int sz = citations.size();
    for(int i=0; i<sz; i++) {
        if(sz - i <= citations[i]){
            return sz-i;
        }
    }
    return 0;
}