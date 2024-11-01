class Solution
{
public:
    void generate_combinations(vector<vector<int>> &res, vector<int> &candidates, vector<int> &temp,int i, int target)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }

        if (i == candidates.size() || target < 0)
        {
            return;
        }

        temp.push_back(candidates[i]);
        generate_combinations(res, candidates, temp, i + 1, target - candidates[i]);
        temp.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
        {
            i++;
        }
        
        generate_combinations(res, candidates, temp, i + 1, target);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        generate_combinations(res, candidates, temp, 0, target); // i = 0
        return res;
    }
};