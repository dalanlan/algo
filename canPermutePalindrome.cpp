bool canPermutePalindrome(string s) {
	sort(s.begin(),s.end());

	int odd = 0;


	int pos1=0,pos2;

	while(pos1<s.length())
	{
		pos2=pos1;
		while(pos2<s.length() && s[pos2+1]== s[pos1])
		{
			pos2++;
		}
		if((pos2-pos1+1)%2 == 1)
			odd++;

		pos1 = pos2+1;
		if(odd>1)
			return false;

	}

	return true;
}