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

//solution3: 
int addDigits(int num) {
    if(num % 9 == 0 && num != 0) {
        return 9;
    }
    else return (num%9);
}