class Solution {

public:
    void generate(vector<string>&result,string &ans, int n, int i,int open_count,int close_count)
    {

        if(i == n*2)
        {
            if(open_count == close_count)
            {
                result.push_back(ans);
            }
            return;
        }
        ans[i] = '(';
        generate(result,ans,n,i+1,open_count + 1,close_count);

        if(close_count < open_count)
        {
            ans[i] = ')';
            generate(result,ans,n,i+1,open_count,close_count + 1);
        }
    }


public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string ans((n*2), ' ');
        generate(result,ans,n,0,0,0);

        return result;
    }
};