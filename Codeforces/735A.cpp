#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int k, n;
int ans=-1;
string s;
bool visited[107];

int recur(int pos)
{
	if(pos<0 || pos>=n)
		return 0;

	if(visited[pos])
		return 0;

	visited[pos]=1;
	
	if(s[pos]=='#')
		return 0;

	if(s[pos]=='T')
		{
			ans=pos;
			return 0;
		}

	recur(pos+k);
	recur(pos-k);
	return 0;
}

int main()
{
	int i;
	int pos;

	cin >> n >> k >> s;

	for(i=0; i<n; i++)
		if(s[i]=='G')
			pos=i;

	recur(pos);

	if(ans!=-1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}