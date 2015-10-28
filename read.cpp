// Read N characters Given Read4

System.arraycopy(/*src*/,/*srcPos*/,/*dest*/,/*destPos*/,/*length*/);

int read(char *buf, int n) {
    for(int i = 0; i < n; i+=4) {
        char[] tmp = new char[4];
        int len = read4(tmp);
        System.arraycopy(tmp, 0, buf, i, Math.min(len,n-i));
        if(len < 4) return Math.min(i+len, n);
    }
    return n;
}