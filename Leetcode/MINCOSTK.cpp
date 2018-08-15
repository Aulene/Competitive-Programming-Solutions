#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

bool cmp(pair <double, int> a, pair <double, int> b)
{
	return a.f > b.f;
}

double check(vector<int> &quality, vector<int> &wage, int K, double c)
{
	priority_queue <double, vector <double>, greater <double> > pq;

	int num = 0; double cost = 0;

	for(int i = 0; i < wage.size(); i++) {
		if(c * quality[i] >= wage[i])
			pq.p(c * quality[i]);
	}

	while(!pq.empty() && num < K) {
		cout << pq.top() << " ";
		num++;
		cost += pq.top();
		pq.pop();
	} 
	cout << endl;

	if(num < K) 
		cost = 0;

	return cost;
}

double bsearch(vector<int> &quality, vector<int> &wage, int K)
{
	int n;
	double low = 1, high = 100000, mid, checker, ans = INT_MAX;

	while(low <= high)
		{
			mid = (low + high) / 2;

			cout << endl;
			checker = check(quality, wage, K, mid);
			cout << low << " " << high << " " << mid << " " << checker << endl;

			if(checker == 0 || checker > ans) low = mid + 0.0000001;
			else {
				ans = min(ans, checker);
				high = mid - 0.0000001;
			}
		}

	return ans;
}

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) 
{
	return bsearch(quality, wage, K);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		vector <int> q, w;

		cin >> n >> m;
		for(i = 0; i < n; i++) cin >> u, q.pb(u);
		for(i = 0; i < n; i++) cin >> u, w.pb(u);
		cout << mincostToHireWorkers(q, w, m) << endl;

		return 0;
	}