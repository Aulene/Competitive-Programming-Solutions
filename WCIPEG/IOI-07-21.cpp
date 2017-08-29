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

string s;

int score(int a, int b, int c)
{
	int ans=0;

	if(a==1 && b==1 && c==1)
		ans=3;

	if(a==2 || b==2 || c==2)
		ans=2;

	if(a==3 || b==3 || c==3)
		ans=3;

	return ans;
}

int recur(int index, int a, int b, int c)
{
	if(index>=len)
		return 0;

	int ans1, ans2, ans;
	
}

int main()
	{
		int n, i, j, ans=0;

		cin >> n >> s;

		for(i=0; i<n; i++)
			if(s[i]=='M')
				s[i]=1;
			else if(s[i]=='B')
				s[i]=2;
			else
				s[i]=3;



		cout << ans << endl;
		return 0;
	}