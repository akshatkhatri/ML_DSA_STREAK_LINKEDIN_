class Solution {
  public:
  
    void generate_subset_sums(vector<int> &arr, int i, int sum, int n,vector<int>&ans)
    {
        if(i == n)
        {
            ans.push_back(sum);
            return;
        }
        
        sum+= arr[i];
        generate_subset_sums(arr,i+1,sum,n,ans);
        
        sum -= arr[i];
        generate_subset_sums(arr,i+1,sum,n,ans);
    }
  
    vector<int> subsetSums(vector<int> arr, int n) {
        int i = 0;
        int sum = 0;
        vector<int>ans;
        generate_subset_sums(arr,i,sum,n,ans); // i = 0 and sum = 0
        return ans;
    }
};