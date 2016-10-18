/*
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

#define N 100100
const int alNum = 26;
const int maxN = 100005;
int len;
string str;
int n;
map<string, int> mp;
int dp[maxN][alNum];

int main(){
    cin>>len;
    cin>>str;
    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        mp[s] = 1;
        swap(s[0],s[1]);
        mp[s] = 1;
    }
    dp[0][str[0]-'a'] = 1;
    for(int i = 1; i < len; i++){
        string s;
        s.push_back('a');
        s.push_back(str[i]);
        int maxlen = 1;
        for(int j = 0; j < 26; ++j){
            s[0] = 'a' + j;
            if(mp.find(s) == mp.end()){
                maxlen = max(dp[i - 1][j] + 1, maxlen);
            }
        }
        dp[i][str[i] - 'a'] = maxlen;
        for(int j = 0; j < 26; ++j){
            if(str[i] != ('a' + j)){
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int maxlen = -1;
    for(int j = 0; j < 26; ++j){
        maxlen = max(maxlen, dp[len - 1][j]);
    }
    cout << len - maxlen << endl;
    return 0;
}
*/


#include<iostream>
#include<cmath>
#include<cstdlib>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

#define N 100100
const int alNum = 26;
const int maxN = 100005;
int len;
string str;
int n;
set<string> st;
int dp[maxN][alNum];

int main(){
    cin>>len;
    cin>>str;
    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        st.insert(s);
        swap(s[0],s[1]);
        st.insert(s);
    }
    dp[0][str[0]-'a'] = 1;
    for(int i = 1; i < len; i++){
        string s;
        s.push_back('a');
        s.push_back(str[i]);
        int maxlen = 1;
        for(int j = 0; j < 26; ++j){
            s[0] = 'a' + j;
            if(st.count(s) == 0) {
                maxlen = max(dp[i - 1][j] + 1, maxlen);
            }
        }
        dp[i][str[i] - 'a'] = maxlen;
        for(int j = 0; j < 26; ++j){
            if(str[i] != ('a' + j)){
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int maxlen = -1;
    for(int j = 0; j < 26; ++j){
        maxlen = max(maxlen, dp[len - 1][j]);
    }
    cout << len - maxlen << endl;
    return 0;
}