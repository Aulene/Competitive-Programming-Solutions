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
#define zp mp(0, 0)
#define N 100007

int a[N], pre[N];
int ans = 0;

void binarySearch(int low, int high, int lidx, int c) {

	int ansHere = 0;

	while(low <= high) {

		int mid = (low + high) / 2;
		int idx = floor((int) (lidx + mid) / 2);

		int sum = pre[mid] - (2 * pre[idx]) + pre[lidx - 1];
		sum += a[idx] * ((2 * idx) + 1 - mid - lidx);

		if(sum <= c) {
			ansHere = mid - lidx + 1;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}

	ans = max(ans, ansHere);
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
		
		int n, lx, b, i, j, u, v;

		cin >> n >> lx >> b;

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) pre[i] = a[i] + pre[i - 1];

		for(i = 1; i <= n; i++) {

			binarySearch(i, n, i, b);
			// for(j = i; j <= n; j++) {
			// 	int idx = floor((int) (i + j) / 2);
			// 	int ansHere = 0;

			// 	int sum = pre[j] - (2 * pre[idx]) + pre[i - 1];
			// 	sum += a[idx] * ((2 * idx) + 1 - j - i);

			// 	if(sum <= b) ansHere = j - i + 1;

			// 	ans = max(ans, ansHere);
			// }
		}

		// for(i = 1; i <= n; i++) {
		// 	for(j = i; j >= 1; j--) {
		// 		binarySearch(i, n, i, j, b);
		// 	}
		// }

		cout << ans << endl;

		return 0;
	}