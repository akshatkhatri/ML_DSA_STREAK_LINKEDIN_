class Solution {
public:
    void print_array(vector<int>&temp)
    {
        for(int ele : temp)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    void generate_combinations(vector<vector<int>>&res, vector<int>&candidates, vector<int>&temp, int i, int n, int target,int sum)
    {
         if(i == n)
        {
            return;
        }

        if(sum == target)
        {
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        if(sum + candidates[i] > target)
        {
            return;
        }

        temp.push_back(candidates[i]);
        sum += candidates[i];

        generate_combinations(res,candidates,temp,i,n,target,sum);
        
        generate_combinations(res,candidates,temp,i+1,n,target,sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int n = candidates.size();

        generate_combinations(res,candidates,temp,0,n,target,0);
        return res;
    }
};