class Solution{
    
	public:
	int MOD = 1e9+7;
	
	void generate(int arr[], int i, int n, long long int curr_sum, int sum, int &count)
	{
	    if(i == n)
	    {
	        if(curr_sum == sum)
	        {
	            count = (count + 1) % MOD;
	        }
	        return;
	        
	    }
	    
	   // temp.push_back(arr[i]);
	    curr_sum += arr[i];
	    generate(arr,i+1,n,curr_sum,sum,count);
	    
	   // temp.pop_back();
	    curr_sum -= arr[i];
	    generate(arr,i+1,n,curr_sum,sum,count);
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // vector<int>temp;
        int count = 0;
        generate(arr,0,n,0,sum,count);
        
        return count;
        
	}
	  
};