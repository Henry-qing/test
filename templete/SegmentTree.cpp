#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include<stack>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int n;
const int N = 100010;
int w[N];

struct Node
{
    int l,r;
    int sum;
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l,r,w[r]};
    else
    {
        tr[u] = {l,r};
        int mid =  l + r >> 1;
        build(u << 1,l,mid);
        build(u << 1 | 1, mid + 1, r); 
        pushup(u);
    }
}

int query(int u,int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int sum = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) sum += query(u << 1, l, r);
    if(r > mid)  sum += query(u << 1 | 1, l, r);
    return sum;
}

void modify(int u, int x, int v)
{
    if(tr[u].l == tr[u].r) tr[u].sum += v;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1,x,v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main()
{
    return 0;
}