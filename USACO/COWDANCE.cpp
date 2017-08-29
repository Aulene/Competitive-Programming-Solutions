#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

int a[100007];
int f[100007];
int tmax, n;
queue<int> q;

int check(int k)
{
	int i, x, ans;

	for(i=0; i<n; i++)
		f[i]=a[i];

	sort(f, f+k);

	for(i=0; i<k; i++)
		q.p(f[i]);

	for(i=k; i<n; i++)
		{
			//cout << q.front() << " ";
			x=q.front();
			q.pop();
			q.p(x+a[i]);
		}

	while(!q.empty())
		{
			//cout << q.front() << " ";
			ans=q.front();
			q.pop();
		}
	//cout << endl;
	//cout << ans << endl;

	if(ans<=tmax)
		return 1;
	else
		return 0;
}

int binarySearch()
{
	int low=1, high=n, mid, ans=n;

	while(low<=high)
		{
			mid=(low+high)/2;

			if(check(mid))
				{
					ans=mid;
					high=mid-1;
				}
			else
				{
					low=mid+1;
				}
		}

	return ans;
}

int main()
	{
		ifstream fin ("cowdance.in");
		ofstream fout ("cowdance.out");

		int i;

		cin >> n >> tmax;

		for(i=0; i<n; i++)
			cin >> a[i];

		cout << binarySearch() << endl;
		return 0;
	}