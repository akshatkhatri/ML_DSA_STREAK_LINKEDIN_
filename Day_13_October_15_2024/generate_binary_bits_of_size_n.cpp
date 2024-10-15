//User function Template for C++

class Solution{
    
public:
    void add_answer(vector<int>&arr,vector<string>&ans)
    {
        string s = "";
        char ch = '0';
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(ch == '1' && arr[i] == 1)
            return;
            
            ch = (arr[i] + '0');
            s.push_back(ch);
        }
        
        ans.push_back(s);
    }

    
public:
    void generate(vector<int>&arr,int n,int i,vector<string>&ans)
    {
        if(i == n)
        {
            add_answer(arr,ans);
            return;
        }
        
        arr[i] = 0;
        generate(arr, n, i+1, ans);
        
        arr[i] = 1;
        generate(arr, n, i+1,ans);
    }
    
public:
    vector<string> generateBinaryStrings(int num)
    {
        vector<string>ans;
        vector<int>arr(num);
        generate(arr,num,0,ans);
        
        return ans;
    }
};