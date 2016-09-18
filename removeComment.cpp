/*
This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

You can also change the default language your pads are created with
in your account settings: https://coderpad.io/profile

Enjoy your interview!
*/
public class Comment {
    // "this is a comment"
    void comment() {
        String s0 = "this is not a comment";
        String s1 = "// this is not a comment";
        String s4 = "'";
        String s5 = "\\"";
        char c0 = '/';
        char c1 = '"';
        char c2 = '\\''; 
    }
};


/*
string nextStash(string &s) {
  size_t pos = s.find("/");
  if(pos != std::string::npos) {
      string ret = s.substr(0, pos);
      s = s.substr(pos);
  }
}
*/



//comment: // 0
// plain code:  1
// string: " 2



string removeComments(string s) {
    string res("");
    if(s.empty()) {
      return res;
    }
    
    int flag=1;
    
    int start = 0, end = 0;
    
    while(end <s.size()) {
      while(s[end] != '/' && flag) {
        end++; 
      }
      
      if(end + 1<s.size() && s[end+1] == '/') {
          flag = 0;
          res += s.substr(start, end-start);
      }
      
      while(!flag && end < s.size() && s[end] != '\n') {
          end++;
      }
      if(end < s.size() && s[end] == '\n') {
        flag = 1;
        start = end+1;
        end = start;
      }
    }
    
    if(flag) res += s.substr(start, end-start);
    
    return res;
    
    
    
}