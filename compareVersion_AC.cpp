// Compare Version Numbers

// Incorrect sol 1 : string to double
// 'cause we would treat 1.10 as 1.1, which is absolutely wrong.

int compareVersion(string version1, string version2)
{
	double v1, v2;
	v1 = atof(version1.c_str());
	v2 = atof(version2.c_str());
	if( v1>v2 )
		return 1;
	else if (v1 == v2)
		return 0;
	else
		return -1;
}

// -------------------------------------------------

// Sol1
// Extra func : string split
vector<string> split(string str, char delimiter){
	vector<string> internal;
	stringstream ss(str);
	string tok;

	while(getline(ss,tok,delimiter)){
		internal.push_back(tok);
	}
	return internal;
}

// string to int
// stoi(str);
// str is a std::string

int compareVersion(string version1, string version2)
{
	vector<string> v1tmp = split(version1,'.'); // char should use ''
	vector<string> v2tmp = split(version2,'.');

	int size1 = v1tmp.size();
	int size2 = v2tmp.size();

	for(int i=0;i<size1 || i<size2;i++)
	{
		if(i<size1 && i<size2)
		{
			int v1ele = stoi(v1tmp[i]);
			int v2ele = stoi(v2tmp[i]);
			if(v1ele > v2ele)
				return 1;
			else if(v1ele<v2ele)
				return -1;
		}
		else if(i < size1)
		{
			int v1ele = stoi(v1tmp[i]);
			if (v1ele != 0)
				return 1;
		} 
		else if(i < size2)
		{
			int v2ele = stoi(v2tmp[i]);
			if(v2ele != 0)
				return -1;
		}

	}
	return 0;
}