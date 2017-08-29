#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
float *multiply( float A[],  float B[], int m, int n)
{
   float *prod = new  float[m+n-1];
 
   // Initialize the porduct polynomial
   for (int i = 0; i<m+n-1; i++)
     prod[i] = 0;
 //for (int i = 0; i<m; i++)
   //  cout<<A[i]<<endl;
 
   // Multiply two polynomials term by term
 
   // Take ever term of first polynomial
   for (int i=0; i<m; i++)
   {
     // Multiply the current term of first polynomial
     // with every term of second polynomial.
     for (int j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }
 
   return prod;
}


int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    int c=pow(2,n);
    float arr[c][2];int b[n];
    for(int i=0;i<c;i++)
    arr[i][1]=1;
    for(int i=0;i<n;i++)
       {cin>>b[i];}

if(n==1)
{arr[0][0]=sqrt(b[0]);
arr[1][0]=-sqrt(b[0]);
}
else if(n==2)
{arr[0][0]=sqrt(b[0])+sqrt(b[1]);
arr[1][0]=sqrt(b[0])-sqrt(b[1]);
arr[2][0]=-sqrt(b[0])+sqrt(b[1]);
arr[3][0]=-sqrt(b[0])-sqrt(b[1]);
}
else if(n==3)
{arr[0][0]=sqrt(b[0])+sqrt(b[1])+sqrt(b[2]);
arr[1][0]=sqrt(b[0])-sqrt(b[1])+sqrt(b[2]);
	arr[2][0]=sqrt(b[0])+sqrt(b[1])-sqrt(b[2]);
	arr[3][0]=sqrt(b[0])-sqrt(b[1])-sqrt(b[2]);
	arr[4][0]=-sqrt(b[0])+sqrt(b[1])+sqrt(b[2]);
	arr[5][0]=-sqrt(b[0])-sqrt(b[1])+sqrt(b[2]);
	arr[6][0]=-sqrt(b[0])+sqrt(b[1])-sqrt(b[2]);
	arr[7][0]=-sqrt(b[0])-sqrt(b[1])-sqrt(b[2]);
		}
 float *prod = multiply(arr[0],arr[1],2, 2);
int k=0;
for(int i=2;i<c;i++)
{
	 prod = multiply(prod,arr[i], 3+k, 2);
k++;
}

cout<<c<<endl;
for(int i=0;i<=c;i++)
{ if (abs(prod[i]-int(prod[i]))>0.5 && prod[i]>0)
prod[i]=int(prod[i])+1;
else if(abs(prod[i]-int(prod[i]))>0.5 && prod[i]<0)
prod[i]=int(prod[i])-1;
else
prod[i]=(int)prod[i];
}
for(int i=0;i<=c;i++)
{
if(prod[i]>=0)	
{int k=((int)prod[i])%((int)(pow(10,9)+7));
	cout<<k<<" ";}
	else
	cout<<(int)((pow(10,9)+7)+prod[i])<<" ";
}
cout<<endl;
}
return 0;	
}

