/*
重载运算符的函数一般格式如下：
    函数类型 operator 运算符名称 (形参表列)
    {
        // 对运算符的重载处理
    }


*/



class A 
{
	public:
	// construction function
	A(int d):data(d){}

    // member function
	A operator+ (A&);
	A operator- (A&);
	A operator* (A&);
	A operator/ (A&);
   
    // friend function
    friend A operator + (A&, A&);
    friend A operator - (A&, A&);
    friend A operator * (A&, A&);
    friend A operator / (A&, A&);

    private:
    int data;

};

A A::operator+(A &a) {
	return A(data + a.data);
}

A operator+(A &a1, A &a2) {
	return A(a1.data+a2.data);
}

void main(){
	A a1(1), a2(2), a3(3);

	a1 = a2+a3;
	a1 = a2.operator+(a3);
}


// only member function
A& operator = (const A& );
char operator [] (int i);
const char* operator() ();

// only friend function
friend inline ostream &operator << (ostream&, A&);
friend inline istream &operator >> (istream&, A&);
