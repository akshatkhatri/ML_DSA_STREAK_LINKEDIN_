// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) 
    {
        stack<string>st;
        int i = s.size() - 1;
        
        while(i >= 0)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                string str(1, s[i]);
                st.push(str);
            }
            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                
                string con = '(' + t1 + s[i] + t2 + ')';
                st.push(con);
            }
            
            i--;
        }
        
        return st.top();
    }
};