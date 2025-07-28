#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int>* l;

    public:
        Graph(int V){
           this->V = V;
           l = new list<int> [V]; // dynamic array
        }

        void addEdge(int u, int v){ // undirected u--v
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void print(){
            for(int u = 0; u<V; u++){ // 0 , 1, 2, 3, 4
                list<int> neighbors = l[u];
                cout << u << " : ";
                for(int v: neighbors){
                    cout << v << " ";
                }

                cout << endl;
            }
        }


    void bfs(){ //O(V + E);
        queue<int> q;
        vector<int> vis(V, false);

        q.push(0);
        vis[0] = true;

        while(q.size() > 0){
            int u = q.front();  // curr vertex
            q.pop();
            cout << u << " ";

            list<int> neighbors = l[u];
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);

                }
            }
        }
        cout << endl;
    }

    void dfshelper(int u, vector<bool> &vis){
        vis[u] = true;
        cout << u << " " ;

        list<int> neighbors = l[u];
        for(int v: neighbors){
            if(!vis[v]){
                dfshelper(v, vis);
            }
        }
    }


    void dfs(){
        vector<bool> visited(7, false);
        dfshelper(0, visited);
        cout << endl;

    }

};

vector<int> bfsofgraph(int V, vector<int>& adj[]){

    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }

        }
    }
    return bfs;

}


void dfs(int node, vector<int> adj[], int& vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    vector<int> ls;
    int start = 0;
    int vis[V] = {0};
    dfs(start, adj, vis, ls);
    return ls;
}


// rotten oranges  
 // bfs algo



/*
    create vis matrix
    have row and col

    create the queue<pair<pair<int, int>, int>>

    vector<vector<int>> vis;

    find the 2 elements in the grid and push it to the queue

    then intialize the time or tm = 0;

    run bfs 
    while(!q.empty()){

        r
        c
        t
        q.pop();

        now visit their neighbors which are adjacent to check if they have the 1 or not
        loop it in the size
            int nrow = r + drow[i];
            int ncol = c + dcol[i]
            if(nrow >= 0 && ncol >= 0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] ==1)

                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 1

    }

*/



// bfs questions
int orangesRotting(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int cntfresh = 0;

    queue<pair<pair<int, int> , int> > q;
    int vis[n][m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }else{
                vis[i][j] = 0;
            }
            if(grid[i][j] == 1) cntfresh++;
        }

    }

    int tm = 0;
    int cnt = 0; 
    int drow[] = {1, 0, -1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        tm = max(tm, t);
        q.pop();
        for(int i = 0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && ncol <= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({{nrow, ncol},t+1});
                vis[nrow][ncol] = 1;
                cnt

            }
        }
    }


// find closest 0 for each cell

class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m));
        for(int i=0;i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]== 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;

                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            dis[r][c] = t;
            for(int i = 0; i<4; i++){
                int nrow = drow[i] + r;
                int ncol = dcol[i] + c;

                if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 ){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, t+1});
                }
            }

        }

        return dis;


    }
};


    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         if(vis[i][j] != 2 && grid[i][j] == 1){
    //             return - 1;
    //         }
    //     }
    // }

    if(cnt !=  cntfresh) return -1;
    return tm;
}



//cycle using bfs

// go through notes to find how to detect cycle in unconnected graphs

// tc  O (N + 2E) // sum of adjacent = sumof degree = 2edge 
// sc O (N) + O(N)

bool detect(int src, vector<int> adj[], int &vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto & a: adj[node]){
            if(!vis[a]){
                q.push({a, node});
                vis[a] = 1;
            }
            else if(parent != a){
                return true;
            }
        }
    }

    return false;
}


        // using dfs

bool dfsdetect(int start,int parent, int & vis[], vector<int> adj[]){
    vis[start] = 1;
    
    for(auto it: adj[start]){
        if(vis[it] == 0){
            if(dfs(it,start, vis, adj) == true) return true;
        }
        else if(it != parent){
            return true;
        }
    }

    return false;
}

bool detectcycdfs(int V, vector<int> adj[]){
    int vis[V] = {0};
    
    for(int i= 0; i<V; i++){
        if(vis[i] == 0){
            if(dfsdetect(i,- 1, vis, adj)){
                return true;
            }
        }
    }

    return false;
    
}







int main(){

    Graph graph(5);
    
    graph.addEdge(0, 1);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    // graph.print();
    
    graph.dfs();

    return 0;
}

// graph matrix based storing

// int main(){
//     int n, m ;
//     cin >> n >> m;
//     int adj[n+1][n+1];
//     for(int i = 0; i<m ; i++){
//         int u, v; 
//         cin >> u >> v;
//         adj[u][v] = 1;
//         adj[u][v] =1;
//     }

//     return 0;
// }


// list way of storing

int main(){
    int n , m ;
    cin >> n >> m;
    vector<vector<int>> adj[n+1];
    for(int i = 0; i<m ; i++){
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;

}