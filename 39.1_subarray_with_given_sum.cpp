class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int start = 0, end = 0, sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            end = i;
            
            while (sum > s && start < end) {
                sum -= arr[start];
                start = start + 1;
            }
            if (sum == s) {
                return {start + 1, end + 1};
            } 
        }
        return {-1};
    }
};
