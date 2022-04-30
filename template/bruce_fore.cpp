// Gen Subset
int n ;
vector<int> subset;

void search(int k){
    if(k == n + 1){
        // prcess
    } else {
        // include k 
        subset.push(k);
        search(k+1);
        subset.pop_back(k);
        // not include k
        search(k+1);
    }
}

// gen subset
int n;
vector<int> subset;
void subset(int k){
    if(k == n + 1){
        // process
    } else{
        // include k
        subset.push_back(k);
        search(k+1);
        subset.pop_back(k);

        search(k+1);
    }
}

// Gen Permutation
int n ;
vector<int> permu;
bool chossen[n+1];

void search(){
    if(permu.size() == n){
        // process
    } else{
        for(int i = 1 ; i <=n ;i++){
            chossen[i] = true;
            permu.push_back(i);
            search();

            chossen[i] = false;
            permu.pop_back();
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


int main(){


}