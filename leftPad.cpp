
/*
lintcode: left pad 
http://www.lintcode.com/zh-cn/problem/left-pad/

*/
static string leftPad(string& originalStr, int size, char padChar = ' ') {
        return originalStr.size() >= size?originalStr:string(size-originalStr.size(),padChar)+originalStr;
    }