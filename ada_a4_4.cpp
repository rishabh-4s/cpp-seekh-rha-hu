#include <bits/stdc++.h>
using namespace std;
 
vector<int> parent;
vector<int> siz;
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v]= find_set(parent[v]);
}
 
int union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
 
        parent[b] = a;
        siz[a] += siz[b];
        return 1;
    }
    return 0;
}
 
void mst(int houses[][2], int n)
{
    vector<pair<int, pair<int, int> > > v;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = abs(houses[i][0]- houses[j][0]);
            p += abs(houses[i][1]- houses[j][1]);
            v.push_back({ p, { i, j } });
        }
    }
    parent.resize(n);
    siz.resize(n);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        parent[i] = i, siz[i] = 1;
    }
    int ans = 0;
    for (auto x : v) {
        if (union_sets(x.second.first, x.second.second)) {
            ans += x.first;
        }
    }
    cout << ans;
}
 
int main()
{
    int houses[][2] = { { 0, 0 }, { 2, 2 }, { 3, 10 }, { 5, 2 }, { 7, 0 }};
    int N = sizeof(houses)/ sizeof(houses[0]);
    mst(houses, N);
 
    return 0;
}
