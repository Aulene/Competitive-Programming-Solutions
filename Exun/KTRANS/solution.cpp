#include<iostream>

using namespace std;

int arr[1000005], nxt[1000005];
int main()
{
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int temp=n;
	for(int i = n-1; i >= 0; i--)
	{
		nxt[i]=temp;
		if(arr[i] != 1) temp = i;
	}
	int l, r, k;
	for(int i = 0; i < q; i++)
	{
		cin >> l >> r >> k;
		int curr=l;
		while(curr<=r && k > 0)
		{
			k/=arr[curr];
			curr=nxt[curr];
		}
		cout << k << "\n";
	}
}
