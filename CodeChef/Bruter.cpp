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
#include<fstream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

int main()
	{	
		ofstream fout ("inp.txt");

		lli t=10, i, j, n, k=1000;

		fout << t << endl;

		while(t--)
			{
				n=rand()%13;

				while(n%k!=0 || k==1)
					k=rand()%(n)+1;

				fout << n << " " << k << endl;

				for(i=0; i<n; i++)
					fout << rand()%50+1 << " ";
				fout << endl;
			}
		return 0;
	}