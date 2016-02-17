
/*
LintCode: hash function
http://www.lintcode.com/zh-cn/problem/hash-function/
*/


/**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */

int hashCode(string key, int HASH_SIZE) {
	long res=0;
	int base = 1;
	for(int i=key.length()-1; i>=0; i--) {
		res += modMultiply(key[i],  base, HASH_SIZE);
		res %= HASH_SIZE;
		base *= modMultiply(base, 33, HASH_SIZE);
	}
}

long modMultiply(long a, long b, int HASH_SIZE) {
	return a*b%HASH_SIZE;
}