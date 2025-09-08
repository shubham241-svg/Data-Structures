#include<bits/stdc++.h>
using namespace std;


// topological sorting
void dfs(int start, vector<int> &vis,vector<int> adj[], stack<int> st){
    vis[start] = 1;
    for(auto &it : adj[start]){
        if(!vis[start]){
            dfs(it, vis, adj, st);
        }
    }

    st.push(start);
}

vector<int> topsort(int v, vector<int> adj[]){
    vector<int> vis(v);
    stack<int> st;
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

// toposort usnig bfs

vector<int> topoSort(int v, vector<int> adj[]){
    vector<int> indegree(v, 0):
    
    for(int i = 0; i < v; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }   
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        //node is in your topo sort
        //so please remove it from the indegree
        for(auto it: adjs[node]){
            indegree[it]--;
            if(indegree[it] == 0)q.push(it);
        }
    }

    return topo;

}



// find the safest nodes
vector<int> eventualsafe(int V, vector<int> adj[]){
    vector<int> adjrev[v];
    int indegree[v] = {0};
    for(int i = 0; i< V; i++){
        // i -> it
        // it-> i

        for(auto it: adj){
            adjRev[it].push_back(i);
            indegree[i]++;

        }
    }

    queue<int> q;
    vector<int> safeNodes;
    for(int i = 0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}


// dfs  solution for it
bool dfscheck(int node, vector<int> adj[], int vis[], int pathvis[], int check[]) {
    vis[node] = 1;
    pathvis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfscheck(it, adj, vis, pathvis, check) == true)
                return true;
        } else if (pathvis[it]) {
            return true;  // cycle found
        }
    }

    pathvis[node] = 0;
    check[node] = 1; // no cycle from this node → safe
    return false;
}

vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
    int vis[v] = {0};
    int pathvis[v] = {0};
    int check[v] = {0};  // 1 if node is safe

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfscheck(i, adj, vis, pathvis, check);
        }
    }

    vector<int> safenodes;
    for (int i = 0; i < v; i++) {
        if (check[i] == 1)
            safenodes.push_back(i);
    }

    return safenodes;
}


// ALIEN DICTIONARY

vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return topo;
}

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];

    for (int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());

        for (int ptr = 0; ptr < len; ptr++) {
            if (s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for (auto it : topo) {
        ans += (char)(it + 'a');
    }

    return ans;
}



// bridges in graph

int timer = 1; 
void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[]){
    
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it: adj[node]){
        if(it == parent) continue;
        if(vis[it]==0){
            dfs(it, node, adj, tin, low);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                bridges.push_back({it, node});
            }
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
}
vector<vector<int>> criticalConnection(int n , vector<vector<int>> &connection){
    vector<int> adj[n];
    for(auto it: connection){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges);
    return bridges;
}




// Articulation point in a graph



void dfs(int node, int parent, vector<int> adj[],
         vector<int>& disc, vector<int>& low, vector<bool>& visited,
         vector<bool>& artpoint, int& timer) {

    visited[node] = true;
    disc[node] = low[node] = ++timer;
    int childCount = 0;

    for (auto neib : adj[node]) {
        if (neib == parent) continue;

        if (!visited[neib]) {
            childCount++;
            dfs(neib, node, adj, disc, low, visited, artpoint, timer);

            // Update low
            low[node] = min(low[node], low[neib]);

            // Case 1: Non-root node
            if (parent != -1 && low[neib] >= disc[node]) {
                artpoint[node] = true;
            }
        } else {
            // Back edge
            low[node] = min(low[node], disc[neib]);
        }
    }

    // Case 2: Root node special condition
    if (parent == -1 && childCount > 1) {
        artpoint[node] = true;
    }
}

vector<int> articulationPoint(int V, vector<int> adj[]) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> visited(V, false), artpoint(V, false);
    int timer = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, disc, low, visited, artpoint, timer);
        }
    }

    vector<int> ans;
    for (int i = 0; i < V; i++) {
        if (artpoint[i]) ans.push_back(i);
    }

    if (ans.empty()) return {-1};
    return ans;
}


// kosraju algorithm - strongly connected components
void dfs1(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs1(it, adj, vis, st);
    }
    st.push(node); // finishing time
}

void dfs2(int node, vector<int> adjT[], vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adjT[node]) {
        if (!vis[it]) dfs2(it, adjT, vis);
    }
}

int kosaraju(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;

    // Step 1: order by finish time
    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs1(i, adj, vis, st);
    }

    // Step 2: transpose
    vector<int> adjT[V];
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    // Step 3: process stack in transpose
    fill(vis.begin(), vis.end(), 0);
    int scc = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++;
            dfs2(node, adjT, vis);
        }
    }
    return scc;
}