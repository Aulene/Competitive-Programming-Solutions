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
 
void printSubsequences(long long int arr[],long long int n ,long long int K)
{
    unsigned long long int opsize = pow(2, n);
 	long long int sum=1,count=0;
    for (long long int counter = 1; counter < opsize; counter++)
    {
        for (long long int j = 0; j < n; j++)
        {
            if (counter & (1<<j))
                sum*=arr[j];
                if(sum>K)
                {
                	count++;
                	break;
                }
        }
        sum=1;
    }
    cout << pow(2,n)-1-count << endl;
}
int main()
{
	long long int N,K;
	cin >> N >> K;
	long long int A[N];
	
	for(int i=0;i<N;i++)
	cin >> A[i];
    printSubsequences(A, N, K);
    return 0;
} 