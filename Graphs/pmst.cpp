#include<bits/stdc++.h>
using namespace std;

// prims algo

int spanningtree(int v, vector<vector<int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int,int>>> pq;

    vector<int> vis(V, 0);

    pq.push({0, 0});
    int sum = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if(vis[node] == 1) continue;

        vis[node] == 1;
        sum += wt;
        for(auto it: adj[node]){
            int adj = it[0];
            int edw = it[1];

            if(!vis[adj]){
                pq.push({edw, adj});
            }
        }

    }

    return sum;
}

// Disjoint Set 

class disjointset{
    vector<int> rank, parent, size;
    public:
        disjointset(int n){
            rank.resize(n+1, 0);
            parent.resize(n + 1);
            size.resize(n+1);
            for(int i = 0; i<n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUpar(int node){
            if(node == parent[node])return node;
            return parent[node] = findUpar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_v = findUpar(v);
            int ulp_u = findUpar(u);

            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void unionbysize(int u, int v){
            int ulp_v = findUpar(v);
            int ulp_u = findUpar(u);

            if(ulp_v == ulp_u) return;
            if(size[ulp_u] < size[ulp_v] ){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u]
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }

        }

};


// kruskals algo 

int spanningkruskaltree(int V, vector<vector<int>> adj[]){
    vector<pair<int, pair<int, int>>> edges // wt, from , to

    for(int i = 0; i<V; i++){
        for(auto it: adj[i]){
            int adjnode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjnode}});
        }
    }

    disjointset ds(V); 
    sort(edges.begin(), edges.end());
    int mstint = 0;
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int w = it.second.second;

        if(ds.findUpar(u) != ds.findUpar(v)){
            mstint += wt;
            ds.unionbysize(u, v);
        }
    }

    return mstint;
}


//number of operations to make netwrok connected

int solve(int n , vector<vector<int>> &edge){

    disjointset ds(n);
    int cnt = 0;
    for(auto it: edges){
        int u = it[0];
        int v = it[1];

        if(ds.findUpar(u) == ds.findUpar(v)){
            cnt++;
        }else{
            ds.unionbysize(u, v);
        }
    }

    int cntc = 0;
    for(int i = 0; i<n; i++){
        if(ds.parent[i] == i) cntC++;
    }
    int ans = cntc-1;
    if(cnt > ans) return ans;
    return -1;
}


int main(){
    disjointset ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(1, 2);
    ds.unionByRank(1, 2);
    ds.unionByRank(1, 2);
}


// number of provinces 

class Solution {

public:

    map<pair<int, int>, int> ma;
    int cnt = 0;


    void dfs(pair<int, int> m, map<pair<int, int>, vector<pair<int, int>>> &adj){
        ma[m] = 1;
        for(auto &it: adj[m]){
            if(ma[it] == 0 ){
                dfs(it, adj);
                cnt++;
            }
        }
        
    }


    int removeStones(vector<vector<int>>& stones) {

        map<pair<int, int>, vector<pair<int, int>>> adj;

    for (int i = 0; i < stones.size(); i++) {
    for (int j = i + 1; j < stones.size(); j++) {
        pair<int, int> a = {stones[i][0], stones[i][1]};
        pair<int, int> b = {stones[j][0], stones[j][1]};

        if (a.first == b.first || a.second == b.second) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    }

        for(auto it: adj){
            ma[it.first] = 0;

        }

        for(auto &it: ma){
            if(it.second == 0){
                dfs(it.first, adj);
            }
        }

        return cnt;



        
        
    }
};


// accounts merge

class Solution {
public:
    class disjointset{
        public:
        vector<int> size, parent;

        disjointset(int n ){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++){
                parent[i] = i;
                size[i]  = 1;
            }    
        }

        int findpar(int n){
            if(parent[n] == n) return n;
            return parent[n] = findpar(parent[n]);
        }

        void unionbysize(int u, int v){
            int ulp_u = findpar(u);
            int ulp_v = findpar(v);

            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }


    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // use a set to store all emails
        unordered_map<string, int> ma;
        int n = accounts.size();
        disjointset ds(accounts.size());
        for(int i = 0; i<accounts.size(); i++){
            string name = accounts[i][0];
            
            for(int j= 1 ; j<accounts[i].size(); j++){
                string email = accounts[i][j];

                if(!ma.count(email)){
                    ma[email] = i;
                }else {
                    ds.unionbysize(i, ma[email]);
                }
                }
        
        }

        vector<vector<string>> mergedmails(n);
        for(auto it: ma){
            string mail = it.first;
            int node = ds.findpar(it.second);
            mergedmails[node].push_back(mail);

        }

        vector<vector<string>> ans;
        for(int i = 0 ; i<n; i++){
            string name = accounts[i][0];
            if(mergedmails[i].empty()) continue;
            sort(mergedmails[i].begin(), mergedmails[i].end());
            vector<string> temp;
            temp.push_back(name);
            for(auto it: mergedmails[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }
        
        return ans;
    }
};


