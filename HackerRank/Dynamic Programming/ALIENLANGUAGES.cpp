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
#define pb push_back

lli n, m;

lli recur(int index, int nextLetter)
{
	if(index*2>n)
		return (n-index-1)*m;
	
	if(index>n)
		return 1;
	
	if(nextLetter>m)
		return 0;

	lli ans=recur(index+1, nextLetter+1);
	return ans;
}

int main()
	{
		int t, i;
		lli ans;

		cin >> t;

		while(t--)
			{
				cin >> n >> m;

				ans=recur(1, 1);
				cout << ans << endl;
			}

		return 0;
	}