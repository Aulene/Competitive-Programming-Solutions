#include <bits/stdc++.h>

using namespace std;

int n;
int row[107][107];
int memo[107][107];
int recur(int rowRightNow, int k)

{
	if(rowRightNow>=n)
		{
			if(!(memo[rowRightNow][k]))
				memo[rowRightNow][k]=memo[rowRightNow][k];
			return memo[rowRightNow][k];
		}
	else
		{		
			if(!(memo[rowRightNow][k]))
				memo[rowRightNow][k]=row[rowRightNow][k]+max(recur(rowRightNow+1, k), recur(rowRightNow+1, k+1));
			return memo[rowRightNow][k];
		}
}

int main()
{
	ifstream cin ("/Users/Aulene/Desktop/input.txt");
	ofstream cout ("/Users/Aulene/Desktop/output.txt");
	
	int t, i, j;
	n = 100;
	for(i=0; i<n; i++)
		for(j=0; j<=i; j++)
			cin >> row[i][j];
			
	cout << recur(0, 0) << endl;
	
	for(i=0; i<=107; i++)
		for(j=0; j<=107; j++)
			memo[i][j]=0;
	return 0;
}
