

//Length of Last Word

    int lengthOfLastWord(string s) {
        
        if(s.length() == 0)
		return 0;

	int i = s.length()-1;
	
	while(i>=0 && s[i] == ' ')
		i--;
	if(i<0)
	    return 0; 
	    
	int j=i;
	while(s[j] != ' ' && j>=0)
		j--;
	return (i-j);
    }