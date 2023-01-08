#include <bits/stdc++.h>
using namespace std;
 
void depth_search(unordered_map<int, vector<int> >& adj, int node, vector<bool>& visited)
{
    if (visited[node])
        return;
 
    visited[node] = true;

    for (auto x : adj[node]) {       
        if (visited[x] == false)
            depth_search(adj, x, visited);
    }
}
 

int makeConnectedUtil(int N, int connections[][2], int M)
{
    vector<bool> visited(N, false);
    unordered_map<int, vector<int> > adj;
    int edges = 0;

    for (int i = 0; i < M; ++i) {
        adj[connections[i][0]].push_back(
            connections[i][1]);
        adj[connections[i][1]].push_back(
            connections[i][0]);
        edges += 1;
    }
    int components = 0;
 
    for (int i = 0; i < N; ++i) {
        if (visited[i] == false) {
            components += 1;
            depth_search(adj, i, visited);
        }
    }
 
    
    if (edges < N - 1)
        return -1;

    int redundant = edges - ((N - 1) - (components - 1));
 
    if (redundant >= (components - 1))
        return components - 1;
 
    return -1;
}
 

void Connect(int N, int connections[][2], int M)
{
    int minOps = makeConnectedUtil(
        N, connections, M);
    cout << minOps;
}
 
int main()
{
    int N = 5;
    int connections[][2] = {
        { 0, 1 }, { 0, 2 }, { 3, 4 }, {2,3}
    };
    int M = sizeof(connections) / sizeof(connections[0]);
    Connect(N, connections, M);
    return 0;
}
