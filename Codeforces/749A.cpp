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

int main()
	{
		int n, no, ans=0, i;
		cin >> n;

		if(n%2==0)
			{
				ans=n/2;
				cout << ans << endl;
				for(i=0; i<ans; i++)
					cout << "2" << " ";
				cout << endl;
			}
		else
			{
				ans=n/2;
				cout << ans << endl;

				for(i=0; i<ans-1; i++)
					cout << "2" << " ";
				cout << "3" << endl;
			}


		return 0;
	}