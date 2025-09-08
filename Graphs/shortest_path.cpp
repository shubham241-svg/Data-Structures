#include <bits/stdc++.h>
using namespace std;

// find the shortest path in the unidirected graph having unit distance


vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src){
    vector<int> adj[N];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int dist[N];
    for(int i = 0; i<N; i++) dist[i] = 1e9;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }

    }

    vector<int> ans(N, -1);
    for(int i = 0; i<N; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    }

    return ans;

}



// shortest path in direct acyclic graph

// s- Src 
// n -  nodes
// m - edges

// do toposort

// create the function and do normal bfs by creating adjacency list 
// then perform topo on that store the order in the stact
// now do the bfs on that stack



// djikstra algo using min queue

vector<int> djikstra(int V, vector<vector<int>> adj[], int s){

    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int>> pq;
    vector<int> dist(V, 1e9);

    dist[S] = 0;
    pq.push({0, S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjnode = it[1];
            int edgeweight = it[0];

            if(dis + edgeweight < dist[adjnode]){
                dist[adjnode] =adjnode + edgeweight;
                pq.push(dist[adjnode], adjnode);
            }
        }
    }

    return dist;
}


// djikstra algo using set 

vector<int> dj(int V, vector<vector<int>> adj[], int s){

    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);

    st.insert({0, s});
    dist[s] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;

        st.erase(it);

        for(auto it: adj[node]){
            int adjnode = it[0];
            int edgw = it[1];

            if(dis + edgw < dist[adjnode]){
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjnode], adjnode});
                }

                dist[adjnode] = dis + edgw;
                st.insert({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}



// shortest path using djikstra in binary maze

#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size();
    int m = grid[0].size();

    // Distance array initialized with INF
    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    distance[source.first][source.second] = 0;

    // Queue for BFS: {row, col}
    queue<pair<int, int>> q;
    q.push({source.first, source.second});

    // 8-direction movement
    int drow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dcol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            // Check bounds & walkable cell
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                if (distance[row][col] + 1 < distance[nrow][ncol]) {
                    distance[nrow][ncol] = distance[row][col] + 1;

                    if (nrow == destination.first && ncol == destination.second) {
                        return distance[nrow][ncol];
                    }

                    q.push({nrow, ncol});
                }
            }
        }
    }

    return -1; // No path found
}

// cheapest flights 

int cheapestflight(int n , vector<vector<int>> &flights, int src, int dst, int k){
    vector<pair<int, int>> adj[n];
    for(auto it: flights){
        adj[it[0]].push({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;


        if(stops > k) continue;
        for(auto iter : adj[node]){
            int adjnode = iter.first;
            int edn = iter.second;

            if(cost + edw < dist[adjnode] && stops <= k){
                dist[adjnode] = cost + edn;
                q.push({stops + 1 , {adjNode, cost + edw}})
            }
        }
    }

    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}


// bellman fords

vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s){
    vector<int> dist(v, 1e9);
    dist[s] = 0;
    for(int i = 0; i<V - 1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    // -ve relaxation
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
}
