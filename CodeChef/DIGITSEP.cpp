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

int t, n;
lli num;
int sepmin, sepmax, mdig;
int ans=0;

int recur(int num, int sepUsed)
{	
	int i, ans;

	if(sepUsed==sepmax)
		return num;

	if(sepUsed>=sepmin)
		ans=num;

	if(sepUsed<sepmin)
		ans=0;

	for(i=1; i<=sepmax-sepUsed; i++)
		{
			int x=pow(10, i);
			ans=max(ans, __gcd(recur(num-num%x, sepUsed+i), num%x));
		}
	return ans;
}

int main()
	{
		int i;

		cin >> t;

		while(t--)
			{
				cin >> n >> num;
				cin >> mdig >> sepmin >> sepmax;

				ans=0;
				if(num)
					ans=max(1, recur(num, 0));

				cout << ans << endl;
			}

		return 0;
	}