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

int main()
	{
		int t, n, i, j, ans;
		string d1[5], d2[5];

		cin >> t;

		while(t--)
			{
				ans=0;

				for(i=0; i<4; i++)
					cin >> d1[i];

				for(i=0; i<4; i++)
					cin >> d2[i];

				for(i=0; i<4; i++)
					for(j=0; j<4; j++)
						if(d1[i] == d2[j])
							ans++;

				if(ans>=2)
					cout << "similar\n";
				else
					cout << "dissimilar\n";
			}

		return 0;
	}