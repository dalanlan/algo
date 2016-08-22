
/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?


http://www.cnblogs.com/jcliBlogger/p/4748554.html
https://discuss.leetcode.com/topic/21999/1-4-lines-python-ruby-c-c-java?show=53180
*/
bool canPermutePalindrome(string s) {
	bitset<256> b;
	for(char c:s) {
		b.flip(c);
	}
	return b.count()<2;
}

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