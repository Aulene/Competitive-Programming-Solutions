#include <bits/stdc++.h>

using namespace std;

int maxSubsetSum(vector <int> vs)
{
    int i, j, n = vs.size(), ans = 0;

    int dp[n];

    for(i = 0; i < n; i++) 
    	if(vs[i] < 0) vs[i] = 0;

    for(i = 0; i < n; i++) dp[i] = 0;

    dp[0] = vs[0];
    ans = dp[0];

    if(n > 1) {
        dp[1] = vs[1];
        ans = max(dp[0], dp[1]);
    }
    

    for(i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], vs[i] + dp[i - 2]);
        if(i > 2)
        	dp[i] = max(dp[i], vs[i] + dp[i - 3]);
        
        ans = max(dp[i], ans);
    }

    return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		vector <int> vs;

		cin >> n;

		for(i = 0; i < n; i++) cin >> u, vs.push_back(u);

		cout << maxSubsetSum(vs) << endl;
		return 0;
	}