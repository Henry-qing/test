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

//树状数组
int n;
const int N = 1000010;
int a[N],tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v) //在x上+v;
{
    for(int i = x; i < N; i += lowbit(i)) tr[i] += v;
}

int query(int x) //1 + 2 +....+ x
{
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

// [a,b] = query(b) - query(a - 1);
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) add(i,a[i]);
    return 0;
}