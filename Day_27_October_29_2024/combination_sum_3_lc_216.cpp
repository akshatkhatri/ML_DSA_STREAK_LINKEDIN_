class Solution {
public:

    void generate(vector<vector<int>>&res,vector<int>&ans,int i, int sum, int curr_ele,int target,int n)
    {
        
        if(i == n)
        {
            if(sum == target)
            {
                res.push_back(ans);
            }
            return;
        }

        if(curr_ele >= 10 || sum > target)
        {
            return;
        }


        sum += curr_ele;
        ans.push_back(curr_ele);
        generate(res,ans,i+1,sum,curr_ele+1,target,n);

        ans.pop_back();
        sum -= curr_ele;
        generate(res,ans,i,sum,curr_ele+1,target,n);
    }

    vector<vector<int>> combinationSum3(int n, int target) 
    {
        vector<vector<int>>res;
        vector<int>ans;

        generate(res,ans,0,0,1,target,n);// i = 0 and sum = 0 and current_ele = 1
        return res;
    }
};