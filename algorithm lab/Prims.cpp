
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
vector<vector<int>>graph[N];
vector<int> dist(N),parent(N);
const int INF = 1e9+9;
bool visited[N];
int Prims(int n,int src){
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	dist[src] = 0;
	set<vector<int>> st;
	st.insert({0,src});//wt,vertex
	int cost = 0;
	while(!st.empty()){
		auto x = *st.begin();
		st.erase(x);
		int wt = x[0];
		int u = x[1];
		int v = parent[u];
		visited[u] = true;
		cost += wt;

		for(auto it:graph[u]){
			int v = it[0];
			int w = it[1];
			if(visited[v]==true) continue;
			if(dist[v]>w){
				st.erase({dist[v],v});
				dist[v] = w;
				st.insert({dist[v],v});
				parent[v] = u;
			}
		}
	}
	return cost;
}
int main(){

	int n,m;	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1,v2,wt;	cin >> v1 >> v2 >> wt;
		graph[v1].push_back({v2,wt});
		graph[v2].push_back({v1,wt});
	}
	int cost = Prims(n,0);
	cout << "Total Cost: " << cost << endl;
}

