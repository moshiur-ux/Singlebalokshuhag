#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>Graph[N];
bool vis[N];
void BFS(int src)
{
    queue<int>Q;
    Q.push(src);
    while(!Q.empty())
    {
    int data=Q.front();
        Q.pop();
    vis[data]=true;

    cout<<data<<" ";
    for(auto child:Graph[data])
    {
        if(vis[child]==false)
        {
            Q.push(child);
        }
    }

  }

}
int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    for(int i=0;i<edges;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        Graph[v1].push_back(v2);
        Graph[v2].push_back(v1);
    }

    BFS(1);
}
