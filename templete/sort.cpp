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

//1.快速排序
void quick_sort(int a[], int l, int r)
{
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = a[(l + r) / 2];
    while(i < j)
    {
        do i ++;
        while(a[i] < x);
        do j --;
        while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_sort(a,l,j);
    quick_sort(a,j + 1,r);
}