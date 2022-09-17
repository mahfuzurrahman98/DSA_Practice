//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int arr[], int n, int k, long long possibleAns) {
        long long sum = 0;
        int count = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] > possibleAns) { // assumed ans is smaller than single element
                return false; // impossible to considered as ans
            }
            if (sum + arr[i] <= possibleAns) { // increase sum if possible
                sum += arr[i];
            } else {
                count++; // get a new day
                if (count > k) { // if days overflow
                    return false; // impossible to considered as ans
                }
                sum = arr[i]; // new day, new weights
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k) {
        long long b = 1, sum = 0, m, ans = -1, e;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        e = sum;
        // search space is 1 to the sum of elements
        while (b <= e) {
            m = b + (e - b) / 2;
            if (isPossible(arr, n, k, m)) { // possible ans
                ans = m;
                e = m - 1; // discard right part to search more minimum ans
            } else {
                b = m + 1; // discard left part because we need greater mid values
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends