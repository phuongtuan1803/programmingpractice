
// permutation
int n,k;
vector<int> permutation;
bool chosen[1000];
int arr[1000];

void search(){
    if(permutation.size() == k){
        // process
    } else{
        for(int i = 0 ; i < n ; i++){
            if( exception_condition ) continue;
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(arr[i]);
            search();
            chosen[i] = false;            
            permutation.pop_back();            
        }
    }
}

// DFS
vector<int> adj[N];
bool visited[N];

void dfs(int s){
    if(visited[s]) return;
    visited[s] = true;
    // process node s
    for(auto u : adj[s]){
        dfs(u)
    }
}


// BFS
vector<int> adj;
queue<int> q;
bool visited[N];
int distance[N];
int x = 0; // start node

void bfs(){
    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    while(!q.empty()){
        int s = q.front();
        q.pop();

        // process node s

        for(auto u : adj[s]){
            if(visited[s]) continue;
            visited[s] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
        }
    }
}
