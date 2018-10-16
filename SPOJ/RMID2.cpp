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

priority_queue <int, vector <int>, greater <int> > MinHeap;
priority_queue <int, vector <int>, less <int> > MaxHeap;

void insert(int n) {
	if(n >= MinHeap.top() || MinHeap.empty()) MinHeap.push(n);
	else MaxHeap.push(n);

	if(MinHeap.size() - MaxHeap.size() == 2) {
		MaxHeap.push(MinHeap.top());
		MinHeap.pop();
	}
	else if(MaxHeap.size() - MinHeap.size() == 2) {
		MinHeap.push(MaxHeap.top());
		MaxHeap.pop();
	}
}


int median() {
	int ans;

	if(MinHeap.size() == MaxHeap.size()) {
		ans = MaxHeap.top();
		MaxHeap.pop();
	}
	else if(MinHeap.size() >= MaxHeap.size()) {
		ans = MinHeap.top();
		MinHeap.pop();
	}
	else ans = MaxHeap.top(), MaxHeap.pop();

	if(MinHeap.size() - MaxHeap.size() == 2) MaxHeap.push(MinHeap.top()), MinHeap.pop();
	else if(MaxHeap.size() - MinHeap.size() == 2) MinHeap.push(MaxHeap.top()), MaxHeap.pop();

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

			while(!MinHeap.empty()) MinHeap.pop();
			while(!MaxHeap.empty()) MaxHeap.pop();
			MinHeap.push(INT_MAX); 
			MaxHeap.push(-1);

			while(true) {
				cin >> n;

				if(n == 0) break;
				if(n == -1) cout << median() << endl;
				else insert(n);
			}
		}
		return 0;
	}