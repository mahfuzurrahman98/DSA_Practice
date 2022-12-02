//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    queue<long long> q;
    vector<long long> ans;
    long long i;
    
    for (i = 0; i < K; i++) { // process the first window
        if (A[i] < 0) { // push if it is negative
            q.push(i);
        }
    }
    ans.push_back(q.empty()? 0: A[q.front()]); // push to ans
    
    for (i = K ; i < N ; i++) { // process next 
        if (!q.empty() && q.front() == i - K) { // remove form q if it is from the prev window
            q.pop();
        }
        if (A[i] < 0) { // push if it is negative 
            q.push(i);
        }
        ans.push_back(q.empty()? 0: A[q.front()]); // push to ans
    }
    
    return ans;
}
