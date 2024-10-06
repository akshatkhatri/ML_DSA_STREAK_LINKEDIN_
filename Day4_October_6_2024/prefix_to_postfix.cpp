// User function Template for C++

class Solution {
  public:
    string preToPost(string s) 
    {
        stack<string>st;
        int i = s.size() - 1;
        
        while(i >= 0)
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
                
                st.push(t1 + t2 + s[i]);
            }
            
            i--;
        }
        
        return st.top();
    }
};