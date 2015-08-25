//solution1: A trivial one
int addDigits(int num) {
    int res = 0;
    while(num!=0)
    {
    
        res+=(num%10);
        num/=10;
    }
    while(res >= 10)
    {
        num=res;
        res=0;
        while(num!=0)
        {
        
            res+=(num%10);
            num/=10;
        }
    }
    return res;
        
}


//solution2: Congruence formula
int addDigits(int num){
    return 1+(num-1)%9;
}