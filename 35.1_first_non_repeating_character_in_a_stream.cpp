//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A) {
		    string s = "";
		    queue<char> q;
		    map<char, int> cnt;
		    

		    for (int i = 0; i < A.size(); i++) {
		        cnt[A[i]]++;
		        q.push(A[i]);
		        
		        while (!q.empty()) {
		            if (cnt[q.front()] > 1) { // repeating
		                q.pop();
		            } else { // non-repeating
		                // here is the ans
		                s += q.front();
		                break; // ans found, so break
		            }
		        }
		        if (q.empty()) { // if q get empty, then nothing to add in this moment
		            // add #
		            s += '#';
		        }
		    }
		    return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
