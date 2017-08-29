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

int main()
	{
		int t, n, no, ans;
		cin >> t;

		while(t--)
			{
				cin >> n;

				no=0;
				while(n>8)
					{
						n-=8;
						no++;
					}

				if(n==3 || n==2 || n==1)
					ans=n+3;
				else if(n==6 || n==5 || n==4)
					ans=n-3;
				else if(n==7)
					ans=n+1;
				else if(n==8)
					ans=n-1;

				if(ans==3 || ans==6)
					cout << 8*no+ans << "UB" << endl;
				else if(ans==2 || ans==5)
					cout << 8*no+ans << "MB" << endl;
				else if(ans==1 || ans==4)
					cout << 8*no+ans << "LB" << endl;
				else if(ans==7)
					cout << 8*no+ans << "SL" << endl;
				else
					cout << 8*no+ans << "SU" << endl;
			}

		return 0;
	}