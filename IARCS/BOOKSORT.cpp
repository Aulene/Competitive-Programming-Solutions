#include<iostream>
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
#define pb push_back

int a[200007];

int lis(int n)
{
	int i;

	multiset<int> s;
	multiset<int>::iterator it;

	for(i=0; i<n; i++)
		{
			s.insert(a[i]);

			it=s.upper_bound(a[i]);

			if(it!=s.end())
				s.erase(it);
		}

	return s.size();
}

int main()
	{
		int n, i, cur;

		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		cur=lis(n);
		cout << n-cur << endl;
		
		return 0;
	}