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
#define f first
#define s second
#define p push
#define pb push_back
#define mp make_pair

pair<int, int> a[200007];
multiset<int> s;
int n;

int lis(int n)
{
	int i;
	multiset<int>::iterator it2;

	for(i=0; i<n; i++)
		{
			s.insert(a[i].second);

			it2=s.upper_bound(a[i].second);

			if(it2!=s.end())
				s.erase(it2);
		}

	return s.size();
}

int main()
	{
		int t, i, ans, prevX, prevY;

		cin >> t;

		while(t--)
			{
				s.clear();
				cin >> n;

				for(i=0; i<n; i++)
					cin >> a[i].first >> a[i].second;
				
				sort(a, a+n);

				ans=lis(n);

				cout << n-ans+1 << endl;
			}

		return 0;
	}