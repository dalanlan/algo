/*
LintCode 212: Replace space

设计一种方法，将一个字符串中的所有空格替换成 %20。
你可以假设该字符串有足够的空间来加入新的字符，且你得到的是“真实的”字符长度。

你的程序还需要返回被替换后的字符串的长度。

*/

/**
 * @param string: An array of Char
 * @param length: The true length of the string
 * @return: The true length of new string
 */
int replaceBlank(char string[], int length) {
	if(length == 0) {
		return 0;
	}
	int count = 0;
	for(int i=0; i<length; i++) {
		if(string[i] == ' ') {
			count++;
		}
	}
	int len = 2*count + length; // could be zero
	int pos = len;
	for(int i=length; i >= 0; i--) {
		if(string[i] != ' ') {
			string[pos] = string[i];
			pos--;
		}
		else {
			string[pos] = '0';
			string[pos-1] = '2';
			string[pos-2] = '%';
			pos-=3;
		}
	}
	return len;

}