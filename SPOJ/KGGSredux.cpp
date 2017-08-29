#include <iostream>
using namespace std;

#define in(a) cin>>a
#define NMAX 100005
#define SIZE NMAX*4
#define MIN -1e9
int ARR[NMAX];
int TREE1[SIZE];
int TREE2[SIZE];
int NODES=0;
int L[SIZE];
int R[SIZE];

void construct(int start, int end, int node)    
{
    if(start==end)  {
        TREE1[node]=ARR[start];
        TREE2[node]=MIN;
    }
    else {
        int mid=(start+end)/2;
        L[node]=NODES++;
        R[node]=NODES++;
        
        construct(start, mid, L[node]);
        construct(mid+1, end, R[node]);
        
        if(TREE1[L[node]]>TREE1[R[node]])   {
            TREE1[node]=TREE1[L[node]];
            TREE2[node]=max(TREE1[R[node]],TREE2[L[node]]);
        }
        else {
            TREE1[node]=TREE1[R[node]];
            TREE2[node]=max(TREE2[R[node]],TREE1[L[node]]);
        }
    }
}

void update(int x, int start, int end, int node, int val)    {
    if(start==end)  {
        TREE1[node]=val;
        TREE2[node]=MIN;
    }
    else {
        int mid=(start+end)/2;
        if(x<=mid)  {
            update(x, start, mid, L[node], val);
        }
        else {
            update(x, mid+1, end, R[node], val);
        }
        
        if(TREE1[L[node]]>TREE1[R[node]])   {
            TREE1[node]=TREE1[L[node]];
            TREE2[node]=max(TREE1[R[node]],TREE2[L[node]]);
        }
        else {
            TREE1[node]=TREE1[R[node]];
            TREE2[node]=max(TREE2[R[node]],TREE1[L[node]]);
        }
        
    }
}


pair<int, int> query(int a, int b, int start, int end, int node)    {
    int mid=(start+end)/2;
    if(start>=a && end<=b)  {
        return make_pair(TREE1[node], TREE2[node]);
    }
    else if(b<=mid)   {
        return query(a, b, start, mid, L[node]);
    }
    else if(a>mid)  {
        return query(a, b, mid+1, end, R[node]);
    }
    else {
        pair<int, int> x1=query(a, b, start, mid, L[node]), y1=query(a, b, mid+1, end, R[node]);
        int i,j;
        
        if(x1.first>y1.first)   {
            i=x1.first;
            j=max(x1.second,y1.first);
        }
        else {
            i=y1.first;
            j=max(x1.first,y1.second);
        }
        
        return make_pair(i, j);
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    int N;
    in(N);
    for(int i=0;i<N;i++)
        in(ARR[i]);
    int root=NODES++;
    construct(0, N-1, root);
    
    int Q;
    in(Q);
    char s;
    int a, b;
    pair<int, int> t;

    while(Q--)  {
        cin>>s;
        in(a),in(b);
        if(s=='Q')  {
            a--, b--;
            t=query(a, b, 0, N-1, root);
            cout<<t.first+t.second<<endl;
        }
        else {
            a--;
            update(a, 0, N-1, root, b);
        }
    }
    
    
    return 0;
}
