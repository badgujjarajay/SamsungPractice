# GRAPH

## GRAPH TRAVERSAL
* DFS
```
vector<int>v;
void dfs(int s,vector<int>&vis,vector<int>adj[]){
    if(vis[s]==1){
        return;
    }
    vis[s]=1;
    v.push_back(s);
    for(auto u:adj[s]){
        dfs(u,vis,adj);
    }
    // vis[s]=2;
}
```
* BFS
```
vector<int>v;
void bfs(int s,vector<int>&vis,vector<int>adj[]){
    deque<int>q;
    q.push_back(s);
    while(!q.empty()){
        int s=q.front();
        q.pop_front();
        v.push_back(s);
        for(auto u:adj[s]){
            if(vis[u]==0){
                q.push_back(u);
                vis[u]=1;
            }
        } 
    }
}
```
## TOPOLOGICAL SORT
* BY USING DFS 
```
vector<int>st;
bool dfs(int s,vector<int>&vis,vector<int>adj[]){
    vis[s]=1;
    for(auto u:adj[s]){
        if(vis[u]==1 || (vis[u]==0 and !dfs(u,vis,adj))){
            // topological sort not possible (Not a DAG)
            return 0;
        }
    }
    vis[s]=2;
    st.push_back(s);
    return 1;
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int n, vector<int> adj[]) 
{
    vector<int>vis(n);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(!dfs(i,vis,adj)){
                return {};
            }
        }
    }
    // for(auto val:st) cout<<val<<" ";
    reverse(st.begin(),st.end());
    return st;
}
```
* BY USING BFS 
```
vector<int> topoSort(int n, vector<int> adj[]) {
    vector<int>indeg(n);
    for(int i=0;i<n;i++){
        for(auto u:adj[i]){
            indeg[u]++;
        }        
    }
    deque<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push_back(i);
        }
    }
    vector<int>top_sort;
    while(!q.empty()){
        int s=q.front();
        q.pop_front();
        top_sort.push_back(s);
        for(auto u:adj[s]){
            indeg[u]--;
            if(indeg[u]==0){
                q.push_back(u);
            }
        }
    }
    if(top_sort.size()<n) return {};
    return top_sort;
}
```
## DETECT CYCLE IN DIRECTED GRAPH
* BY USING DFS
```
// The idea is similar to topological sort.
vector<int>vis;
bool dfs(int s,vector<int> adj[]){
    if(vis[s]==1) return 1;
    if(vis[s]==2) return 0;
    vis[s]=1;
    for(auto u:adj[s]){
        if(dfs(u,adj)){
            return 1;
        }
    }
    vis[s]=2;
    return 0;
}
bool isCyclic(int V, vector<int> adj[]) {
    vis.assign(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,adj)){
                return 1;
            }
        }
    }
    return 0;
}
```
* BY USING BFS
```
bool isCyclic(int n, vector<int> adj[]) {
    vector<int>indeg(n);
    for(int i=0;i<n;i++){
        for(auto u:adj[i]){
            indeg[u]++;
        }        
    }
    deque<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push_back(i);
        }
    }
    vector<int>top_sort;
    while(!q.empty()){
        int s=q.front();
        q.pop_front();
        top_sort.push_back(s);
        for(auto u:adj[s]){
            indeg[u]--;
            if(indeg[u]==0){
                q.push_back(u);
            }
        }
    }
    if(top_sort.size()<n) return 1;
    return 0;
}
```
## DETECT CYCLE IN UNDIRECTED GRAPH
* USING DFS
```
bool dfs(int s,vector<int>adj[],bool vis[],int parent){
    if(vis[s]) return 1;
    vis[s]=1;
    for(auto u:adj[s]){
        if(u!=parent && dfs(u,adj,vis,s)) return 1;
    }
    return 0;
}
bool isCycle(int V, vector<int>adj[])
{
    bool vis[V];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<V;i++){
        if(!vis[i] && dfs(i,adj,vis,-1)) return 1;
    }
    return 0;
}
```
* USING BFS
```
bool isCycle(int n, vector<int> adj[]) {
    vector<int>parent(n,-1),vis(n);
    auto bfs=[&](int s)->bool{
        deque<int>q;
        q.push_back(s);
        while(!q.empty()){
            int s=q.front();
            q.pop_front();
            for(auto u:adj[s]){
                if(vis[u]==0){
                    vis[s]=1;
                    parent[u]=s;
                    q.push_back(u);
                }
                else if(u!=parent[s]){
                    return true;
                }
            } 
        }
        return false;
    };
    for(int i=0;i<n;i++){
        if(vis[i]==0 and bfs(i)){
            return true;
        }
    }
    return false;
}
```
## SINGLE SOURCE SHORTEST PATH (works for both Directed & Undirected graph)
* DIJKSTRA
```
// NOT APPLICABLE WHEN NEGATIVE EDGES
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int>dis(V,INT_MAX);
    vector<bool>vis(V,0);
    dis[S]=0;
    set<pair<int,int>>st;
    st.insert({0,S});
    while(!st.empty()){
        int w,u;
        tie(w,u)=*st.begin();
        st.erase(st.begin());
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:adj[u]){
            if(!vis[v[0]] and v[1]+w<dis[v[0]]){
                st.erase({dis[v[0]],v[0]});
                dis[v[0]]=v[1]+w;
                st.insert({dis[v[0]],v[0]});
            }
        }
    }
    return dis;
}
```
* BELLMAN FORD
```
// CAN DETECT NEGATIVE CYCLE
// Undirected graph with negative edges forms negative cycle, so bellman ford will not work there.
vector<int>bellman_ford(int s,vector<vector<int>> &edges,int n){
    vector<int>dis(n,INT_MAX);
    dis[s]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<edges.size();j++){
            int u=edges[j][0],v=edges[j][1],wt=edges[j][2];
            if(dis[u]!=INT_MAX and dis[v]>dis[u]+wt){
                if(i==n-1){
                    // Graph contains negative cycle
                    return {};
                }
                dis[v]=dis[u]+wt;
            }
        }
    }
    return dis;
}
```
## ALL PAIR SHORTEST PATH
* FLOYD WARSHALL (works for both Directed & Undirected graph)
```
void shortest_distance(vector<vector<int>>&matrix){
    for(int k=0;k<matrix.size();k++){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[k][j]!=-1 and matrix[i][k]!=-1){
                    if(matrix[i][j]==-1) {
                        matrix[i][j]=matrix[i][k]+matrix[k][j];
                    }
                    else {
                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }
    }
}
```
## MINIMUM SPANNING TREE
* PRIM's ALGORTHIM 
```
// only for undirected graph
int spanningTree(int n, vector<vector<int>> adj[]) {
    vector<int>dis(n,INT_MAX),vis(n);
    dis[0]=0;
    set<pair<int,int>>st;
    st.insert({0,0});
    int mst=0,wt,s;
    while(!st.empty()){
        tie(wt,s)=*st.begin();
        st.erase(st.begin());
        mst+=wt;
        vis[s]=1;
        for(auto v:adj[s]){
            if(vis[v[0]]==0 and v[1]<dis[v[0]]){
                st.erase({dis[v[0]],v[0]});
                dis[v[0]]=v[1];
                st.insert({dis[v[0]],v[0]});
            }
        }
    }
    return mst;
}
```
* KRUSKAL's ALGORITHM
```
// only for undirected graph
vector<int>parent;
void dsu(int n){
    parent.assign(n,-1);
}
int findParent(int s){
    if(parent[s]<0){
        return s;
    }
    return parent[s]=findParent(parent[s]);
}
bool connect(int a,int b){
    a=findParent(a);
    b=findParent(b);
    if(a==b) return 0;
    if(parent[a]<parent[b]){
        swap(a,b);
    }
    parent[b]+=parent[a];
    parent[a]=b;
    return 1;
}
int kruskal(vector<vector<int>> &edges,int n){
    dsu(n);
    auto cmp=[](vector<int>&v1,vector<int>&v2)->bool{
        return v1[2]<v2[2];
    };
    sort(edges.begin(),edges.end(),cmp);
    int mst=0;
    for(auto arr:edges){
        if(connect(arr[0],arr[1])){
            mst+=arr[2];
        }
    }
    return mst;
}
```
## CUT EDGES (only for undirected graph)
```
int timer;
vector<int>tin,low,vis;
vector<vector<int>>bridges;
void dfs(int s, int p, vector<int>adj[]) {
    vis[s]=1;
    tin[s]=low[s]=++timer;
    for(auto u:adj[s]){
        if(!vis[u]){
            dfs(u,s,adj);
            low[s]=min(low[s],low[u]);
            if(low[u]>tin[s]){
                bridges.push_back({s,u});
            }
        }
        else if(u!=p){
            low[s]=min(low[s],tin[u]);
        }
    }
}
vector<vector<int>> bridge(int n, vector<int>adj[]) {
    tin.assign(n,0);
    low.assign(n,0);
    vis.assign(n,0);
    timer=0;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,-1,adj);
    }
    return bridges;
}
```
## CUT VERTICES (only for undirected graph)
```
int timer;
vector<int>cut,tin,low,vis;
void dfs(int s, int p, vector<int>adj[]) {
    vis[s]=1;
    tin[s]=low[s]=++timer;
    int children=0;
    for(int u:adj[s]){
        if(!vis[u]){
            children++;
            dfs(u,s,adj);
            low[s]=min(low[s],low[u]);
            if(p!=-1 and low[u]>=tin[s]){
                cut[s]=1;
            }
        }
        else if(u!=p){
            low[s]=min(low[s],tin[u]);
        }
    }
    if(p==-1 and children>1){   
        cut[s]=1;
    }
}
void articulation(int n, vector<int>adj[]){
    tin.assign(n,0);
    low.assign(n,0);
    vis.assign(n,0);
    cut.assign(n,0);
    timer=0;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,-1,adj);
    }
}
```
## STRONGLY CONNECTED COMPONENTS in directed graph
* KOSARAJU's ALGORITHM
```
void dfs(int s,vector<int>&vis,vector<int>adj[], vector<int>transpose[],vector<int>&st){
    if(vis[s]==1){
        return;
    }
    vis[s]=1;
    while(!adj[s].empty()){
        int u=adj[s].back();
        dfs(u,vis,adj,transpose,st);
        transpose[u].push_back(s);
        adj[s].pop_back();
    }
    st.push_back(s);
}
int kosaraju(int n, vector<int> adj[])
{
    vector<int>vis(n,0);
    vector<int>transpose[n];
    vector<int>st;
    for(int i=0;i<n;i++){
        dfs(i,vis,adj,transpose,st);
    }
    vector<vector<int>>components;
    fill(vis.begin(),vis.end(),0);
    while(!st.empty()){
        if(vis[st.back()]==0){
            vector<int>v;
            dfs(st.back(),vis,transpose,adj,v);
            components.push_back(v);
        }
        st.pop_back();
    }
    return components.size();
}
```
* TARJAN's ALGORITHM
```
// https://www.geeksforgeeks.org/tree-back-edge-and-cross-edges-in-dfs-of-graph/
// cross edge only exists in directed graph
int timer,ans;
vector<int>tin,low,vis,st;
void dfs(int s, vector<int>adj[]) {
    vis[s]=1;
    st.push_back(s);
    tin[s]=low[s]=++timer;
    for(int u:adj[s]){
        if(!tin[u]){
            dfs(u, adj);
            low[s]=min(low[s],low[u]);
        }
        else if(vis[u]==1){
            low[s]=min(low[s],tin[u]);
        }
    }
    if(low[s]==tin[s]){
        ans++;
        // cout<<"Component no:"<<ans<<<<"\n";
        while(st.back()!=s){
            // cout<<st.back()<<" ";
            vis[st.back()]=0;
            st.pop_back();
        }
        // cout<<s<<"\n";
        vis[s]=0;
        st.pop_back();
    }
}
int tarjan(int V, vector<int> adj[])
{
    ans=timer=0;
    tin.assign(V,0);
    low.assign(V,0);
    vis.assign(V,0);
    for(int i=0;i<V;i++){
        if(!tin[i]) dfs(i,adj);
    }
    return ans;
}
```
## DETECT ODD LENGTH CYCLE
```
// GRAPH SHOULD NOT BE BIPARTITE
bool dfs(int s,int c,vector<int>&vis,vector<int>adj[]){
    if(vis[s]!=-1){
        return vis[s]!=c?0:1;
    }
    vis[s]=c;
    for(auto u:adj[s]){
        if(!dfs(u,1-c,vis,adj)){
            return 0;
        }
    }
    return 1;
}
bool isBipartite(int n, vector<int>adj[]){
    // Code here
    vector<int>vis(n,-1);
    for(int i=0;i<n;i++){
        if(vis[i]==-1 and !dfs(i,1,vis,adj)){
            return 0;
        }
    }
    return 1;
}
bool isoddlengthCycle(int n, vector<int>adj[]){
    return !isBipartite(n,adj);
}
```
## CHECK IF GRAPH CAN BE COLORED BY AT MOST M-COLORS
```

```
## Euler Path & circuit
For Euler Circuit:
* The graph must be connected
* For Undirected Graph: Each Vertex must have even degree.
* For Directed Graph: Each Vertex must have same indegree and outdegree. 

For Euler Path: 
* The graph must be connected.
* For Undirected graph: Each Only two vertex should have odd degree.
* For Directed graph: Outdegree - Indegree (for source vertex) = Indegree - Outdegee (for destination vertex) = 1 & rest vertex have same indegree and outdegree
```
https://cses.fi/problemset/task/1693/
https://cses.fi/paste/361fdb3d9c4509c0233008/
```
```
https://cses.fi/problemset/task/1691/
https://cses.fi/paste/b6ba8511eba6e30f232cf4/
```
## MAXIMUM FLOW
```
https://cses.fi/problemset/task/1694/
https://cses.fi/paste/0b6af95b46704c652612b6/
```

## Maximum Bipartite Matching
```

```