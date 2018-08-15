#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[500007];

class Solution {
public:
    int shortestSubarray(vector<int> &A, int K) {
        int n, k = K, u = 0, v = 0, ans = 50007, sum = 0;
        
        n = A.size();

		while(u < n || v < n)
			{
				if(sum < 0) {
					sum -= A[u];
					u++;
				} 

				if(sum < k && v < n) {
					sum += A[v];
					v++;
				}
				else {
					if(sum >= k) 
						ans = min(ans, v - u);

					sum -= A[u];
					u++;
				}

			}

		if(ans == 50007) ans = -1;
		return ans;
    }
};

int shortestSubarray(vector<int> &A, int K) {
        int n, k = K, u = 0, v = 0, ans = 50007, sum = 0;
        
        n = A.size();

		while(u < n || v < n)
			{
				if(sum < 0) {
					sum -= A[u];
					u++;
				} 
				
				if(sum < k && v < n) {
					sum += A[v];
					v++;
				}
				else {
					if(sum >= k) 
						ans = min(ans, v - u);

					sum -= A[u];
					u++;
				}

			}

		if(ans == 50007) ans = -1;
		return ans;
    }

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, k, u = 1, v = 1, ans = INT_MAX, sum = 0;
		vector <int> vs;

		cin >> n >> k;

		for(i = 1; i <= n; i++) cin >> u, vs.pb(u);

		cout << shortestSubarray(vs, k) << endl;
		return 0;
	}