#include<iostream>
#include<algorithm>
using namespace std;

long long cc=0;
long long* a;
void find(long long n,long long k,long long p,int f)
{
  cc++;
  for(int i=f;i<n;i++)
  {
    if(p*a[i] < k)
      find(n,k,p*a[i],f+1);
    else
      break;
  }
}

int main()
{
  long long n,k;
  cin>>n>>k;
  a = new long long[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  long long p = 1;
  find(n,k,p,0);
  cout<<cc-1;
}