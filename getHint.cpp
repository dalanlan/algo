// Bulls and Cows

string getHint(string secret, string guess) {
	int nums[10];
	memset(nums, 0, sizeof(int)*10);
	char s, g;
	int bulls=0, cows=0;
	for(int i=0; i< secret.length();i++) {
		s = secret[i]-'0';
		g = guess[i]-'0';

		if(s == g) {
			bulls++;
		}
		else {
			if(nums[s]>0) cows++;
			if(nums[g]<0) cows++;

			nums[s]--;
			nums[g]++;

		}
	}
	return to_string(bulls)+"A"+to_string(cows)+"B";
}