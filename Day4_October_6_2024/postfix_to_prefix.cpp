// User function Template for C++

class Solution {
  public:
    string postToPre(string s) 
    {
        int i = 0;
        stack<string>st;
        
        while(i < s.size())
        {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                string res;
                res += s[i];
                st.push(res);
            }
            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                
                st.push(s[i] + t2 + t1);
            }
            
            i++;
        }
        
        return st.top();
    }
};