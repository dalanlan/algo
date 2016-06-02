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

// h index ii
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

// use space to replace time
 int hIndex(vector<int>& citations) {
        int sz = citations.size();
        if(sz == 0) {
            return 0;
        }
        vector<int> count(sz+1, 0);
        for(int i=0; i<sz; i++) {
            if(citations[i]>sz){
                count[sz]++;
            }
            else {
                count[citations[i]]++;
            }
        }
        int sum = 0;
        for(int i=sz; i>=0; i--) {
            sum += count[i];
            if(sum >= i) {
                return i;
            }
        }
        return 0;
    }