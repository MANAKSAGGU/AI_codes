#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class graph{

    public:
    void prepareadjlist(unordered_map<int,list<int>>&adjlist,vector<pair<int,int>>&edges){
        for(int i=0;i<edges.size();i++){
            int u = edges[i].first;
            int v = edges[i].second;

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }

    void bfs(unordered_map<int,list<int>>&adjlist,unordered_map<int,bool>&visited,vector<int>&ans,int node){
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:adjlist[front]){
                if(!visited[i])
                q.push(i);
                visited[i]=true;
            }
        }
    }



    vector<int>BFS(int vertex,vector<pair<int,int>>&edges){
        unordered_map<int,list<int>>adjlist;
        unordered_map<int,bool>visited;
        for(int i=0;i<vertex;i++)
        {
            visited[i] = false;
        }
        vector<int>ans;
        prepareadjlist(adjlist,edges);
        cout << "enter the starting node: " << endl;
        int snode;
        cin >> snode;
        bfs(adjlist,visited,ans,snode);

        return ans;
    }
    void dfs(unordered_map<int,list<int>>&adjlist,unordered_map<int,bool>&visited,vector<int>&ans,int node){

        ans.push_back(node);
        visited[node]=true;
  
            for(auto i:adjlist[node]){
                if(!visited[i]){
                    visited[i]=true;
                    dfs(adjlist,visited,ans,i);
                }
            }
        }



    vector<int>DFS(int vertex,vector<pair<int,int>>&edges){
        unordered_map<int,list<int>>adjlist;
        unordered_map<int,bool>visited;
        for(int i=0;i<vertex;i++)
        {
            visited[i] = false;
        }
        vector<int>ans;
        prepareadjlist(adjlist,edges);
         cout << "enter the starting node: " << endl;
        int snode;
        cin >> snode;
        
             dfs(adjlist,visited,ans,snode);
            
        
        return ans;
    }
};

int main(){
    vector<pair<int,int>>edges;
    pair<int,int>p1,p2,p3,p4,p5;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 4));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(4, 5));
    edges.push_back(make_pair(5, 6));
    edges.push_back(make_pair(6, 7));
    edges.push_back(make_pair(7, 8));
    edges.push_back(make_pair(8, 9));
    graph g;
    cout << "enter the type of traversal : " << endl;
    string traversal;
    cin >> traversal;
    if(traversal == "BFS"){
        vector<int>a = g.BFS(5,edges);
        for(auto i:a){
        cout << i << "->";
    }
    }
    else if(traversal == "DFS"){
        vector<int>a = g.DFS(5,edges);
        for(auto i:a){
        cout << i << "->";
    }
    }
    cout << "end" ;
    return 0;
}