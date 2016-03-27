
/*
Cracking the code interview: use a single array to implement three stacks

*/
int stackSize = 300;
// array 
vector<int> buffer(stackSize*3, 0);
vector<int> pointer(3, 0);

void push (int stackNum, int val) {
	int index = stackNum*stackSize + pointer[stackNum++]+1;
	buffer[index] = val;
}

void pop(int stackNum) {
	int index = stackNum*stackSize+pointer[stackNum];
	// int res = buffer[index];
	buffer[index] = 0;
	pointer[stackNum]--;
	//return res;
}

int top(int stackNum) {
	int index = stackNum*stackSize + pointer[stackNum];
	return buffer[index];
}

bool isEmpty(int stackNum) {
	return pointer[stackNum] == 0;
}