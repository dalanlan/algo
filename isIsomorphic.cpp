
bool isIsomorphic(string s, string t)
{
	unordered_map<char,char> mp;
	unordered_map<char,int> flag;

	for(int i =0;i<s.length();i++)
	{
		if(mp.find(s[i]) == mp.end())
		{
			if(flag.find(t[i]) == flag.end())
			{
				mp[s[i]] = t[i];
				flag[t[i]] = 1;
			}
			else
				return false;	
		}	
		else
		{
			if(mp[s[i]] != t[i])
				return false;
		}
	}
	return true;
}