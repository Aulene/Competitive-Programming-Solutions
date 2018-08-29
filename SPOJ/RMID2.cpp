#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

priority_queue <int, vector <int>, greater <int> > pq; // minheap
priority_queue <int, vector <int>, less <int> > pq2; // maxheap

void insert(int n)
{
	if(n >= pq.top() || pq.empty())
		pq.p(n);
	else pq2.p(n);

	if(pq.size() - pq2.size() == 2) {
		pq2.p(pq.top());
		pq.pop();
	}
	else if(pq2.size() - pq.size() == 2){
		pq.p(pq2.top());
		pq2.pop();
	}
}


int median()
{
	int ans;

	if(pq.size() == pq2.size()) {
		ans = pq2.top();
		pq2.pop();
	}
	else if(pq.size() >= pq2.size()) {
		ans = pq.top();
		pq.pop();
	}
	else
		ans = pq2.top(), pq2.pop();

	if(pq.size() - pq2.size() == 2) pq2.p(pq.top()), pq.pop();
	else if(pq2.size() - pq.size() == 2) pq.p(pq2.top()), pq2.pop();

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t, n, i, j, u, v;

		cin >> t;

		while(t--) {

			while(!pq.empty()) pq.pop();
			while(!pq2.empty()) pq2.pop();
			pq.p(INT_MAX); 
			pq2.p(-1);

			while(true) {
				cin >> n;

				if(n == 0) break;
				if(n == -1) cout << median() << endl;
				else insert(n);
			}
		}
		return 0;
	}