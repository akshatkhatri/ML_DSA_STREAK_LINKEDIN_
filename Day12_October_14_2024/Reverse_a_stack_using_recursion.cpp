//User function Template for C++

class Solution{
    
public:
    void insert_at_bottom(stack<int>&st,int curr)
    {
        if(st.empty())
        {
            st.push(curr);
            return;
        }
        
        int st_curr = st.top();
        st.pop();
        
        insert_at_bottom(st,curr);
        st.push(st_curr);
    }
public:
    void Reverse(stack<int> &st){
        if(st.empty())
        {
            return;
        }
        
        int curr = st.top();
        st.pop();
        
        Reverse(st);
        
        insert_at_bottom(st,curr);
    }
};