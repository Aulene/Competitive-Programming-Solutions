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
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 100007;

int cnt[3], pidx[3];
vi mv;

int check(string s, int n, int midval) {

	if(n < midval) return 0;

	for(int i = 0; i < 2; i++) cnt[i] = midval / 2;

	int i = 0, j = 0;

	while(i < n) {

		int val = ((int) s[i] - '0');

		// printf("OPEN %lld, Val = %lld\n", i, val);
		// printf("START Cnt0 = %lld, Cnt1 = %lld\n", cnt[0], cnt[1]);
		// printf("START j = %lld\n", j);

		if(cnt[val]) cnt[val]--;
		else {

			while(!cnt[val] && j < n) {
				int jval = ((int) s[j] - '0');
				cnt[jval]++;
				j++;
			}

			cnt[val]--;
		}

		// printf("End j = %lld\n", j);
		// printf("END Cnt0 = %lld, Cnt1 = %lld\n", cnt[0], cnt[1]);
		// printf("CLOSE %lld\n\n", i);

		if(cnt[0] == 0 && cnt[1] == 0) return 1;
		i++;
	}

	return 0;
}

int bs(string s, int n) {
	int low = 0, high = mv.size() - 1, ans = 0, mid, midval;

	while(low <= high) {
		
		mid = (low + high) / 2;
		midval = mv[mid];

		// printf("Checking with val %lld, got result %lld\n", midval, check(s, n, midval));

		if(check(s, n, midval)) {
			ans = midval;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v;
		string s;

		cin >> n >> s;

		for(i = 2; i < N; i += 2) mv.pb(i);
		cout << bs(s, n) << endl;
	
		return 0;
	}